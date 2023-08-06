#include<iostream>
#include<queue>
using namespace std;

int n, e, v1, v2;
int INF = 1000000;
int graph[801][801] = {0, };
void input();
int dijkstra(int start, int target);

int main (){
    
    int answer[6];
    input();
    answer[0] = dijkstra(1, v1);
    answer[1] = dijkstra(v2, n);
    answer[2] = dijkstra(1, v2);
    answer[3] = dijkstra(v1, n);
    answer[4] = dijkstra(v1, v2);
    for(int i = 0; i < 5; i++){
        if(answer[i] == INF){
            cout << -1;
            return 0;
        }
    }
    cout << min(answer[0]+answer[1], answer[2]+answer[3])+answer[4];
}

void input(){
    cin >> n >> e;
    int a, b, c;
    for(int i = 0; i < 801; i++){
        for(int j = 0; j < 801; j++){
            graph[i][j] = INF;
        }
    }
    for(int i = 0; i <801; i++){
        graph[i][i] = 0;
    }
    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
    }
    cin >> v1 >> v2;
}

int dijkstra(int start, int target){
    int d[801];
    for(int i = 0; i <= n; i++){
        d[i] = INF;
    }
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, start});
    while(!pq.empty()){
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (graph[start][currentNode] < currentDist) continue;
        for(int i = 1; i <= n; i++){
            if(graph[currentNode][i]+currentDist < d[i]){
                d[i] = graph[currentNode][i]+currentDist;
                pq.push({d[i], i});
            }
        }
    }
    return d[target];
}