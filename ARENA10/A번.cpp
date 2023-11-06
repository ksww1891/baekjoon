#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, l;
    cin >> n >> l;
    string tmp;
    int beautiful = 0;
    int answer = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        char last = '0';
        int lineCnt = 0;
        for(int i = 0 ; i < l; i++){
            if(tmp[i] != last){
                if(last == '0'){
                    lineCnt++;
                    last = '1';
                }
                else last = '0';
            }
        }
        if(beautiful < lineCnt){
            beautiful = lineCnt;
            answer = 1;
        }
        else if(beautiful == lineCnt){
            answer++;
        }
    }
    cout << beautiful <<  ' ' << answer;
}