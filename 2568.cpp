#include<iostream>
#include<vector>
#define INF -987654321
using namespace std;

int n, maxIdx;
int l[500001];
int p[500001];
int answer[500001];
vector<int>tree;
vector<int>treeIdx;

int find(int num){
    int s = 1, e = tree.size();
    int mid;
    while(s < e){
        mid = (s + e)/2;
        if(tree[mid] >= num){
            e = mid;
        }
        else s = mid + 1;
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < 500001; i++){
        l[i] = -1;
    }
    for(int i = 1; i <= n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        l[tmp1] = tmp2;
        maxIdx = max(maxIdx, tmp1);
    }
    tree.push_back(INF);
    treeIdx.push_back(0);
    for(int i = 1; i < 500001; i++){
        if(l[i] == -1)continue;
        if(l[i] > tree.back()){
            tree.push_back(l[i]);
            p[i] = treeIdx.back();
            treeIdx.push_back(i);
        }
        else {
            int idx = find(l[i]);
            tree[idx] = l[i];
            p[i] = treeIdx[idx-1];
            treeIdx[idx] = i;
        }
    }
    cout << n - (tree.size()-1) << '\n';

    vector<int>survive;
    int now = treeIdx.back();
    while(now != 0){
        survive.push_back(now);
        now = p[now];
    }
    

    for(int i = 0; i < survive.size(); i++){
        answer[survive[i]] = 1;
    }
    for(int i = 1; i <= maxIdx; i++){
        if(l[i] == -1)continue;
        if(answer[i] == 0){
            cout << i << '\n';
        }
    }
}