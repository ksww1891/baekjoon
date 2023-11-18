#include<iostream>
using namespace std;

int n, q;
int flower[1001];

int firstQ(int s, int e, int k){
    int cnt = 0;
    for(int i = s; i <= e; i++){
        if(flower[i] == k){
            cnt++;
        }
    }
    return cnt;
}

void secondQ(int s, int e){
    for(int i = s; i <= e; i++){
        flower[i] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> flower[i];
    }
    cin >> q;
    int tmp;
    while(q--){
        cin >> tmp;
        if(tmp == 1){
            int a, b, c;
            cin >> a >> b >> c;
            cout << firstQ(a, b, c) << '\n';
        }
        else {
            int a, b;
            cin >> a >> b;
            secondQ(a, b);
        }
    }
}