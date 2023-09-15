#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, start, arrival;
vector<pair<int, int>>map[1001];
int INF = 987654321;

void input(){
	int tmp1, tmp2, value;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> tmp1 >> tmp2 >> value;
		map[tmp1].push_back({tmp2, value});
	}
	cin >> start >> arrival;
}

int dijkstra(){
	int dist[1001];
	for(int i = 0; i < 1001; i++){
		dist[i] = INF;
	}
	priority_queue<pair<int, int>>pq;
	dist[start] = 0;
	pq.push({0, start});
	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dist[here] < cost)continue;
		for(int i = 0; i < map[here].size(); i++){
			int there = map[here][i].first;
			int nextDist = cost + map[here][i].second;
			if(dist[there] > nextDist){
				dist[there] = nextDist;
				pq.push({-dist[there], there});
			}
		}
	}
	return dist[arrival];
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	cout << dijkstra();

} 