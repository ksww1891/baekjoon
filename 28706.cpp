#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

vector<pair<pair<char, int>,pair<char, int>>>v;
void solving (int num, int turn);
int n;
bool isTrue = 0;
bool visited[200001][10] = {0, };

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 200001; i++){
            for(int j = 0; j < 10; j++){
                visited[i][j] = 0;
            }
        }
        v.clear();
        isTrue = 0;
        int tmp1, tmp2;
        char a, b;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a;
            cin >> tmp1;
            cin >> b;
            cin >> tmp2;
            v.push_back(make_pair(make_pair(a, tmp1), make_pair(b, tmp2)));
        }
        
        solving(1, 0);
        if(isTrue) cout << "LUCKY" << '\n';
        else cout << "UNLUCKY" << '\n';
    }
}

void solving(int num, int turn){
    if(turn == n){
        if(num%7 == 0) isTrue = 1;
        return;
    }
    if(v[turn].first.first == '*'){
        int tmp = (num*((v[turn].first.second)%7))%7;
        if(visited[turn][tmp] == 0){
            visited[turn][tmp] = 1;
            solving(tmp, turn+1);
        }
    }
    else {
        int tmp = (num+((v[turn].first.second)%7))%7;
        if(visited[turn][tmp] == 0){
            visited[turn][tmp] = 1;
            solving(tmp, turn+1);
        }
    }
    if(v[turn].second.first == '*'){
        int tmp = (num*((v[turn].second.second)%7))%7;
        if(visited[turn][tmp] == 0){
            visited[turn][tmp] = 1;
            solving(tmp, turn+1);
        }
    }
    else {
        int tmp = (num+((v[turn].second.second)%7))%7;
        if(visited[turn][tmp] == 0){
            visited[turn][tmp] = 1;
            solving(tmp, turn+1);
        }
    }
}