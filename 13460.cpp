#include<iostream>
#include<string>
#include<queue>
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define piiii pair<pair<int, int>, pair<int,int>>
using namespace std;

char map[11][11];
int visited[11][11][11][11];
int n, m;
queue<piiii>q;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

  
int solving(){
    while(!q.empty()){
        piiii now = q.front();
        q.pop();
        //cout << now.ff << ' ' << now.fs << ' ' << now.sf << ' ' << now.ss << '\n';
        if(visited[now.ff][now.fs][now.sf][now.ss] > 10)return -1;
        for(int i = 0; i < 4; i++){
            piiii tmp = {{0, 0}, {0, 0}};
            piiii next = now;
            bool possible = 1, answerPossible = 0;
            int flag;
            if(i == 0){
                if(now.fs < now.ss)flag = 0;
                else flag = 1;
            }
            else if(i == 1){
                if(now.fs > now.ss)flag = 0;
                else flag = 1;
            }
            else if(i == 2){
                if(now.ff > now.sf)flag = 1;
                else flag = 0;
            }
            else{
                if(now.ff < now.sf)flag = 1;
                else flag = 0;
            }
            if(flag == 0){
                while(tmp!=next && possible){
                    tmp = next;
                    //빨간색 한칸 이동
                    if(map[next.ff+dy[i]][next.fs+dx[i]] == 'O'){
                        answerPossible = 1;
                        next.ff = 0;
                        next.fs = 0;
                    }
                    else if(map[next.ff+dy[i]][next.fs+dx[i]] == '.'){
                        next.ff += dy[i];
                        next.fs += dx[i];
                    }
                    //파란색 한칸 이동
                    if(map[next.sf+dy[i]][next.ss+dx[i]] == 'O')possible = 0;
                    else if(map[next.sf+dy[i]][next.ss+dx[i]] == '.' && !(next.sf + dy[i] == next.ff && next.ss + dx[i] == next.fs)){
                        next.sf += dy[i];
                        next.ss += dx[i];
                    }
                }
            }
            else if(flag == 1){
                while(tmp!=next && possible){
                    tmp = next;
                    //파란색 한칸 이동
                    if(map[next.sf+dy[i]][next.ss+dx[i]] == 'O')possible = 0;
                    else if(map[next.sf+dy[i]][next.ss+dx[i]] == '.'){
                        next.sf += dy[i];
                        next.ss += dx[i];
                    }
                    //빨간색 한칸 이동
                    if(map[next.ff+dy[i]][next.fs+dx[i]] == 'O'){
                        answerPossible = 1;
                        next.ff = 0;
                        next.fs = 0;
                    }
                    else if(map[next.ff+dy[i]][next.fs+dx[i]] == '.' && !(next.ff+dy[i] == next.sf && next.fs + dx[i] == next.ss)){
                        next.ff += dy[i];
                        next.fs += dx[i];
                    }
                    
                }
            }
            if(possible == 0)continue;
            if(answerPossible)return visited[now.ff][now.fs][now.sf][now.ss];
            if(visited[next.ff][next.fs][next.sf][next.ss] == 0){
                visited[next.ff][next.fs][next.sf][next.ss] = visited[now.ff][now.fs][now.sf][now.ss] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    piiii p;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            map[i][j] = str[j];
            if(map[i][j] == 'R'){
                p.first = {i, j};
                map[i][j] = '.';
            }
            else if(map[i][j] == 'B'){
                p.second = {i, j};
                map[i][j] = '.';
            }
        }
    }
    visited[p.ff][p.fs][p.sf][p.ss] = 1;
    q.push(p);
    int answer = solving();
    if(answer == -1){
        cout << -1;
        return 0;
    }
    else cout << answer;
}