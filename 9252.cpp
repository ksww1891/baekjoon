#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string answerS;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    string A, B;
    int answer[1002][1002] = {0, };
    cin >> A >> B;
    
    A = ' ' + A;
    B = ' ' + B;
    for(int i = 1; i < B.size(); i++){
        for(int j = 1; j < A.size(); j++){
            if(A[j] == B[i]){
                answer[i][j] = answer[i-1][j-1]+1;
            }
            else{
                answer[i][j] = max(answer[i-1][j], answer[i][j-1]);
            }
        }
    }
    int idx2 = A.size()-1;
    int idx1 = B.size()-1;
    
    
    while(answer[idx1][idx2] > 0){
        if(answer[idx1][idx2] == answer[idx1-1][idx2]){
            idx1--;
        }
        else if(answer[idx1][idx2] == answer[idx1][idx2-1]){
            idx2--;
        }
        else{
            answerS += A[idx2];
            idx1--;
            idx2--;
        }
    }
    cout << answer[(int)A.size()-1][(int)B.size()-1] << '\n';
    if(answerS.size() > 0){
        for(int i = answerS.size()-1; i >= 0; i--){
            cout << answerS[i];
        }
    }
}