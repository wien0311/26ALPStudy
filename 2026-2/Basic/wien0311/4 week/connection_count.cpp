#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int tc, n, m, k_num, num; //y(m)이 열 x(n)이 행
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>tc;
    for(int i=0; i<tc; i++) {//test case 횟수만큼 반복
        num = 0;
        for(int i=0; i<502; i++) {
            for(int j=0; j<502; j++) {
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }

        cin>>n>>m>>k_num;

        for(int i=0; i<k_num; i++) {
            int k1, k2;
            cin>>k1>>k2;
            board[k1][k2] = 1;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 0 || vis[i][j]) continue;
                queue<pair<int,int>> q;
                vis[i][j] = 1;
                q.push({i, j});
                while (!q.empty()){
                    pair<int,int> cur = q.front(); q.pop();
                    for(int dir = 0; dir<4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                num+=1;
            }

        }
        cout<<num<<"\n";
    }
}