#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v, e;
void input();
void solving();
vector<pair<int, pair<int, int>>>link;
vector<int>p(10005, -1);
int answer = 0;
int cnt = 0;

int find(int x){
	if(p[x] < 0)return x;
	return p[x] = find(p[x]);
}

bool isDiffGroup(int nodeA, int nodeB){
	nodeA = find(nodeA); nodeB = find(nodeB);
	if(nodeA == nodeB)return false;
	if(p[nodeA] == p[nodeB])p[nodeA]--;
	if(p[nodeA] < p[nodeB])p[nodeB] = nodeA;
	else p[nodeA] = nodeB;
	return true;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solving();
	cout << answer;
}

void input(){                                                                 
	cin >> v >> e;
	int a, b, c;
	for(int i = 0; i < e; i++){
		cin >> a >> b >> c;
		link.push_back({c, {a, b}});
	}
}

void solving(){
	sort(link.begin(), link.end());
	for(int i = 0; i < e; i++){
		int cost = link[i].first;
		int nodeA = link[i].second.first;
		int nodeB = link[i].second.second;
		if(!isDiffGroup(nodeA, nodeB))continue;
		answer += cost;
		cnt++;
		if(cnt == v-1)break;
	}
}