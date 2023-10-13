#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>>edge;
vector<int>p(1005, -1);
int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool isDiffGroup(int nodeA, int nodeB){
    nodeA = find(nodeA); nodeB = find(nodeB);
    if(nodeA == nodeB)return 0;
    if(p[nodeA] == p[nodeB]) nodeA--;
    if(p[nodeA] < p[nodeB]) p[nodeB] = nodeA;
    else p[nodeA] = nodeB;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(a == b)continue;
        edge.push_back({c, {a, b}});
    }
    sort(edge.begin(), edge.end());
    int answer = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int cost = edge[i].first;
        int nodeA = edge[i].second.first;
        int nodeB = edge[i].second.second;
        if(!isDiffGroup(nodeA, nodeB))continue;
        answer += cost;
        cnt++;
        if(cnt == n-1)break;
    }
    cout << answer;
}