#include<iostream>

using namespace std;
#define mod 1000000000
int dp[101][10][1<<10];

int n;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int answer = 0;
    if(n < 10){
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= 9; i++)
        dp[1][i][1<<i] = 1;
    //dynamic programming
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 1; k < 1024; k++){
                if(j == 0) dp[i][j][k|(1<<0)] = (dp[i][j][k|(1<<0)] + dp[i-1][1][k])%mod;
                else if(j == 9) dp[i][j][k|(1<<9)] = (dp[i][j][(k|1<<9)] + dp[i-1][8][k])%mod;
                else{
                    dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j-1][k])%mod;
                    dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j+1][k])%mod;
                }
            }
        }
    }

    for(int i = 0; i <= 9; i++){
        answer = (answer + dp[n][i][1023])%mod;
    }
    cout << answer;
}