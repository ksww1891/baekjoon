#include<iostream>
#include<algorithm>

using namespace std;

int main (){
    int n, t;
    cin >> t;
    
    while(t--){
        cin >> n;
        int sticker[2][100001] = {0, };
        int answer[2][100001] = {0, };
        for (int i = 0; i < 2; i++){
            for (int j = 1; j <= n; j++)
                cin >> sticker[i][j];
        }
        answer[0][1] = sticker[0][1];
        answer[1][1] = sticker[1][1];
        answer[0][2] = answer[1][1] + sticker[0][2];
        answer[1][2] = answer[0][1] + sticker[1][2];
        for (int i = 3; i <= n; i++){
           answer[0][i] = max(answer[1][i-1], answer[0][i-2]);
           answer[0][i] = max(answer[0][i], answer[1][i-2]);
           answer[0][i] += sticker[0][i];
           answer[1][i] = max(answer[0][i-1], answer[1][i-2]);
           answer[1][i] = max(answer[1][i], answer[0][i-2]);
           answer[1][i] += sticker[1][i];
        }
        cout << max(answer[0][n], answer[1][n]) << '\n';
    }
}