#include<iostream>
#include<queue>
using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, order;
    priority_queue<int>q;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> order;
        if(order>0){
            q.push(order);
        }
        else {
            if(q.empty())
                cout << '0' << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
}