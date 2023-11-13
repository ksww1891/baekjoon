#include<iostream>
#include<queue>
using namespace std;

int board[21][21];
int n, answer;

bool goUp(){
    int tmp[21][21];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            tmp[i][j] = board[i][j];
        }
    }
    queue<int>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(board[j][i] != 0){
                q.push(board[j][i]);
                board[j][i] = 0;
            }
        }
        int idx = 0;
        int last = 0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(now == last && last != 0){
                board[idx][i] = now*2;
                last = 0;
            }
            else if(last != now){
                idx++;
                last = now;
                board[idx][i] = now;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(tmp[i][j] != board[i][j]){
                return true;
            }
        }
    }
    return false;
}
bool goDown(){
    int tmp[21][21];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            tmp[i][j] = board[i][j];
        }
    }
    queue<int>q;
    for(int i = 1; i <= n; i++){
        for(int j = n; j >= 1; j--){
            if(board[j][i] != 0){
                q.push(board[j][i]);
                board[j][i] = 0;
            }
        }
        int idx = n+1;
        int last = 0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(now == last && last != 0){
                board[idx][i] = now*2;
                last = 0;
            }
            else if(last != now){
                idx--;
                last = now;
                board[idx][i] = now;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(tmp[i][j] != board[i][j]){
                return true;
            }
        }
    }
    return false;
}
bool goRight(){
    int tmp[21][21];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            tmp[i][j] = board[i][j];
        }
    }
    queue<int>q;
    for(int i = 1; i <= n; i++){
        for(int j = n; j >= 1; j--){
            if(board[i][j] != 0){
                q.push(board[i][j]);
                board[i][j] = 0;
            }
        }
        int idx = n+1;
        int last = 0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(now == last && last != 0){
                board[i][idx] = now*2;
                last = 0;
            }
            else if(last != now){
                idx--;
                last = now;
                board[i][idx] = now;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(tmp[i][j] != board[i][j]){
                return true;
            }
        }
    }
    return false;
}
bool goleft(){
    int tmp[21][21];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            tmp[i][j] = board[i][j];
        }
    }
    queue<int>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(board[i][j] != 0){
                q.push(board[i][j]);
                board[i][j] = 0;
            }   
        }
        int idx = 0;
        int last = 0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(now == last && last != 0){
                board[i][idx] = now*2;
                last = 0;
            }
            else if(last != now){
                idx++;
                last = now;
                board[i][idx] = now;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(tmp[i][j] != board[i][j]){
                return true;
            }
        }
    }
    return false;
}
void solving(int num){
    int boardTmp[21][21];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            answer = max(answer, board[i][j]);
            boardTmp[i][j] = board[i][j];
        }
    }
    if(num == 5){
        return;
    }
    
    if(goUp()){
        solving(num+1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                board[i][j] = boardTmp[i][j];
            }
        }
    }
    if(goDown()){
        solving(num+1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                board[i][j] = boardTmp[i][j];
            }
        }
    }
    if(goRight()){
        solving(num+1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                board[i][j] = boardTmp[i][j];
            }
        }
    }
    if(goleft()){
        solving(num+1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                board[i][j] = boardTmp[i][j];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }
    solving(0);
    cout << answer;
}