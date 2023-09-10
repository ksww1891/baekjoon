#include<iostream>
#include<vector>
using namespace std;

int n, k;
pair<int, int>stuff[101];
void input();
int dynamic();
int dp[101][100001] = {0, };
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    cout << dynamic();

}

void input(){
    cin >> n >> k;
    int w, v;
    for(int i = 1 ; i <= n; i++){
        cin >> stuff[i].first >> stuff[i].second;
    }
}

int dynamic(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j >= stuff[i].first) 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - stuff[i].first] + stuff[i].second);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}