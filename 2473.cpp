#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int n;
vector<long long>v;
tuple<int, int, int>answer;
long long answerNum;
void solving(int now){
    int start = now+1; 
    int end = n-1;
    while(start < end){
        long long answerTmp = v[now] + v[start] + v[end];
        if(answerNum > abs(answerTmp)){
            answerNum = abs(answerTmp);
            answer = {now, start, end};
        }
        if(answerTmp < 0){
            start++;
        }
        else end--;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    answer = {0, 1, n-1};
    answerNum = abs(v[0] + v[1] + v[n-1]);
    for(int i = 0; i < n-2; i++){
        solving(i);
    }
    cout << v[get<0>(answer)] << ' ' << v[get<1>(answer)] << ' ' << v[get<2>(answer)];
}