#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[9];
int numbers[9];

void recursive(int cnt, int lastN){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = lastN; i < n; i++){
        arr[cnt] = numbers[i];
        recursive(cnt+1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    sort(numbers, numbers+n);
    recursive(0, 0);
}