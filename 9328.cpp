#include<iostream>
#include<string>
#include<queue>
using namespace std;

int t, h, w;
char map[101][101];
bool key[26];
int answer;
int isAddedKey;
int visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>>q;

void searchEntrance(){
	for(int i = 0; i < w; i++){
		if(map[0][i] == '.'){
			q.push({0, i});
			visited[0][i] = 1;
		}
		else if(map[0][i] <= 'Z' && map[0][i] >= 'A'){
			if(key[map[0][i]-'A'] == 1){
				map[0][i] = '.';
				q.push({0, i});
				visited[0][i] = 1;
			}
		}
		else if(map[0][i] <= 'z' && map[0][i] >= 'a'){
			key[map[0][i] - 'a'] = 1;
			map[0][i] = '.';
			q.push({0, i});
			visited[0][i] = 1;
		}
		else if(map[0][i] == '$'){
			map[0][i] = '.';
			answer++;
			visited[0][i] = 1;
			q.push({0, i});
		}
		if(map[h-1][i] == '.'){
			q.push({h-1, i});
			visited[h-1][i] = 1;
		}
		else if(map[h-1][i] <= 'Z' && map[h-1][i] >= 'A'){
			if(key[map[h-1][i]-'A'] == 1){
				map[h-1][i] = '.';
				q.push({h-1, i});
				visited[h-1][i] = 1;
			}
		}
		else if(map[h-1][i] <= 'z' && map[h-1][i] >= 'a'){
			key[map[h-1][i] - 'a'] = 1;
			map[h-1][i] = '.';
			q.push({h-1, i});
			visited[h-1][i] = 1;
		}
		else if(map[h-1][i] == '$'){
			map[h-1][i] = '.';
			answer++;
			visited[h-1][i] = 1;
			q.push({h-1, i});
		}
	}
	for(int i = 1; i < h-1; i++){
		if(map[i][0] == '.'){
			q.push({i, 0});
			visited[i][0] = 1;
		}
		else if(map[i][0] <= 'Z' && map[i][0] >= 'A'){
			if(key[map[i][0]-'A'] == 1){
				map[i][0] = '.';
				q.push({i, 0});
				visited[i][0] = 1;
			}
		}
		else if(map[i][0] <= 'z' && map[i][0] >= 'a'){
			key[map[i][0] - 'a'] = 1;
			isAddedKey++;
			map[i][0] = '.';
			q.push({i, 0});
			visited[i][0] = 1;
		}
		else if(map[i][0] == '$'){
			map[i][0] = '.';
			answer++;
			visited[i][0] = 1;
			q.push({i, 0});
		}
		if(map[i][w-1] == '.'){
			q.push({i, w-1});
			visited[i][w-1] = 1;
		}
		else if(map[i][w-1] <= 'Z' && map[i][w-1] >= 'A'){
			if(key[map[i][w-1]-'A'] == 1){
				map[i][w-1] = '.';
				q.push({i, w-1});
				visited[i][w-1] = 1;
			}
		}
		else if(map[i][w-1] <= 'z' && map[i][w-1] >= 'a'){
			key[map[i][w-1] - 'a'] = 1;
			map[i][w-1] = '.';
			isAddedKey++;
			q.push({i, w-1});
			visited[i][w-1] = 1;
		}
		else if(map[i][w-1] == '$'){
			map[i][w-1] = '.';
			answer++;
			visited[i][w-1] = 1;
			q.push({i, w-1});
		}
	}
}
void bfs(){
	isAddedKey = 1;
	while(isAddedKey != 0){
		isAddedKey = 0;
		for(int i = 0 ; i < h; i++){
			for(int j = 0 ; j < w; j++){
				visited[i][j] = 0;
			}
		}
		searchEntrance();
		while(!q.empty()){
			int nowY = q.front().first;
			int nowX = q.front().second;
			q.pop();
			for(int i = 0 ; i < 4; i++){
				int nextY = nowY + dy[i];
				int nextX = nowX + dx[i];
				if(nextY >= 0 && nextY < h && nextX >= 0 && nextX < w){
					if(visited[nextY][nextX] == 1)continue;
					if(map[nextY][nextX] == '*')continue;
					else if(map[nextY][nextX] >= 'A' && map[nextY][nextX] <= 'Z'){
						if(key[map[nextY][nextX] - 'A'] == 1){
							map[nextY][nextX] = '.';
							visited[nextY][nextX] = 1;
							q.push({nextY, nextX});
						}
					}
					else if(map[nextY][nextX] <= 'z' && map[nextY][nextX] >= 'a'){
						key[map[nextY][nextX] - 'a'] = 1;
						isAddedKey++;
						map[nextY][nextX] = '.';
						q.push({nextY, nextX});
					}
					else if(map[nextY][nextX] == '$'){
						answer++;
						map[nextY][nextX] = '.';
						visited[nextY][nextX] = 1;
						q.push({nextY, nextX});
					}
					else {
						visited[nextY][nextX] = 1;
						q.push({nextY, nextX});
					}
				}
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		//초기화
		cin >> h >> w;
		answer = 0;
		for(int i = 0 ; i < 101; i++){
			for(int j = 0; j < 101; j++){
				visited[i][j] = 0;
				map[i][j] = 0;
			}
		}
		for(int i = 0 ; i < 26; i++){
			key[i] = 0;
		}
		//입력
		for(int i = 0 ; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> map[i][j];
			}
		}
		string s;
		cin >> s;
		for(int i = 0 ; i < s.length(); i++){
			if(s[i] == '0')break;
			key[s[i] - 'a'] = 1;
		}
		
		//solving
		bfs();
		
		cout << answer << '\n';
	}
}