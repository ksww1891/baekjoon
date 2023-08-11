#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

//n : node 갯수
//m : 간선 갯수
//w : 윔홀 갯수
int n, m, w;
int INF = 987654321;
vector<pair<int, int>>graph[501];
int d[501];
void input();
bool bellman();

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--){
        input();
        if(bellman()) cout << "YES"<< '\n';
        else cout << "NO"<< '\n';
        for(int i = 0; i < 501; i++){
            graph[i].clear();
        }
    }
}
void input(){
    cin >> n >> m >> w;
    int s, e, t;
    for(int i = 0; i < m; i++){
        cin >> s >> e >> t;
        graph[s].push_back({e, t});
        graph[e].push_back({s, t});
    }
    for(int i = 0; i < w; i++){
        cin >> s >> e >> t;
        graph[s].push_back({e, -t});
    }
}
bool bellman(){
    for(int i = 0; i <= n; i++){
        d[i] = INF;
    }
    d[1] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < graph[j].size(); k++){
                int from = j;
                int to = graph[j][k].first;
                int cost = graph[j][k].second;

                if(d[to] > d[from]+cost){
                    d[to] = d[from]+cost;
                }
            }
        }
    }
    for(int j = 1; j <= n; j++){
        for(int k = 0; k < graph[j].size(); k++){
            int from = j;
            int to = graph[j][k].first;
            int cost = graph[j][k].second;

            if(d[to] > d[from]+cost){
                return true;
            }
        }
    }
    return false;
}