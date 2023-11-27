#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, T, P, answerT = 0, answerP1 = 0, answerP2 = 0;
    int t[6] = {0, };
    //입력
    cin >> n;
    for(int i = 0; i < 6; i++){
        cin >> t[i];
    }
    cin >> T >> P;
    for(int i = 0; i< 6; i++){
        if(t[i]%T == 0){
            answerT += t[i]/T;
        }
        else answerT += t[i]/T + 1;
    }
    answerP1 = n/P;
    answerP2 = n-answerP1*P;
    cout << answerT << '\n';
    cout << answerP1 << ' ' << answerP2;
}