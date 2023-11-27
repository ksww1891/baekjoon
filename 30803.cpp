#include<iostream>
using namespace std;

int n, q;
long long water;
long long A[200001];
bool At[200001];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        water += A[i];
        At[i] = 1;
    }
    cout << water << '\n';
    cin >> q;
    while(q--){
        long long tmp1, tmp2, tmp3;
        cin >> tmp1;
        if(tmp1 == 1){
            cin >> tmp2 >> tmp3;

            if(At[tmp2] == 0){
                A[tmp2] = tmp3;
            }
            else{
                water -= A[tmp2];
                A[tmp2] = tmp3;
                water += A[tmp2];
            }
        }
        else {
            cin >> tmp2;

            if(At[tmp2] == 0){
                At[tmp2] = 1;
                water += A[tmp2];
            }
            else {
                At[tmp2] = 0;
                water -= A[tmp2];
            }
        }
        cout << water << '\n';
    }
}