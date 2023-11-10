#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dp[2000][2000];
vector<int>num;
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        num.push_back(tmp);
        dp[i][i] = 1;
    }
    for(int i = 0; i < n-1; i++){
        if(num[i] == num[i+1]){
            dp[i][i+1] = 1;
        }
    }
    //dp
    for(int i = n-2 ; i >= 0; i--){
        for(int j = i+2; j < n; j++){
            if(num[i] == num[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
            }
        }
    }
    cin >> m;
    while(m--){
        int s, e;
        cin >> s >> e;
        cout << dp[s-1][e-1] << '\n'; 
    }
}