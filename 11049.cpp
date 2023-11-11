#include<iostream>
#include<vector>
#define INF 2147483647
using namespace std;

int n;
int dp[501][501];//[a][b]a번째에서 b번째까지의 최소행렬계산수
vector<pair<int, int>>rc;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int a, b;

    rc.push_back({0, 0});
    for(int i = 0 ; i< n; i++){
        cin >> a >> b;
        rc.push_back({a, b});
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; i+j <= n; j++){
            dp[j][i+j] = INF;
            for(int k = j; k <= i+j; k++){
                dp[j][i+j] = min(dp[j][i+j], dp[j+k][i+j] + dp[j][k] + rc[j].first*rc[k].second*rc[i+j].second);
            }
        }
    }
    cout << dp[1][n];
}