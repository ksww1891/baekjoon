#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

vector<int>l;
vector<int>r;
vector<int>leftSum;
vector<int>rightSum;

bool compare(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n/2; i++){
        int tmp;
        cin >> tmp;
        l.push_back(tmp);
    }
    for(int i = 0; i < n-n/2; i++){
        int tmp;
        cin >> tmp;
        r.push_back(tmp);
    }
    for(int i = 0; i < (1 << n/2); i++){
        int tmp = 0;
        for(int j = 0; j < n/2; j++){
            if(i & (1 << j)){
                tmp += l[j];
            }
        }
        leftSum.push_back(tmp);
    }
    for(int i = 0; i < (1 << (n-n/2)); i++){
        int tmp = 0;
        for(int j = 0; j < n - n/2; j++){
            if(i & (1 << j)){
                tmp += r[j];
            }
        }
        rightSum.push_back(tmp);
    }
    sort(leftSum.begin(), leftSum.end());
    sort(rightSum.begin(), rightSum.end(), compare);
    long long int answer = 0;
    int idx1 = 0;
    int idx2 = 0;
    while(idx1 < (1 << n/2) && idx2 < (1 << n-n/2)){
        if(leftSum[idx1] + rightSum[idx2] == s){
            long long int tmp1 = 1, tmp2 = 1;
            idx1 ++;
            idx2 ++;
            while(idx1 < (1 << n/2) && leftSum[idx1] == leftSum[idx1-1]){
                idx1++;
                tmp1++;
            }
            while(idx2 < (1 << n-n/2) && rightSum[idx2] == rightSum[idx2-1]){
                idx2++;
                tmp2++;
            }
            answer += tmp1*tmp2;
        }
        else if(leftSum[idx1] + rightSum[idx2] < s){
            idx1++;
        }
        else idx2++;
    }
    if(s == 0)answer--;
    cout << answer;
}