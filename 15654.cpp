#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int>v;
int arr[9] = {0, };
bool used[9] = {0, };

void recursive(int cnt){
    if(cnt == m) {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }
    for(int i = 0; i < n; i++){
        if(used[i] == 0){
            used[i] = 1;
            arr[cnt] = v[i];
            recursive(cnt+1);
            used[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int tmp;
	for(int i = 0 ; i < n; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	recursive(0);
}

