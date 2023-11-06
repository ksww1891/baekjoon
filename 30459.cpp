#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, r;
vector<int>stake;
vector<int>width;
vector<int>pole;
int answer = -1;

void binarySearch(int height){
    int s = 0;
    int e = width.size()-1;
    int mid, area;
    while(e >= s){
        mid = (e+s)/2;
        area = width[mid]*height;
        if(area > r){
            e = mid-1;
        }
        else{
            answer = max(answer, area);
            s = mid+1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m >> r;
    r *= 2;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        stake.push_back(tmp);
    }
    for(int i = 0; i < m; i++){
        cin >> tmp;
        pole.push_back(tmp);
    }
    sort(stake.begin(), stake.end());
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            width.push_back(stake[j] - stake[i]);
        }
    }
    sort(width.begin(), width.end());
    for(int i = 0; i < m; i++){
        binarySearch(pole[i]);
    }
    if(answer == -1)cout << -1;
    else {
        printf("%.1f", ((double)answer)/2);
    }
}