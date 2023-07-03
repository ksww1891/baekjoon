#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int map[27][27] = {0, };
int visited[27][27] = {0, };
int answer[170] = {0, };
int n, cnt;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>>q;

void input();
int BFS(int i, int j, int group);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	cnt = 0;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <=n; j++){
			if(visited[i][j] == 0 && map[i][j]>0){
				cnt++;
				answer[cnt-1] = BFS(i, j, cnt);
			}
		}
	}
	sort(answer, answer+cnt);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
		cout << answer[i] << '\n';
	return 0;
}

void input(){
	string tmp;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> tmp;
		for (int j = 0; j <= n-1; j++){
			map[i][j+1] = tmp[j]-'0';
		}
	}
}
int BFS(int i, int j, int group){
	visited[i][j] = 1;
	q.push(make_pair(i, j));
	int homeCnt = 1;
	while(!q.empty()){
		for (int i = 0; i < 4; i++){
			int x = q.front().second + dx[i];
			int y = q.front().first + dy[i];
			if(x >= 1 && x <= n && y >= 1 && y <= n){
				if(visited[y][x] == 0 && map[y][x]){
					visited[y][x] = 1;
					map[y][x] = group;
					q.push(make_pair(y, x));
					homeCnt++;
				}
			}
		}
		q.pop();
	}
	return homeCnt;
}