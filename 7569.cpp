#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

int m, n, h;
int tomato[101][101][101] = {0, };
int visited[101][101][101] = {0, };
queue<tuple<int, int, int>>q;
int answer = 0;
int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {-1, 1, 0, 0,0,0};
int dz[6] = {0, 0, 0, 0, -1, 1};

void input(){
	cin >> m >> n >> h;
    for(int k = 1; k <= h; k++){
	    for (int i=1; i<=n; i++){
		    for (int j=1; j<=m; j++){
			    cin >> tomato[k][i][j];
		    }
	    }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	//큐에 들어갈 토마토 위치 찾기
	int isThere = 0;
    for(int k = 1; k <= h; k++){
	    for(int i=1; i<=n; i++){
		    for (int j=1; j<=m; j++){
			    if(tomato[k][i][j] == 1){
				    visited[k][i][j] = 1;
				    q.push(make_tuple(k, i, j));
			    }
		    }
	    }
    }
	
	while(!q.empty()){
		for (int i=0; i<6; i++){
			int x = get<2>(q.front())+dx[i];
			int y = get<1>(q.front())+dy[i];
            int z = get<0>(q.front()) + dz[i];
			if(x>=1 && x<=m && y>=1 && y<=n && z>=1 && z<=h)
				if(visited[z][y][x] == 0 && tomato[z][y][x] == 0){
					visited[z][y][x] == 1;
					q.push(make_tuple(z, y, x));
					tomato[z][y][x] = tomato[z-dz[i]][y-dy[i]][x-dx[i]] + 1;
				}
		}
		q.pop();
	}
    for(int k = 1; k <= h; k++){
	    for(int i=1; i<=n; i++){
		    for (int j=1; j<=m; j++){
			    if(tomato[k][i][j] == 0){
				    cout << -1;
					    return 0;
			    }
			    answer = max(answer, tomato[k][i][j]);
		    }
	    }
    }
	cout << answer-1;
	return 0;
}