#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;
int cnt;
int parents[100001];
vector<pair<int, pair<int, int>>>cost;
vector<int>answer;

int find(int a){
    if(parents[a] == a)return a;
    else return parents[a] = find(parents[a]);
}
bool isDiffP(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b){
        return false;
    }
    else return true;
}
int solving(){
    int ret = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int nowCost = cost[i].first;
        int nodeA = cost[i].second.first;
        int nodeB = cost[i].second.second;
        if(isDiffP(nodeA, nodeB)){
            nodeA = find(nodeA);
            nodeB = find(nodeB);
            parents[nodeB] = nodeA;
            answer.push_back(nowCost); 
        }
    }
    for(int i = 0; i < answer.size()-1; i++){
        ret += answer[i];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        parents[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost.push_back({c, {a, b}});
    }
    sort(cost.begin(), cost.end());
    cout << solving();
}