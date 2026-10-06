#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, num/*갯수*/, count1;
deque<int> area;
string board[30];
int vis[30][30];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>board[i];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == '0' || vis[i][j]) continue; 
            num+=1;
            queue<pair<int, int>> q;
            vis[i][j] = 1;
            q.push({i,j});
            count1 = 0;

            while(!q.empty()) {
                count1+=1;
                pair<int, int> cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || board[nx][ny] == '0') continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            area.push_back(count1);
        }
    }
    sort(area.begin(), area.end());
    cout<<num<<"\n";
    for(int i : area) cout<<i<<"\n";
}/*board[30][30]으로 놓고 이중 for문으로 cin을 board[i][j]에 넣으면
입력이 공백없이 010100<<이렇게 입력되기 때문에 board[0][0]에 010100이 들어가
거의 모든 다른 칸이 0으로 들어가 오류가 생김*/