#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<pair<int, int>>items;
vector<int>bag;
priority_queue<int, vector<int>>pq;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        items.push_back({a, b});
    }
    for(int i = 0; i < k; i++){
        cin >> a;
        bag.push_back(a);
    }
    sort(items.begin(), items.end());
    sort(bag.begin(), bag.end());
    long long int answer = 0;
    int idx = 0;

    for(int i = 0; i < k; i++){
        while(idx < n && bag[i] >= items[idx].first){
            pq.push(items[idx].second);
            idx++;
        }
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer;
}