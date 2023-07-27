#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
char map[601][601] = {0, };
bool visited[601][601] = {0, };
int bfs();
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>>q;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin >> map[i][j];
    }
    int answer = bfs();
    if(answer == 0)
        cout << "TT";
    else cout << answer;
}

int bfs(){
    int ret = 0;
    //도연이 찾기
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] == 'I'){
                visited[i][j] = 1;
                q.push(make_pair(i, j));
                break;
            }
        }
    }
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            int x = q.front().second + dx[i];
            int y = q.front().first + dy[i];
            if(x >= 1 && x <= m && y >= 1 && y <= n)
                if(map[y][x] == 'O'&& visited[y][x] == 0){
                    visited[y][x] = 1;
                    q.push(make_pair(y, x));
                }
                else if(map[y][x] == 'P' && visited[y][x] == 0){
                    ret++;
                    visited[y][x] = 1;
                    q.push(make_pair(y, x));
                }
        }
        q.pop();
    }
    return ret;
}