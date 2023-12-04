#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    pair<int, int>answer = {1001, 1001};
    pair<int, int>tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp.first >> tmp.second;
        if(tmp.second < answer.second)answer = tmp;
    }
    cout << answer.first << ' ' << answer.second;
}