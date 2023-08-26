#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;//n: 도시개수 m: 간선개수

void input();
int dist[101][101];
int INF = 987654321;
void floyd();

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    floyd();
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dist[i][j]==INF){cout<<0<<' ';continue;}
            cout << dist[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void input(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dist[i][j] = INF;
        }
    }
    int start, end, value;
    for(int i = 0; i < m; i++){
        cin >> start >> end >> value;
        dist[start][end] = min(dist[start][end], value);
    }
}
// k > i > j
void floyd(){
    //중간 고르기
    for(int i = 1; i <= n; i++){
        // 도착 고르기
        for(int j = 1; j <= n; j++){
            if(dist[i][j] == INF || i == j)continue;
            //시작 고르기
            for(int k = 1; k <= n; k++){
                if(dist[k][i] == INF || k == i || j == k)continue;
                dist[k][j]= min(dist[k][i]+dist[i][j], dist[k][j]);
            }
        }
    }
}