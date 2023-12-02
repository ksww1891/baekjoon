#include<iostream>
using namespace std;

int n;
void solve(int a, int b, int c, int n){
    if(n == 1){
        cout << a << ' ' << c << '\n';
        return;
    }
    solve(a, c, b, n-1);
    cout << a << ' ' << c  << '\n';
    solve(b, a, c, n-1); 
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    cout << (1<<n)-1 << '\n';
    solve(1, 2, 3, n);
}