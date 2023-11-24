#include<iostream>
#include<string>
#define INF 2501;
using namespace std;

string str;
bool dp[2501][2501];
int answer[2501];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	str = ' ' + str;
	int n = str.size();
	for(int i = 1; i <= n; i++){
		dp[i][i] = 1;
	}
	for(int i = 1; i < n; i++){
		if(str[i] == str[i+1])dp[i][i+1] = 1;
	}
	for(int i = n-2; i > 0; i--){
		for(int j = i+2; j <= n; j++){
			if(str[i] == str[j] && dp[i+1][j-1] == 1)dp[i][j] = 1;
		}
	}
	answer[0] = 0;
	for(int i = 1; i <= n; i++){
		answer[i] = INF;
		for(int j = 1; j <= i; j++){
			if(dp[j][i] == 1){
				answer[i] = min(answer[i], answer[j-1] + 1);
			}
		}
		cout << answer[i] << ' ';
	}
	cout << answer[n]-1;
}