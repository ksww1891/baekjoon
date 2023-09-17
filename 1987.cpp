#include<iostream>
#include<string>
#include<vector>

using namespace std;

int r, c;
char graph[21][21] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int answer = 0;

void dfs(int y, int x, bool usedAlphabet[], int dist){
	answer = max(answer, dist);
	for(int i = 0; i < 4; i++){
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if(nextY >= 0 && nextX >= 0 && nextY < r && nextX < c){
			if(usedAlphabet[graph[nextY][nextX] - 'A'] == 0){
				bool newUsedA[27];
				for(int j = 0; j < 27; j++){
					newUsedA[j] = usedAlphabet[j];
				}
				newUsedA[graph[nextY][nextX] - 'A'] = 1;
				dfs(nextY, nextX, newUsedA, dist+1);
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < c; j++){
			graph[i][j] = tmp[j];
		}
	}
	bool usedAlphabet[27] = {0, };
	usedAlphabet[graph[0][0]- 'A'] = 1;
	dfs(0, 0, usedAlphabet, 1);
	cout << answer;
}