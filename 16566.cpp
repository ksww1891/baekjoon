#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
vector<int>card;
int parents[4000001];

int find(int x){
    if(parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
    }
    for(int i = 0; i <= n; i++){
        parents[i] = i;
    }
    sort(card.begin(), card.end());
    while(k--){
        int magicianCard;
        cin >> magicianCard;
        int drawCardIdx = upper_bound(card.begin(), card.end(), magicianCard)- card.begin();
        int findIdx = find(drawCardIdx);
        cout << card[findIdx] << '\n';
        parents[findIdx] = find(findIdx+1);
    }
}