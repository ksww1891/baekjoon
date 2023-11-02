#include<iostream>
#include<vector>
using namespace std;

vector<long long>v;


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	int start = 0;
	int end = n-1;
	int answer = abs(v[0] + v[n-1]);
	pair<int, int>answerPair = {0, n-1};
	while(start < end){
		long long answerTmp = v[start] + v[end];
		answer = min(answer, (int)abs(answerTmp));
		if(answer == (int)abs(answerTmp)){
			answerPair = {start, end};
		}
		if(answerTmp > 0){
			end--;
		}
		else {
			start++;
		}
	}
	cout << v[answerPair.first] << ' ' << v[answerPair.second];
}