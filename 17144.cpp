#include<iostream>

using namespace std;

int map[51][51] = {0, };
pair<int, int>purifier[2];
int r, c, t;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
void solving(int lastTime);

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> r >> c >> t;
    int index = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> map[i][j];
            if(map[i][j] == -1){
                purifier[index] = {i, j};
                index++;
            }
        }
    }
    solving(t);
    int answer = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            answer += map[i][j];
        }
    }
    cout << answer+2;
}

void solving(int lastTime){
    if(lastTime == 0)return;
    int mapTmp[51][51] = {0, };
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(map[i][j] == -1 || map[i][j] == 0)continue;
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nextY = i + dy[k];
                int nextX = j + dx[k];
                if(nextY == purifier[0].first && nextX == 1)continue;
                if(nextY == purifier[1].first && nextX == 1)continue;
                if(nextY <= 0 || nextX <= 0 || nextY > r || nextX > c)continue;
                cnt++;
                mapTmp[nextY][nextX] += map[i][j]/5;
            }
            map[i][j] -= (map[i][j]/5) * cnt;
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            map[i][j] += mapTmp[i][j];
        }
    }
    for(int i = purifier[0].first-1; i > 1; i--)map[i][1] = map[i-1][1];
    for(int i = 1; i < c; i++)map[1][i] = map[1][i+1];
    for(int i = 1; i < purifier[0].first; i++)map[i][c] = map[i+1][c];
    for(int i = c; i > 2; i--)map[purifier[0].first][i] = map[purifier[0].first][i-1];
    map[purifier[0].first][2] = 0;
    for(int i = purifier[1].first + 1; i < r; i++)map[i][1] = map[i+1][1];
    for(int i = 1; i < c; i++)map[r][i] = map[r][i+1];
    for(int i = r; i > purifier[1].first; i--)map[i][c] = map[i-1][c];
    for(int i = c; i > 2; i--)map[purifier[1].first][i] = map[purifier[1].first][i-1];
    map[purifier[1].first][2] = 0;
    solving(lastTime-1);
}