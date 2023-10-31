#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m;
vector<int>tallerList[32001];
int flag[32001];
queue<int>q;


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int tmp1, tmp2;
	for(int i = 0; i < m; i++){
		cin >> tmp1 >> tmp2;
		tallerList[tmp1].push_back(tmp2);
		flag[tmp2]++;
	}
	for(int i = 1; i <= n; i++){
		if(flag[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int nowPerson = q.front();
		q.pop();
		if(flag[nowPerson] == 0){
			cout << nowPerson << ' ';
		}
		for(int i = 0; i < (int)tallerList[nowPerson].size(); i++){
			int tallerPerson = tallerList[nowPerson][i];
			flag[tallerPerson]--;
			if(flag[tallerPerson] == 0){
				q.push(tallerPerson);
			}
		}
	}
}