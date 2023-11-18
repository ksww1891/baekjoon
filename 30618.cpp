#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    if(n==1){
        cout << 1;
        return 0;
    }
    for(int i = 2; i <= n; i+=2){
        cout << i << ' ';
    }
    if(n%2 == 1){
        cout << n << ' ';
        for(int i = n-2; i >= 1; i-=2){
            cout << i << ' ';
        }
        return 0;
    }
    else{
        for(int i = n-1; i >= 1; i-=2){
            cout << i << ' ';
        }
    }
}