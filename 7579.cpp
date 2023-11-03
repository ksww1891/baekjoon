#include<iostream>

using namespace std;

int n, m, sum;
int appM[101];
int appC[101];

int dp[101][10001];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> appM[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> appC[i];
        sum += appC[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(j >= appC[i]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-appC[i]] + appM[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    for(int i = 0; i <= sum; i++){
        if(dp[n][i] >= m){
            cout << i;
            return 0;
        }
    }
}