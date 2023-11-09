#include<iostream>
#include<string.h>
using namespace std;

int stu[100001];
bool visited[100001];
bool done[100001];
int n, answer;

void dfs(int nowNode){
    visited[nowNode] = 1;
    if(visited[stu[nowNode]] == 0){
        dfs(stu[nowNode]);
    }
    else if(done[stu[nowNode]] == 0){
        for(int i = stu[nowNode]; i != nowNode; i = stu[i])
            answer--;
        answer--;
    }
    done[nowNode] = 1;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(stu, 0, sizeof(stu));
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));
        cin >> n;
        answer = n;
        for(int i = 1 ; i <= n; i++){
            cin >> stu[i];
        }
        for(int i = 1 ; i <= n; i++){
            if(visited[i] == 0)
                dfs(i);
        }
        cout << answer << '\n';
    }
}