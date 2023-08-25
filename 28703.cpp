#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    priority_queue<int, vector<int>, greater<int>>pq;
    int n;
    int tmp;
    int maxi = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        pq.push(tmp);
        maxi = max(maxi, tmp);
    }
    int max1 = maxi;
    int answer = maxi-pq.top();
    while(pq.top() <= max1){
        tmp = pq.top();
        pq.pop();
        maxi = max(maxi, 2*tmp);
        pq.push(2*tmp);
        int newAnswer = maxi-pq.top();
        answer = min(answer, newAnswer);
    }
    cout<<answer;
}
