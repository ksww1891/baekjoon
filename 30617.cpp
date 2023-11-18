#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    int l, r;
    int lastL, lastR, nowL, nowR;
    int answer = 0;
    cin >> t;
    cin >> lastL >> lastR;
    if(lastL == lastR && lastL != 0){
            answer++;
        }
    t--;
    while(t--){
        cin >> nowL >> nowR;
        if(lastL != 0){
            if(nowL == lastL){
                answer++;
            }
        }
        if(lastR != 0){
            if(nowR == lastR){
                answer++;
            }
        }
        if(nowL == nowR && nowL != 0){
            answer++;
        }
        lastL = nowL;
        lastR = nowR;
    }
    cout << answer;
}