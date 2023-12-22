#include<iostream>
using namespace std;

bool bulb[11][11];
bool bulbTmp[11][11];
int cntAnswer = 987654321;

void push(int i, int j){
    bulb[i][j] = !bulb[i][j];
    if(i-1 >= 0){
        bulb[i-1][j] = !bulb[i-1][j];
    }
    if(j-1 >= 0){
        bulb[i][j-1] = !bulb[i][j-1];
    }
    if(j+1 < 10){
        bulb[i][j+1] = !bulb[i][j+1];
    }
    if(i+1 < 10){
        bulb[i+1][j] = !bulb[i+1][j];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    char tmp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> tmp;
            if(tmp == 'O'){
                bulbTmp[i][j] = 1;
            }
        }
    }
    for(int k = 0; k < 1024; k++){
        int cnt = 0;
        //복사
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                bulb[i][j] = bulbTmp[i][j];
            }
        }
        //K의 켜져있는 비트만 push
        for(int i = 0; i < 10; i++){
            if(k & (1<<i)){
                push(0, i);
                cnt++;
            }
        }
        //2번째 줄부터 위가 켜져있다면 push
        for(int i = 1; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(bulb[i-1][j] == 1){
                    cnt++;
                    push(i, j);
                }
            }
        }
        //맨 아랫줄에 아직 켜져있는 전구 있는지 확인
        bool isPossible = 1;
        for(int i = 0; i < 10; i++){
            if(bulb[9][i] == 1){
                isPossible = 0;
            }
        }
        //없다면 Answer 최솟값 비교
        if(isPossible)cntAnswer = min(cntAnswer, cnt);
    }
    
    if(cntAnswer == 987654321){
        cout << -1;
    }
    else cout << cntAnswer;
}