#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    int arr[1001]= {0, };
    int dp[1001] = {0, };
    int answer = 1;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(arr[j] < arr[i]){
                if(dp[j] > dp[i]){
                    dp[i] = dp[j];
                }
            } 
        }
        dp[i]++;
        answer = max(answer, dp[i]);
    }
    cout << answer;
}

