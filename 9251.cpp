#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    string A, B;
    int answer[1002][1002] = {0, };
    cin >> A >> B;
    for(int i = 0; i < max((int)A.size(), (int)B.size()); i++){
        answer[i][0] = answer[0][i] = 0;
    }
    for(int i = 1; i <= A.size(); i++){
        for(int j = 1; j <= B.size(); j++){
            if(A[i-1] == B[j-1]){
                answer[i][j] = answer[i-1][j-1]+1;
            }
            else{
                answer[i][j] = max(answer[i-1][j], answer[i][j-1]);
            }
        }
    }
    cout << answer[(int)A.size()][(int)B.size()];
}