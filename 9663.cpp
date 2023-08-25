#include<iostream>
#include<cmath>
using namespace std;

void placing(int r);
int answer = 0;
int board[15] = {0, };
int n;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    placing(0);
    cout << answer;
}

void placing(int r){
    if(r==n){answer++; return;}
    for(int i = 0; i < n; i++){
        int isIpossible = 1;
        for(int j = 0; j<r; j++){
            if(board[j] == i || abs(i-board[j]) == abs(r-j)){
                isIpossible = 0;
                break;
            }
        }
        if(isIpossible){
            board[r]=i;
            placing(r+1);
        }
    }
}