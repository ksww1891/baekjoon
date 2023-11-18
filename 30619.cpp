#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, m;
    int arr[301];
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> m;
    int L, R;
    while(m--){
        cin >> L >> R;
        int idx = L;
        for(int i = 1; i <= n; i++){
            if(arr[i] < L || arr[i] > R){
                cout << arr[i] << ' '; 
            }
            else {
                cout << idx << ' ';
                idx++;
            }
        }
        cout << '\n';
    }
}