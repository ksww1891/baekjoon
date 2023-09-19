#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

vector<pair<int, int>>map[1001];
vector<int>path[1001];
int n, m;
void input();
void dijkstra();
int s, e;
int answer = 0;
int INF = 987654321;


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    dijkstra();
}

void input(){
    cin >> n >> m;
    int a, b, c;
    for(int i = 0 ; i < m; i++){
        cin >> a >> b >> c;
        map[a].push_back({b, c});
    }
    cin >> s >> e;
}

void dijkstra(){
    int dist[1001] = {0, };
    priority_queue<pair<int, int>>pq;
    for(int i = 0 ; i < 1001; i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    path[s].push_back(s);
    pq.push({0, s});
    while(!pq.empty()){
        int nowValue = -pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();
        if(dist[nowNode] < nowValue)continue;
        for(int i = 0; i < (int)map[nowNode].size(); i++){
            int nextNode = map[nowNode][i].first;
            int nextValue = nowValue + map[nowNode][i].second;
            if(nextValue < dist[nextNode]){
                dist[nextNode] = nextValue;
                path[nextNode].clear();
                for(int i = 0; i < path[nowNode].size(); i++){
                    path[nextNode].push_back({path[nowNode][i]});
                }
                path[nextNode].push_back(nextNode);
                pq.push({-nextValue, nextNode});
            }
        }
    }
    cout << dist[e] <<'\n' <<  path[e].size() << '\n';
    for(int i = 0; i < (int)path[e].size(); i++){
        cout << path[e][i] << ' ';
    }
}