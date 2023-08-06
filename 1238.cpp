#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int INF = 10000000;
int n, m, x;
int dist[1001][1001] = {0, };
void input();
void dijkstra(int start);
int answer();
priority_queue<pair<int, int>>q;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            if(dist[i][j] < INF)
                q.push({-dist[i][j], j});
        }
        dijkstra(i);
    }
    cout << answer();
}

void input(){
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    int tmp1, tmp2, tmp3;
    for(int i = 0; i < m; i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        dist[tmp1][tmp2] = tmp3;
    }
}
//dist[start][1~n]
void dijkstra(int start){
    while(!q.empty()){
        int currentDist = -q.top().first;
        int currentNode = q.top().second;
        q.pop();
        if(currentDist > dist[start][currentNode]) continue;
        for(int i = 1; i <= n; i++){
            if(dist[start][i] > currentDist+dist[currentNode][i]){
                dist[start][i] = currentDist+dist[currentNode][i];
                q.push({-dist[start][i], i});
            }
        }
        
    }
}

int answer(){
    int maxi = 0;
    for(int i = 1; i <= n; i++){
        maxi = max(maxi, dist[i][x]+dist[x][i]);
    }
    return maxi;
}