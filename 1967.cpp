#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, answer = 0, tmpNode = 0;
bool visited[10001] = {0, };
vector<pair<int, int>>node[10001];
void input();
void dfs(int currentNode, int currentLength);

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    visited[1] = true;
    dfs(1, 0);
    for(int i = 0 ; i < 10001; i++){
        visited[i] = false;
    }
    visited[tmpNode] = true;
    dfs(tmpNode, 0);
    cout << answer;
}

void input(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        node[tmp1].push_back({tmp2, tmp3});
        node[tmp2].push_back({tmp1, tmp3});
    }
}

void dfs(int currentNode, int currentLength){
    int cnt = 0;
    for(int i = 0; i < node[currentNode].size(); i++){
        if(!visited[node[currentNode][i].first]){
            cnt++;
            visited[node[currentNode][i].first] = true;
            dfs(node[currentNode][i].first, currentLength + node[currentNode][i].second);
        }
    }
    if(cnt == 0){
        if(answer < currentLength){
            answer = currentLength;
            tmpNode = currentNode;
            return;
        }
    }
}