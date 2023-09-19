#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int>arr;
int dp1[1001] = {0, };
int dp2[1001] = {0, };
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    dp1[0] = dp2[0] = 1;
    for(int i = 1 ; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(arr[j] < arr[i]){
                if(dp1[j] > dp1[i]){
                    dp1[i] = dp1[j];
                }
            }
        }
        dp1[i]++;
    }
    reverse(arr.begin(), arr.end());
    for(int i = 1 ; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(arr[j] < arr[i]){
                if(dp2[j] > dp2[i]){
                    dp2[i] = dp2[j];
                }
            }
        }
        dp2[i]++;
    }
    int answer = 0;
    for(int i = 0 ; i < n; i++){
        answer = max(answer, dp1[i]+dp2[n-1-i]);
    }
    cout << answer-1;
}