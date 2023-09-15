#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, m;
vector<int>v;
vector<int>arr = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int lastArr[9] = {0, };
bool used[9] = {0, };
set<vector<int>>s;

void recursive(int cnt){
    if(cnt == m) {
        if(s.count(arr))return;
        else s.insert(arr);
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }
    for(int i = 0; i < v.size(); i++){
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
        int count = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == tmp)
            count++;
        }
		if(count < m) v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	recursive(0);
}

