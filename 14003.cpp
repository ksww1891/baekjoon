#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define INF -1000000001
using namespace std;

int n, last;
int arr[1000002];
int parents[1000002];
vector<int>v;
vector<int>v_idx;

int binaryFunction(int num){
    int s = 1, e = v.size();
    int mid;
    while(s < e){
        mid = (s + e)/2;
        if((v[mid] >= num)){
            e = mid;
        }
        else {
            s = mid+1;
        }
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	//시작 노드 넣기
	v.push_back(INF);
	v_idx.push_back(0);

	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		if(arr[i] > v.back()){
			v.push_back(arr[i]);
			parents[i] = v_idx.back();
			v_idx.push_back(i);
		}
		else{
			int idx = binaryFunction(arr[i]);
			v[idx] = arr[i];
			parents[i] = v_idx[idx-1];
			v_idx[idx] = i;
		}
		//cout << parents[i] << ' ';
	}

	//cout << '\n';
	stack<int>s;
	int now  = v_idx.back();
	while(now != 0){
		s.push(now);
		now = parents[now];
	}
	
	/*
	for(int i = 0; i < v_idx.size(); i++){
		cout << v_idx[i] << ' ';
	}*/
	//cout << '\n';
	cout << v.size()-1 << '\n';
	while(!s.empty()){
		cout << arr[s.top()] << ' ';
		s.pop();
	}
}