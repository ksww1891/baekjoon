#include<iostream>
using namespace std;

int n, m;
int arr[9];

void recursive(int cnt, int lastN){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = lastN; i <= n; i++){
        arr[cnt] = i;
        recursive(cnt+1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    recursive(0, 1);
}