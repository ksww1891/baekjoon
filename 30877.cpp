#include<iostream>
#include<string>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    while(n--){
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        for(int i = 0; i < tmp1.length(); i++){
            if(tmp1[i] == 'X' || tmp1[i] == 'x'){
                if(tmp2[i] >= 'a' && tmp2[i] <= 'z'){
                    cout << char(tmp2[i]-'a' + 'A');
                }
                else cout << tmp2[i];
                break;
            }
        }
    }
}