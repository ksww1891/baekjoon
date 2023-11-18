#include<iostream>
using namespace std;

int n, m;
int s[1001][2];//0:모름, 1:아님 2:맞음
int plant, answerMax;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    int a;
    char b;
    bool c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(b == 'P'){
            s[a][0] = c+1;
        }
        else {
            s[a][1] = c+1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(s[i][0] == 2 && s[i][1] == 1){
            plant++;
            answerMax++;
        }
        else if((s[i][0] != 1)&&(s[i][1] != 2)){
            answerMax++;
        }

    }
    cout << plant << ' ' << answerMax;
}