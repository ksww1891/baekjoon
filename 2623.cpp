#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<int>canNext[1001];
int flag[1001];
vector<int>answer;

void solving(){
	queue<int>q;
	for(int i = 1; i <= n; i++){
		if(flag[i] == 0){
			answer.push_back(i);
			q.push(i);
		}
	}
	while(!q.empty()){
		int nowSinger = q.front(); 
		q.pop();
		for(int i = 0 ; i < (int)canNext[nowSinger].size(); i++){
			if(flag[canNext[nowSinger][i]] == 0){
				continue;
			}
			flag[canNext[nowSinger][i]]--;
			if(flag[canNext[nowSinger][i]] == 0){
				answer.push_back(canNext[nowSinger][i]);
				q.push(canNext[nowSinger][i]);
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int tmp, f, tmp1;
		cin >> tmp >> f;
		for(int i = 1; i < tmp; i++){
			cin >> tmp1;
			flag[tmp1]++;
			canNext[f].push_back(tmp1);
			f = tmp1;
		}
	}
	solving();
	if((int)answer.size() == n){
		for(int i = 0; i < (int)answer.size(); i++){
			cout << answer[i]<< '\n'; 
		}
	}
	else cout << 0;
} 