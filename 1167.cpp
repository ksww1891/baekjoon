#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int visited[100001] = {0, };
//<연결된 노드 번호, 거리>
vector<pair<int, int>>edge[100001];
int node[100001] = {0, };
int answer = 0;
queue<int>q;

void bfs();

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int v, tmp1, tmp2, tmp3, cnt;
    cin >> v;

    //input
    for (int i = 1; i <= v; i++){
        cnt = 0;
        cin >> tmp1;
        while(1){
            cin >> tmp2;
            if(tmp2 == -1) break;
            cnt++;
            cin >> tmp3;
            edge[tmp1].push_back({tmp2, tmp3});
        }
        //제일 끝 노드들 큐에 push
        if(cnt == 1) {
            //visited[tmp1]=1;
            q.push(tmp1);
        }
    }
    bfs();
    cout << answer;
    return 0;
}

void bfs(){
    while(!q.empty()){
        visited[q.front()] ++;
        //cout << q.front() << ' ';
        for(int i = 0; i < edge[q.front()].size(); i++){
            //cout <<  edge[edge[q.front()][i].first].size()<< ' ' << visited[edge[q.front()][i].first] << ' ' <<(int)(edge[edge[q.front()][i].first].size()) - (visited[edge[q.front()][i].first])<< "  ";
            if((int)edge[edge[q.front()][i].first].size()-visited[edge[q.front()][i].first] >= 1){
                answer = max(node[edge[q.front()][i].first]+node[q.front()] + edge[q.front()][i].second, answer);
                node[edge[q.front()][i].first] = max(node[edge[q.front()][i].first], node[q.front()] + edge[q.front()][i].second);
                visited[edge[q.front()][i].first]++;
                if((int)edge[edge[q.front()][i].first].size()-visited[edge[q.front()][i].first]==1) q.push(edge[q.front()][i].first);
            }
            /*if(edge[edge[q.front()][i].first].size()-visited[edge[q.front()][i].first] == 1){
                answer = max(node[edge[q.front()][i].first]+node[q.front()] + edge[q.front()][i].second, answer);
                node[edge[q.front()][i].first] = max(node[edge[q.front()][i].first], node[q.front()] + edge[q.front()][i].second);
                //visited[edge[q.front()][i].first]++;
                q.push(edge[q.front()][i].first);
            }
        */}
        /*for(int i = 1; i < 6; i++){
            cout << node[i] << ' ';
        }
        cout << ' ';
        cout << answer << '\n';*/
        q.pop();
        
    }
}



/*if(visited[edge[nodeNum][i].first] < edge[edge[nodeNum][i].first].size()){
            visited[edge[nodeNum][i].first]++;
            dfs(edge[nodeNum][i].first); 
            answer = max(node[edge[nodeNum][i].first]+node[nodeNum] + edge[nodeNum][i].second, answer);
            node[edge[nodeNum][i].first] = max(node[edge[nodeNum][i].first], node[nodeNum] + edge[nodeNum][i].second);
        }*/