#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int answer, n;
    answer = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if(abs(tmp1-answer) <= tmp2)answer++;
    }
    cout << answer;
}