#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int V, e, k;
vector<pair<int, int>>graph[20001];
int d[20001] = {0, };
int INF = 1000000;
void input();
void dijkstra();

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    dijkstra();
    for(int i = 1; i <= V; i++){
        if(d[i] == INF){
            cout << "INF" << '\n';
            continue;
        }
        cout << d[i] << '\n';
    }
}

void input(){
    cin >> V >> e;
    cin >> k;
    int u, v, w;
    for(int i = 0; i < e; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
}

void dijkstra(){
    bool visited[20001] = {0, };
    for(int i = 0; i <= V; i++){
        d[i] = INF;
    }
    d[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, k});
    while(!pq.empty()){
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if(visited[currentNode]==1)continue;
        visited[currentNode] = 1;
        for(int i = 0; i < graph[currentNode].size(); i++){
            if(currentDist + graph[currentNode][i].second < d[graph[currentNode][i].first]){
                d[graph[currentNode][i].first] = currentDist + graph[currentNode][i].second;
                pq.push({d[graph[currentNode][i].first], graph[currentNode][i].first});
            }
        }
    }
}