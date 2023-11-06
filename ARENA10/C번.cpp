#include<iostream>

using namespace std;

int n, l;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> l;
    for(int i = 0; i < l-1; i++){
        cout << 1;
    }
    cout << n;
}