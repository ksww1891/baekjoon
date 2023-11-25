#include<iostream>
#include<vector>
using namespace std;

int n;
bool num[4000001];
vector<int>pn;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    num[2] = 1;
    pn.push_back(2);
    for(int i = 3; i <= n; i+=2){
        if(num[i] == 0){
            pn.push_back(i);
            for(int j = i; j <= n; j+=i){
                num[j] = 1;
            }
        }
    }
    int s = 0, e = 0, answer = 0;
    int sum = pn[0];
    
    while(e < pn.size()){
        //cout << sum << ' ';
        if(sum > n){
            sum -= pn[s++];
        }
        else if(sum == n){
            //cout << pn[s] << ' ' << pn[e] << '\n';
            sum += pn[++e];
            answer++;
        }
        else if(sum < n){
            sum += pn[++e];
        }
        //cout << sum << '\n';
    }
    cout << answer;
}