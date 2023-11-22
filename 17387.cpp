#include<iostream>
#define ll long long
using namespace std;


ll x[5];
ll y[5];

ll ccw(int a, int b, int c){
    ll ret = (x[a]*y[b] + x[b]*y[c] + x[c]*y[a]) - (y[a]*x[b] + y[b]*x[c] + y[c]*x[a]);
    if(ret > 0)return 1;
    else if(ret < 0)return -1;
    return 0;
}
bool check(){
    ll abc = ccw(1,2,3);
    ll abd = ccw(1,2,4);
    ll cda = ccw(3,4,1);
    ll cdb = ccw(3,4,2);
    //cout << abc << ' ' << abd << ' ' << cda << ' ' << cdb << '\n';
    if(abc * abd == 0 && cda * cdb == 0){
        pair<ll, ll> p[5];
        for(int i = 1; i <= 4; i++){
            p[i] = {x[i], y[i]};
        }
        if(p[1] > p[2])swap(p[1], p[2]);
        if(p[3] > p[4])swap(p[3], p[4]);
        if(p[1] <= p[4] && p[2] >= p[3])return true;
        else return false;
    }
    else {
        if((abc*abd <= 0) && (cda*cdb <= 0)){
            return true;
        }
        else return false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    for(int i = 1; i <= 4; i++){
        cin >> x[i] >> y[i];
    }
    cout << check();
    
}