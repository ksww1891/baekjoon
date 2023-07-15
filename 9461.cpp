#include<iostream>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    int n;
    long long answer[101] = {0, };
    answer[0] = answer[1] = answer[2] = 1;
    for(int i = 3; i <101; i++){
        answer[i] = answer[i-3] + answer[i-2];
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout <<answer[n-1]<< '\n';
    }
}