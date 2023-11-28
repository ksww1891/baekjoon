#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int cnt[32001];
vector<int>v[32001];
priority_queue<int, vector<int>, greater<int>>pq;


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cnt[b]++;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0)pq.push(i);
    }
    while(!pq.empty()){
        int nowNode = pq.top();
        pq.pop();
        cout << nowNode << ' ';
        for(int i = 0; i < v[nowNode].size(); i++){
            cnt[v[nowNode][i]]--;
            if(cnt[v[nowNode][i]] == 0){
                pq.push(v[nowNode][i]);
            }
        }
    }
}