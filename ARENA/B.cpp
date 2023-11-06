#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
long long int p;
vector<long long int>map[501];
bool answer = 1;

void input();
void solving(int baseNum);
int itemN[501] = {0, };

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    solving(0);
    cout << answer;
}

void input(){
    cin >> n >> m >> p;
    long long int tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tmp;
            if(tmp == -1)itemN[i]++;
            else map[i].push_back(tmp);
        }
        sort(map[i].begin(), map[i].end());
    }
}

void solving(int baseNum){
    if(baseNum == n)return;
    int j = 0;
    if(map[baseNum].size() == 0){
        while(itemN[baseNum]--){
        p *= 2;
        }
        solving(baseNum+1);
        return;
    }
    for(int i = 0; i < m; i++){
        if(p >= map[baseNum][j]){
            p += map[baseNum][j];
            j++;
            if(j == map[baseNum].size())break;
        }
        else if(p < map[baseNum][j]){
            if(itemN[baseNum] > 0){
                p *= 2;
                itemN[baseNum]--;
            }
            else {
                answer = 0;
                return;
            }
        }
    }
    while(itemN[baseNum]--){
        p *= 2;
    }
    solving(baseNum+1);
}