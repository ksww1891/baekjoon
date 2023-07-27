#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, m;
    string tmp1, tmp2;
    cin >> n >> m;
    unordered_map<string, string>passwords;
    for(int i = 0; i < n; i++){
        cin >> tmp1 >> tmp2;
        passwords.insert(make_pair(tmp1, tmp2));
    }
    for(int i = 0; i < m; i++){
        cin >> tmp1;
        cout << passwords[tmp1] << '\n';
    }
}