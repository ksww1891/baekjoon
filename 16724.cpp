#include<iostream>
using namespace std;

int n, m, answer;
char map[1001][1001];
int visited[1001][1001];
pair<int, int>parent[1001][1001];

pair<int, int> find(pair<int, int>a){
    if(parent[a.first][a.second] == a)return a;
    return parent[a.first][a.second] = find(parent[a.first][a.second]);
}

pair<int, int>next(int a, int b){
    if(map[a][b] == 'D'){
        return find({a+1, b});
    }
    else if(map[a][b] == 'L'){
        return find({a, b-1});
    }
    else if(map[a][b] == 'R'){
        return find({a, b+1});
    }
    return find({a-1, b});
}


void dfs(int a, int b){
    pair<int, int>nextLo = next(a, b);
    parent[a][b] = nextLo;
    if(visited[nextLo.first][nextLo.second] == 0){
        visited[nextLo.first][nextLo.second] = 1;
        dfs(nextLo.first, nextLo.second);
    }
    else if(visited[nextLo.first][nextLo.second] == 1){
        visited[nextLo.first][nextLo.second] = 2;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            parent[i][j] = {i, j};
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0){
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }
    pair<int, int>tmp = {-1, -1};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 2){
                answer++;
            }
        }
    }
    cout << answer;
}