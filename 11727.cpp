#include<iostream>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    long long answer[1001] = {0, };
    answer[1] = 1;
    answer[2] = 3;
    for(int i = 3; i < 1001; i++){
        answer[i] = (answer[i-1]+answer[i-2]*2)%10007;
    }
    cin >> n;
    cout << answer[n];
}