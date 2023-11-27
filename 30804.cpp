#include<iostream>

using namespace std;

int n, answer;
int tanghr[200001];

int solve(int a, int b){
    int ret = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(tanghr[i] == a || tanghr[i] == b){
            cnt++;
        }
        else {
            ret = max(ret, cnt);
            cnt = 0;
        }
    }
    ret = max(ret, cnt);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tanghr[i];
    }
    for(int i = 1; i < 9; i++){
        for(int j = i+1; j < 10; j++){
            answer = max(answer, solve(i, j));
        }
    }
    cout << answer;
}