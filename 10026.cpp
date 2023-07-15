#include<iostream>
#include<string>
#include<queue>

using namespace std;

bool visited[101][101] = {0,};
char originalMap[101][101] = {0, };
char colorWeeknesMap[101][101] = {0, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer[2] = {0, };
int n;
queue<pair<int, int>>q;


void bfs1(int y, int x, char target);
void bfs2(int y, int x, char target);
int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    string tmp;

    //입력
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        for(int j = 1; j <= n; j++){
            originalMap[i][j] = tmp[j-1];
            if(tmp[j-1] == 'G')
                colorWeeknesMap[i][j] = 'R';
            else colorWeeknesMap[i][j] = tmp[j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
        if(visited[i][j] == 0){
            bfs1(i, j, originalMap[i][j]);
            answer[0]++;
        }
    }
    //방문 초기화
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= n; j++)
            visited[i][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
        if(visited[i][j] == 0){
            bfs2(i, j, colorWeeknesMap[i][j]);
            answer[1]++;
        }
    }
    cout << answer[0] << ' ' << answer[1];
}

void bfs1(int y, int x, char target){
    visited[y][x] = 1;
    q.push(make_pair(y, x));
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            int X = q.front().second + dx[i];
            int Y = q.front().first + dy[i];
            if(X >= 1&& X<=n && Y >=1 && Y<=n){
                if(visited[Y][X] == 0 && target == originalMap[Y][X]){
                    visited[Y][X] = 1;
                    q.push(make_pair(Y, X)); 
                }
            }
        }
        q.pop();
    }
}

void bfs2(int y, int x, char target){
    visited[y][x] = 1;
    q.push(make_pair(y, x));
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            int X = q.front().second + dx[i];
            int Y = q.front().first + dy[i];
            if(X >= 1&& X<=n && Y >=1 && Y<=n){
                if(visited[Y][X] == 0 && target == colorWeeknesMap[Y][X]){
                    visited[Y][X] = 1;
                    q.push(make_pair(Y, X)); 
                }
            }
        }
        q.pop();
    }
}
