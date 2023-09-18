#include<iostream>
#include<vector>

using namespace std;

char board[3073][6145];



void drawStar(int y, int x, int a){
    if(a == 3){
        board[y][x] = '*';
        board[y+1][x-1] = '*';
        board[y+1][x+1] = '*';
        for(int i = x-2; i < x+3; i++){
            board[y+2][i] = '*';
        }
        return;
    }
    drawStar(y, x, a/2);
    drawStar(y+a/2, x - a/2, a/2);
    drawStar(y+a/2, x + a/2, a/2);
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    
    for(int i = 0; i < 3073; i++){
        for(int j = 0; j < 6145; j++){
            board[i][j] = ' ';
        }
    }

    drawStar(0, n-1, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n-1; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
    
}