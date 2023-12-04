#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n/5; i++){
            cout << "++++" << ' ';
        }
        for(int i = 0; i < n%5; i++){
            cout << '|';
        }
        cout << '\n';
    }
}