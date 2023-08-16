#include<iostream>
#include<vector>
using namespace std;


long long n, b;
long long v[6][6] = {0, };
long long answer[6][6];
long long one[6][6];
void X(long long target);
void square(long long a[6][6], long long b[6][6]);

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin  >> n >> b;
    long long tmp;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            cin >> tmp;
            v[i][j]=answer[i][j] = tmp;
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            one[i][j] = 1;
        }
    }
    X(b);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            cout << answer[i][j]%1000 << ' ';
        }
        cout << '\n';
    }
}

void X(long long target){
    if(target==1)return;
    if(target%2 == 1){
        X(target-1);
        square(answer, v);
    }
    else{
        X(target/2);
        square(answer, answer);
    }
}

void square(long long a[6][6], long long b[6][6]){
    long long answerTmp[6][6] = {0, };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                answerTmp[i][j] += ((a[i][k]%1000)*(b[k][j]%1000))%1000;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answer[i][j] = (answerTmp[i][j])%1000;
        }
    }
    return;
}