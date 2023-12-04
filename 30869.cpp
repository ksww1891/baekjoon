#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

int n, m, k;
vector<pair<pair<int,int>, int>>bus[501];

int dijkstra(){
    int d[501];
    priority_queue<pair<pair<int, int>, int>>pq;
    for(int i = 0; i <= n; i++){
        d[i] = INF;
    }
    pq.push({{0, 1}, k});
    d[1] = 0;
    while(!pq.empty()){
        int nowNode = pq.top().first.second;
        int nowTime = -pq.top().first.first;
        int nowK = pq.top().second;
        pq.pop();
        if(d[nowNode] < nowTime)continue;
        for(int i = 0; i < bus[nowNode].size(); i++){
            int nextNode = bus[nowNode][i].first.first;
            int nextTime;
            if(nowTime % bus[nowNode][i].second == 0){
                //배차시간 맞아서 바로 출발
                nextTime = nowTime + bus[nowNode][i].first.second;
                if(d[nextNode] > nextTime){
                    d[nextNode] = nextTime;
                    pq.push({{-nextTime, nextNode}, nowK});
                }
            }
            else{
                //배차시간 기다리고 출발
                nextTime = nowTime + bus[nowNode][i].first.second + bus[nowNode][i].second - nowTime%bus[nowNode][i].second;
                if(d[nextNode] > nextTime){
                    d[nextNode] = nextTime;
                    pq.push({{-nextTime, nextNode}, nowK});
                }
                //빨리 기다리기 사용
                if(nowK > 0){
                    int useKtime = nowTime + bus[nowNode][i].first.second;
                    if(d[nextNode] > useKtime){
                        d[nextNode] = useKtime;
                        pq.push({{-useKtime, nextNode}, nowK-1});
                    }
                }
            }
        }
    }
    if(d[n] == INF)return -1;
    else return d[n];
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int s, e, t , g;
        cin >> s >> e >> t >> g;
        bus[s].push_back({{e,t}, g});
    }
    cout << dijkstra();
}