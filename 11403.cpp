#include<iostream>
#include<queue>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    bool graph[101][101] = {0, };
    bool answer[101][101] = {0, };

    //입력
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    //bfs
    for(int i = 0; i < n; i++){
        bool visited[101] = {0, };
        queue<int>s;
        s.push(i);
        while(!s.empty()){
            for(int j = 0; j < n; j++){
                if(graph[s.front()][j] && !visited[j]){
                    visited[j] = 1;
                    answer[i][j] = 1;
                    s.push(j);
                }
            }
            s.pop();
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << answer[i][j] << ' ';
        }
        cout <<'\n';
    }
}