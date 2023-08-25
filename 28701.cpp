#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    int answer = (n*(n+1)/2);
    cout << answer << '\n' << answer*answer << '\n' << answer*answer;
}