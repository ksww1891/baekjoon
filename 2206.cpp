#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>>map;
int visited[1001][1001][2] = {0, };
int bfs();

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//입력
	cin >> n >> m;
	for(int i = 0;i < n; i++){
		string tmp;
		cin >> tmp;
		vector<int>v;
		for(int j = 0 ; j < m; j++){
			v.push_back(tmp[j]-'0');
		}
		map.push_back(v);
	}
	visited[0][0][0]=1;
	cout << bfs();
}

int bfs(){
	queue<tuple<int, int, bool>>q;//<y, x, isBroken>
	q.push(make_tuple(0, 0, 0));
	while(!q.empty()){
		int nowY = get<0>(q.front());
		int nowX = get<1>(q.front());
		bool isBroken =get<2>(q.front());
		q.pop();
		if (nowY==n-1 && nowX==m-1){
			return visited[n-1][m-1][isBroken];
		}
		for(int i = 0; i < 4; i++){
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];
			if(nextX < m && nextX >= 0 && nextY < n && nextY >= 0){
				if(map[nextY][nextX] == 1 && visited[nextY][nextX][1]== 0 &&isBroken == 0){
					visited[nextY][nextX][1] = visited[nowY][nowX][isBroken]+1;
					q.push({nextY, nextX, 1});
				}
				else if (map[nextY][nextX] == 0 && visited[nextY][nextX][isBroken]==0){
					visited[nextY][nextX][isBroken] = visited[nowY][nowX][isBroken]+1;
					q.push({nextY, nextX, isBroken});
				}
			}
		}
	}
	return -1;
}
