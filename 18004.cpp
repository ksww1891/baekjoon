#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int a, b;
    int cnt = 0;
    cin >> a >> b;
    while(a != b){
        if(a > b && a%2 == 0){
            a /= 2;
            cnt++;
        }
        else if(a > b){
            a++;
            cnt++;
        }
        else {
            cnt += b-a;
            a = b;
        }
    }
    cout << cnt;
}