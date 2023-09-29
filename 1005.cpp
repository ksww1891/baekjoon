#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int t, n, k, w;
int constructT[1001] = {0, };
int conditions[1001] = {0, };
int answer[1001] = {0, };
vector<int>nextBuild[1001];

void input();
int solving();

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> t;
	while(t--){
		input();
		cout << solving() << '\n';
	}
}

void input(){
	for(int i = 0; i <= n; i++){
		nextBuild[i].clear();
		conditions[i] = 0;
		answer[i] = 0;
	}
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> constructT[i];
	}
	int tmp1, tmp2;
	for(int i = 0; i < k; i++){
		cin >> tmp1 >> tmp2;
		nextBuild[tmp1].push_back(tmp2);
		conditions[tmp2]++;
	}
	cin >> w;
}

int solving(){
	queue<int>q;
	for(int i = 1; i <= n; i++){
		if(conditions[i] == 0){
			q.push(i);
			answer[i] = constructT[i];
		}
	}
	while(!q.empty()){
		int nowBuilding = q.front();
		q.pop();
		if(nowBuilding == w)return answer[nowBuilding];
		for(int i = 0; i < nextBuild[nowBuilding].size(); i++){
			int nextBuilding = nextBuild[nowBuilding][i];
			conditions[nextBuilding]--;
			answer[nextBuilding] = max(answer[nextBuilding], answer[nowBuilding]+constructT[nextBuilding]);
			if(conditions[nextBuilding] == 0){
				q.push(nextBuilding);
			}
		}
	}
	return answer[w];
}