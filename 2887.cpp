#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int n, minCost;
vector<pair<int, int>>planet[3];
vector<pair<int, pair<int, int>>>tunnel;
int p[100001];

int find(int x){
	if(p[x] == x)return x;
	return p[x] = find(p[x]);
}

bool isDiffGroup(int nodeA, int nodeB){
	nodeA = find(nodeA); nodeB = find(nodeB);
	if(nodeA == nodeB)return false;
	return true;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x, y, z;
	for(int i = 0 ; i < n; i++){
		cin >> x >> y >> z;
		planet[0].push_back({x, i});
		planet[1].push_back({y, i});
		planet[2].push_back({z, i});
		p[i] = i;
	}
	sort(planet[0].begin(), planet[0].end());
	sort(planet[1].begin(), planet[1].end());
	sort(planet[2].begin(), planet[2].end());
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < 3; j++){
			tunnel.push_back({abs(planet[j][i].first - planet[j][i+1].first), {planet[j][i].second, planet[j][i+1].second}});
		}
	}
	sort(tunnel.begin(), tunnel.end());
	int cnt = 0;
	for(int i = 0; i < tunnel.size(); i++){
		int planetA = tunnel[i].second.first;
		int planetB = tunnel[i].second.second;
		int nowCost = tunnel[i].first;
		if(!isDiffGroup(planetA, planetB))continue;
		cnt++;
		minCost += nowCost;
		p[find(planetB)] = find(planetA);
		if(cnt == n-1)break;
	}
	cout << minCost;
}