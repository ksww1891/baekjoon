#include<iostream>
#include<queue>
using namespace std;

int n, k;
queue<pair<int, int>>q;
bool visited[100001] = {0, };
void bfs(); void howManyCases(int time);
int answer, cases;


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> k;
    bfs();
    cout << answer << '\n' << cases;
}   

void bfs(){
    if(n == k){
        answer = 0; cases = 1;
        return;
    }
    visited[n] = 1;
    q.push({n, 0});
    while(!q.empty()){
        int nowLo = q.front().first;
        int nowTime = q.front().second;
        q.pop();
        visited[nowLo] = 1;
        if(nowLo == k){
            cases = 1;
            answer = nowTime;
            howManyCases(nowTime);
            return;
        }
        if(nowLo*2 <= 100000 && nowLo != 0){
            if(visited[nowLo*2] == 0){
                q.push({nowLo*2, nowTime+1});
            }
        }
        if(nowLo+1 <= 100000){
            if(visited[nowLo+1] == 0){
                q.push({nowLo+1, nowTime+1});
            }
        }
        if(nowLo-1 >= 0){
            if(visited[nowLo-1] == 0){
                q.push({nowLo-1, nowTime+1});
            }
        }
    }
}

void howManyCases(int time){
    while(!q.empty()){
        int nowLo = q.front().first;
        int nowTime = q.front().second;
        q.pop();
        if(nowLo == k && nowTime == time)cases++;
    }
}

