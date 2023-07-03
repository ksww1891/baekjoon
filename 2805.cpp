#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long n, m;
long long cutting(int high);    
vector<long long>tree;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long tmp;

    cin >> n >> m;
    for(long long i = 0; i < n; i++){
        cin >> tmp;
        tree.push_back(tmp);
    }

    sort(tree.begin(), tree.end());

    long long sum = 0;
    long long start = 0;
    long long end = tree[n-1];
    long long answer;
    while(end-start >= 0){
        int mid = (start + end)/2;
        sum = cutting(mid);
        if (sum >= m){
            answer = mid;
            start = mid + 1;
        }
        if (sum < m)
            end = mid-1;
    }
    cout << (start+end)/2;
}

long long cutting(int high){
    long long cuttingSum = 0;
    for (int i = 0; i < n; i++){
        if(tree[i] - high > 0)
        cuttingSum += tree[i] - high;
    }
    return cuttingSum;
}