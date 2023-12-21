#include<iostream>
using namespace std;
#define ll long long

ll a, b;

ll fun(ll num){
    ll idx = 0;
    while(((ll)1 << idx) <= num){
        idx++;
    }
    ll cnt = 0;
    ll ret = 0;
    for(ll i = idx-1; i > 0; i--){
        if(num & ((ll)1 << i)){
            ret += (((ll)1<<(i-1))*(i)) + cnt*(((ll)1<<i));
            cnt++;
        }
    }
    ret += cnt;
    if(num % 2){
        ret += cnt + 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> a >> b;
    cout << fun(b) - fun(a-1);
}