#include<iostream>
#include<algorithm>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int answer[3][1001] = {0, };
    int value[3][1001] = {0, };
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++)
            cin >> value[j][i];
    }
    for(int i = 0; i < 3; i++)
        answer[i][0] = value[i][0];
    
    for(int i = 0; i < n; i++){
        answer[0][i+1] = min(answer[1][i], answer[2][i]) + value[0][i+1];
        answer[1][i+1] = min(answer[0][i], answer[2][i]) + value[1][i+1];
        answer[2][i+1] = min(answer[0][i], answer[1][i]) + value[2][i+1];
    }
    cout << min(min(answer[0][n-1], answer[1][n-1]), answer[2][n-1]);
}