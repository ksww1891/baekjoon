#include<iostream>
#include<queue>
using namespace std;

long long int a, b;

void solving(){
    int answer = 0;
    while(b >= a){
        if(b == a){
            cout << answer+1;
            return;
        }
        if(b%10 == 1){
            b /= 10;
            answer++;
            continue;
        }
        if(b%2 == 0){
            b /= 2;
            answer++;
            continue;
        }
        if(b%2 == 1){
            break;
        }
    }
    cout << -1;
    return;        
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> a >> b;
    solving();
}