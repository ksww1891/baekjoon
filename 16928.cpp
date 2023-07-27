#include<iostream>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

int n, m;
int tmp1, tmp2;
map<int, int>ladder;
map<int, int>snake;
map<int, int>:: iterator iter;
int answer = 0;
queue<pair<int, int>>q;
bool visited[101] = {0, };
int bfs();

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    //입력
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> tmp1 >> tmp2;
        ladder.insert(make_pair(tmp1, tmp2));
    }
    for(int i = 0; i < m; i++){
        cin >> tmp1 >> tmp2;
        snake.insert(make_pair(tmp1, tmp2));
    }
    cout << bfs();
}

int bfs(){
    q.push(make_pair(1,0));
    while(!q.empty()){
        answer++;
        for(int i = 1; i <= 6; i++){
            if(snake.find(q.front().first + i) != snake.end()){
                if(!visited[snake[q.front().first+i]]){
                    visited[snake[q.front().first+i]] = 1;
                    q.push(make_pair(snake[q.front().first+i], q.front().second+1));
                }
            }
            else if(ladder.find(q.front().first+i) != ladder.end()){
                if(ladder[q.front().first+i] == 100){
                    return q.front().second+1;
                }
                if(!visited[ladder[q.front().first+i]]){
                    visited[ladder[q.front().first+i]] = 1;
                    q.push(make_pair(ladder[q.front().first+i], q.front().second+1));
                }
            }
            else {
                if(q.front().first+i == 100)
                    return q.front().second+1;
                if(!visited[q.front().first+i] && q.front().first+i <100){
                    visited[q.front().first+i] = 1;
                    q.push(make_pair(q.front().first+i, q.front().second+1));
                }
            }
        }
        q.pop();
    }
}