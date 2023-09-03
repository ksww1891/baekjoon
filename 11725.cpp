#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>graph[100001];
int answer[100001] = {0, };
int visited[100001] = {0, };
int n;
void input();
void bfs();

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    bfs();
    for(int i = 2; i <= n; i++){
        cout << answer[i] << '\n';
    }
}

void input(){
    cin>> n;
    int tmp1, tmp2;
    for(int i = 0; i < n-1; i++){
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
}

void bfs(){
    queue<int>q;
    visited[1] = 1;
    q.push(1);
    while(!q.empty()){
        int nowNode = q.front();
        q.pop();
        for(int i = 0; i < graph[nowNode].size(); i++){
            int nextNode = graph[nowNode][i];
            if(visited[nextNode] == 0){
                answer[nextNode] = nowNode;
                visited[nextNode] = 1;
                q.push(nextNode);
            }
        }
    }
}