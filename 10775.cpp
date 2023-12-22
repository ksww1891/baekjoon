#include<iostream>
using namespace std;

int g, p, cnt;
int plane[100001];
int parents[100001];

int getIdx(int num){
    if(num == parents[num]){
        return num;
    }
    else return parents[num] = getIdx(parents[num]);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> g >> p;
    for(int i = 1; i <= p; i++){
        cin >> plane[i];
    }
    for(int i = 0; i <= g; i++){
        parents[i] = i;
    }
    for(int i = 1; i <= p; i++){
        int idx = getIdx(plane[i]);
        if(idx == 0)break;
        else{
            cnt++;
            parents[idx] = getIdx(idx-1);
        }
    }
    cout << cnt;
}
