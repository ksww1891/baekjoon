#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t;
long long n, m, answer;
long long a[1002], b[1002], aSum[1002], bSum[1002];
vector<long long>va;
vector<long long>vb;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> t;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        aSum[i] = aSum[i-1] + a[i];
        for(int j = 0; j < i; j++){
            va.push_back(aSum[i] - aSum[j]);
        }
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        bSum[i] = bSum[i-1] + b[i];
        for(int j = 0; j < i; j++){
            vb.push_back(bSum[i] - bSum[j]);
        }
    }
    sort(va.begin(), va.end());
    for(int i = 0; i < vb.size(); i++){
        int findT = t-vb[i];
        int cnt = upper_bound(va.begin(), va.end(), findT) - lower_bound(va.begin(), va.end(), findT);
        answer += cnt;
    }
    cout << answer;
}