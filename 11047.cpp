#include<iostream>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, k;
    int coinValue[11] = {0, };
    int answer = 0;

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> coinValue[i];

    for(int i = n-1; i >= 0; i--){
        answer += k/coinValue[i];
        k %= coinValue[i];
    }
    cout << answer;
}