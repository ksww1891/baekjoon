#include<iostream>

using namespace std;

int arr[100001] = {0, };
int pSum[100001] = {0, };
int n, s;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int st = 0, en = 0;
	int tmp = 0;
	int answer = 100001;
	while(en <= n){
		if(tmp < s){
			tmp+=arr[en++];
		}
		else{
			answer = min(answer, en-st);
			tmp -= arr[st++];
		}			
	}
	if(answer == 100001){
		cout << 0;
		return 0;
	}
	cout << answer;
}