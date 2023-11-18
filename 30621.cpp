#include<iostream>

using namespace std;

int n;
int t[100002];
int b[100002];
int c[100002];
int dp[100002];

int findIDX(int num, int e){
    int s = 1;
    int mid;
    while(s<e){
        mid = (s + e)/2;
        if(t[mid] >= num){
            e = mid;
        }
        else s = mid+1;
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> t[i];
    }
    for(int i = 1 ; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1 ; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i-1], dp[findIDX(t[i]-b[i], i-1)-1]+c[i]);
    }
    cout << dp[n];
}