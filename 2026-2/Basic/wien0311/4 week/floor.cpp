// #include <bits/stdc++.h>
// using namespace std;

// int f/*총 층*/, s/*현재 층*/, g/*원하는 층*/, u/*u층 만큼 위로*/, d/*d층 만큼 아래로*/;
// int k, sum;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>f>>s>>g>>u>>d;
//     int floor[f];
//     int vis[f];
//     for(int i=0; i<f; i++) {
//         floor[i]=0;
//         vis[i]=0;
//     }


// } 아이디어는 맞았으나 구현에서 막힘

#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int dist[1000001];   // -1이면 아직 방문 안 함, 아니면 버튼 누른 횟수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;

    fill(dist, dist + f + 1, -1);

    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == g) break;

        int nxt[2] = {cur + u, cur - d};
        for (int n : nxt) {
            if (n < 1 || n > f) continue;   // 건물 범위 밖
            if (dist[n] != -1) continue;    // 이미 방문
            dist[n] = dist[cur] + 1; // 전에 방문거리 +1
            q.push(n);
        }
    }

    if (dist[g] == -1) cout << "use the stairs";
    else cout << dist[g];
}
