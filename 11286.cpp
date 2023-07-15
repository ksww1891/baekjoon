#include<iostream>
#include<queue>
using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, order;
    priority_queue<int>q;
    priority_queue<int, vector<int>, greater<int>>qq;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> order;
        if(order<0){
            q.push(order);
        }
        else if(order>0){
            qq.push(order);
        }
        else {
            if(q.empty()&&qq.empty())
                cout << '0' << '\n';
            else if(q.empty()&&!qq.empty()){
                cout << qq.top() << '\n';
                qq.pop();
            }
            else if(!q.empty() && qq.empty()){
                cout << q.top() << '\n';
                q.pop();
            }
            else {
                if((q.top())*(-1) <= qq.top()){
                    cout << q.top() << '\n';
                    q.pop();
                }
                else {
                    cout << qq.top() << '\n';
                    qq.pop();
                }
            }
        }
    }
}