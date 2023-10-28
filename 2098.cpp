#include<iostream>
#include<cstring>
using namespace std;
#define INF 987654321
int n, w[16][16];
int dp[16][1<<16];

int dfs(int cur, int visited){
	if(visited == (1<<n)-1){
		if(w[cur][0] == 0)return INF;
		return w[cur][0];
	}
	if(dp[cur][visited] != -1)return dp[cur][visited];
	dp[cur][visited] = INF;
	for(int i = 1; i < n; i++){
		if(w[cur][i] == 0)continue;
		if((visited & (1<<i)) == (1<<i))continue;
		dp[cur][visited] = min(dp[cur][visited], w[cur][i] + dfs(i, visited | (1<<i)));
	}
	return dp[cur][visited];
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> w[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1);
}