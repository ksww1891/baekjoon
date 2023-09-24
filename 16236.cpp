#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int n;
int map[21][21] = {0, };
bool visited[21][21] = {0, };
int sharkSize = 2;
int xp = 0;
int answer = 0;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>q;
void bfs();
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
			
			if(map[i][j] == 9){
				visited[i][j] = 1;
				map[i][j] = 0;
				q.push({0, i, j});
			}
		}
	}
	bfs();
	cout << answer;
}

void bfs(){
	while (!q.empty()){
		int nowDist = get<0>(q.top());
		int nowY = get<1>(q.top());
		int nowX = get<2>(q.top());
		q.pop();
		if(map[nowY][nowX] < sharkSize && map[nowY][nowX] >= 1){
			xp++;
			if(xp == sharkSize){
				sharkSize++;
				xp = 0;
			}
			answer += nowDist;
			map[nowY][nowX] = 0;
			while(!q.empty())q.pop();
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					visited[i][j] = 0;
				}
			}
			visited[nowY][nowX] = 1;
			q.push({0, nowY, nowX});
			continue;
		}
		for(int i = 0; i < 4; i++){
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];
			if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n)continue;
			if(map[nextY][nextX] > sharkSize)continue;
			if(visited[nextY][nextX] == 0){
				visited[nextY][nextX] = 1;
				q.push({nowDist+1, nextY, nextX});
			}
		}
	}
	
}