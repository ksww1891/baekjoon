#include<iostream>
#include<queue>
using namespace std;

int n, k;
int visited[100001] = {0, };
void bfs();
int answer = 0;
queue<pair<int, int>> q;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> k;
    q.push({n, 0});
    visited[n] = 1;
    bfs();
    cout << answer;
}

void bfs(){
    if(n == k){
        answer = 0;
        return;
    }
    while(!q.empty()){
        int nowLo = q.front().first;
        int time = q.front().second;
        q.pop();
        int location = nowLo;
        while(location*2 <= 100000){
            if(location == 0)break;
            location *= 2;
            if(location == k){
                answer = time;
                return;
            }
            if(visited[location] == 0){
                visited[location] = 1;
                q.push({location, time});
            }
        }
        if(nowLo-1 >= 0){
            if(nowLo-1 == k){
                answer = time + 1;
                return;
            }
            if(visited[nowLo-1] == 0){
                visited[nowLo-1] = 1;
                q.push({nowLo-1, time+1});
            }
        }
        if(nowLo+1 <= k){
            if(nowLo+1 == k){
                answer = time + 1;
                return;
            }
            if(visited[nowLo+1] == 0){
                visited[nowLo+1] = 1;
                q.push({nowLo+1, time+1});
            }
        }
    }
}