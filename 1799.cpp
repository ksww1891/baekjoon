#include<iostream>
#include<vector>
using namespace std;

int n, answer[2];
bool board[11][11], flag;
bool in[20], de[20];

void solving(int y, int x, int cnt){
    if(x >= n){
        y++;
        if(x%2 == 0)x = 1;
        else x = 0;
    }
    if(y >= n){  
        answer[flag] = max(answer[flag], cnt);
        return;
    }
    if(board[y][x] && in[y-x+n-1] == 0 && de[y+x] == 0){
        in[y-x+n-1] = de[y+x] = 1;
        solving(y, x+2, cnt+1);
        in[y-x+n-1] = de[y+x] = 0;
    }
    solving(y, x+2, cnt);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    flag = 0;
    solving(0, 0, 0);
    flag = 1;
    solving(0, 1, 0);
    cout << answer[0] + answer[1];
}