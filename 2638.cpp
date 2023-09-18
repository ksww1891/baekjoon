#include<iostream>
#include<queue>

using namespace std;

int n, m, cheeze = 0;
int board[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>>q;

void bfs(){
    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        board[nowY][nowX] = 2;
        for(int i = 0; i < 4; i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextX < 0 || nextY < 0 || nextX >= m || nextY >= n)continue;
            if(board[nextY][nextX] == 0){
                board[nextY][nextX] = 2;
                q.push({nextY, nextX});
            }
        }
    }
    return;
}
//2:공기 1:치즈 0:진공
int meltingHour(){
    int answer = 0;
    //공기 표시
    board[0][0] = 2;
    q.push({0, 0});
    bfs();
    while(cheeze != 0){
        answer++;
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if(board[i][j] == 1){
                    int cnt = 0;
                    for(int k = 0; k < 4; k++){
                        if(board[i + dy[k]][j + dx[k]] == 2){
                            cnt++;
                        }
                    }
                    if(cnt > 1){
                        cheeze--;
                        q.push({i, j});
                    }
                }
            }
        }
        //공기 표시
        bfs();
    }
    return answer;
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1)cheeze++;
        }
    }
    cout << meltingHour();
}