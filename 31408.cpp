#include<iostream>

using namespace std;

int n;
int person[100001];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        person[tmp]++;
    }
    if(n%2 == 0){
        n /= 2;
    }
    else{
        n /= 2;
        n++;
    }
    for(int i = 0; i < 10001; i++){
        if(person[i] > n){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}