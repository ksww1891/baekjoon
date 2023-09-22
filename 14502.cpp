#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int map[10][10];
int map_tmp[10][10];
void solving();
int answer = 0;
vector<pair<int, int>>virus;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2)virus.push_back({i, j});
        }
    }
    for(int i = 0; i < n*m-2; i++){
        if(map[i/m][i%m] != 0)continue;
        map[i/m][i%m] = 1;
        for(int j = i; j < n*m-1; j++){
            if(map[j/m][j%m] != 0)continue;
            map[j/m][j%m] = 1;
            for(int k = j; k < n*m; k++){
                if(map[k/m][k%m] != 0)continue;
                map[k/m][k%m] = 1;
                solving();
                map[k/m][k%m] = 0;
            }
            map[j/m][j%m] = 0;
        }
        map[i/m][i%m] = 0;
    }
    cout << answer;
}

void solving(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            map_tmp[i][j] = map[i][j];
        }
    }
    bool visited[10][10] = {0, };
    queue<pair<int, int>>q;
    for(int i = 0; i < virus.size(); i++){
        visited[virus[i].first][virus[i].second] = 1;
        q.push({virus[i].first, virus[i].second});
    }
    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m)continue;
            if(map_tmp[nextY][nextX] == 0 && visited[nextY][nextX] == 0){
                visited[nextY][nextX] = 1;
                map_tmp[nextY][nextX] = 2;
                q.push({nextY, nextX});
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map_tmp[i][j] == 0)cnt++;
        }
    }
    answer = max(answer, cnt);
}