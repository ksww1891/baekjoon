#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int n, m;
vector<pair<int, int>>chicken;
vector<pair<int, int>>home;
int selectedChicken[14] = {0, };
void solving(int cnt, int start);
int answer = 987654321;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	int tmp;
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < n; j++){
			cin >> tmp;
			if(tmp == 1)
				home.push_back({i, j});
			else if(tmp == 2)
				chicken.push_back({i, j});
		}
	}
	solving(0, 0);
	cout << answer;
}

void solving(int cnt, int start){
	if(cnt == m){
		int chickenDist = 0;
		for(int i = 0; i < home.size(); i++){
			int tmp = 987654321;
			for(int j = 0; j < m; j++){
				tmp = min(tmp, abs(home[i].first - chicken[selectedChicken[j]].first) + abs(home[i].second - chicken[selectedChicken[j]].second));
			}
			chickenDist += tmp;
		}
		answer = min(answer, chickenDist);
	}
	for(int i = start; i < (int)chicken.size(); i++){
		selectedChicken[cnt] = i;
		solving(cnt+1, i+1);
	}
}