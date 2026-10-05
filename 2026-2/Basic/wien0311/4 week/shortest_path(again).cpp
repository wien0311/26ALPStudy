// #include <bits/stdc++.h>
// using namespace std;
// #define X first
// #define Y second

// int n, m, ans, count1, path;
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>n>>m;
//     int board[n][m];
//     bool vis[n][m];

//     for(int i=0; i<n; i++)
//         for(int j=0; j<m; j++)
//             cin>>board[i][j];
        
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<m; j++) {
//             if((vis[i][j] || board[i][j] == 0) && count1 == 1) continue;
//             queue<pair<int, int>> q;
//             q.push({0,0});

//             while (!q.empty()) {
//                 pair<int, int> cur = q.front(); q.pop();
//                 for(int dir=0; dir<4; dir++) {
//                     int nx = cur.X + dx[dir];
//                     int ny = cur.Y + dy[dir];
//                     if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//                     if(board[i][j] != 0) continue;
//                     q.push({nx, ny});
//                     path += 1;
//                 }
//             }
//         }
//     }
// } 초기안 짜면서도 뭔가 많이 잘못됌

// #include <bits/stdc++.h>
// using namespace std;
// #define X first
// #define Y second
// string board[102];
// int dist[102][102];
// int n, m;
// int dx[4]={0, 1, 0, -1};
// int dy[4]={1, 0, -1, 0};

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>n>>m;
//     for(int i=0; i<n; i++)
//         cin>>board[i];
//     for(int i=0; i<n; i++) fill(dist[i], dist[i]+m, -1);
//     queue<pair<int, int>> q;
//     q.push({0,0});
//     dist[0][0] = 0;

//     while(!q.empty()) {
//         auto cur = q.front(); q.pop();
//         for(int dir = 0; dir < 4; dir++) {
//             int nx = cur.X + dx[dir];
//             int ny = cur.Y + dy[dir];
//             if(nx < 0 || nx >=n || ny < 0 || ny >=m) continue;
//             if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
//             dist[nx][ny] = dist[cur.X][cur.Y] + 1;
//             q.push({nx,ny});
//         }
//     }
//     cout << dist[n-1][m-1] + 1;
// } 두 번쨰로 강의 내용보고 수정해보려 했는데 실패

#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist[1002][1002][2];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j][0] = dist[i][j][1] = -1;

    queue<array<int,3>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!q.empty()) {
        auto [x, y, w] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (board[nx][ny] == '0') {            // 빈 칸
                if (dist[nx][ny][w] >= 0) continue;
                dist[nx][ny][w] = dist[x][y][w] + 1;
                q.push({nx, ny, w});
            } else {                               // 벽
                if (w == 1) continue;
                if (dist[nx][ny][1] >= 0) continue;
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    int a = dist[n-1][m-1][0], b = dist[n-1][m-1][1];
    if (a == -1 && b == -1) cout << -1;
    else if (a == -1) cout << b + 1;
    else if (b == -1) cout << a + 1;
    else cout << min(a, b) + 1;
}
//구현을 못하겠어서 ai랑 열띤 토론을 함 나중에 다시 봐야 함