#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, x;
    cin >> n >> x;
    int tmp;
    int solving = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        solving += tmp%x;
    }
    if(solving % x == 0)cout << 1;
    else cout << 0;
    return 0;
}