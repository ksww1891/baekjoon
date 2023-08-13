#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int>v[501];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    int tmp;
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < n-1; j++){
            v[i][j] = v[i][j] + max(v[i+1][j], v[i+1][j+1]);
        }
    }
    cout << v[1][0];
}

