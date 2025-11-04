#include<iostream>
#include<float.h>
using namespace std;


int n, answerCnt;
int buildingHeight[51];
double gradient;

bool canSee(int now, int comp){
    double nowGradient = double(buildingHeight[comp]-buildingHeight[now])/double(comp-now);
    if(now > comp)nowGradient *= -1;
    if(nowGradient > gradient){
        gradient = nowGradient;
        return true;
    }
    return false;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> buildingHeight[i];
    }
    
    for(int i = 0; i < n; i++){
        int tmpCnt = 0;
        //왼쪽으로
        gradient = -DBL_MAX;
        for(int j = i-1; j >= 0; j--){
            if(canSee(i, j))tmpCnt++;
        }
        //오른쪽으로
        gradient = -DBL_MAX;
        for(int j = i+1; j < n; j++){
            if(canSee(i, j))tmpCnt++;
        }
        if(tmpCnt > answerCnt)answerCnt = tmpCnt;
    }
    cout << answerCnt;
}