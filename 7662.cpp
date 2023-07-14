#include<iostream>
#include<queue>
#include<set>
using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t, k, orderNum;
    char order;
    int isNotEmpty = 0;

    multiset<int>::iterator iter;

    cin>>t;
    for(int i = 0; i < t; i++){
        priority_queue<int,vector<int>, greater<int>>minq;
        priority_queue<int>maxq;
        multiset<int>map;
        isNotEmpty = 0;
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> order >> orderNum;
            if(order == 'I'){
                minq.push(orderNum);
                maxq.push(orderNum);
                map.insert(orderNum);
                isNotEmpty++;
            }
            else if(isNotEmpty > 0){
                if(orderNum < 0){
                    iter = map.find(minq.top());
                    while(1){
                        if(iter != map.end()){
                            break;
                        }
                        else{
                            minq.pop();
                            iter = map.find(minq.top());
                        }
                    }
                    map.erase(iter);
                    minq.pop();
                }
                else{
                    iter = map.find(maxq.top());
                    while(1){
                        if(iter != map.end()){
                            break;
                        }
                        else{
                            maxq.pop();
                            iter = map.find(maxq.top());
                        }
                    }
                    map.erase(iter);
                    maxq.pop();
                }
                isNotEmpty--;
            }
        }
        if(isNotEmpty==0){
            cout << "EMPTY" << '\n';
            continue;
        }
        while(1){
            iter = map.find(minq.top());
            if(iter != map.end()) break;
            else minq.pop();
        }
        while(1){
            iter = map.find(maxq.top());
            if(iter != map.end()) break;
            else maxq.pop();
        }
        cout << maxq.top() << ' ' << minq.top() << '\n';
    }
}