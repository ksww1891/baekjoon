#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m, r;
int map_item[101] = {0, };
vector<pair<int, int>>map_dist[101];

void input();
int dijkstra(int start);

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    int answer = 0;
    for(int i = 1; i <= n; i++){
        answer = max(answer, dijkstra(i));
    }
    cout << answer;
}

void input(){
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> map_item[i];
    }
    int a, b, l;
    for(int i = 0; i < r; i++){
        cin >> a >> b >> l;
        map_dist[a].push_back({b, l});
        map_dist[b].push_back({a, l});
    }
}

int dijkstra(int start){
    int dist[101];
    for(int i = 0; i <= n; i++){
        dist[i] = 987654321;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>>q;
    q.push({0, start});
    while(!q.empty()){
        int nowDist = -q.top().first;
        int nowNode = q.top().second;
        q.pop();
        if(nowDist > dist[nowNode]) continue;
        for(int i = 0; i < map_dist[nowNode].size(); i++){
            int nextDist = nowDist + map_dist[nowNode][i].second;
            int nextNode = map_dist[nowNode][i].first;
            if(dist[nextNode] > nextDist){
                dist[nextNode] = nextDist;
                q.push({-nextDist, nextNode});
            }
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] <= m)ret += map_item[i];
    }
    return ret;
}