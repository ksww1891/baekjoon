#include<iostream>
#include<string>
#include<map>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    int n;
    string tmp;
    map<string,int>whichclothes;
    map<string, int>::iterator iter;

    cin >> t;
    for(int i = 0; i < t; i++){
        map<string,int>whichclothes;
        int answer = 1;
        cin >> n;
        if (n == 0){
            cout << 0 << '\n';
            continue;
        }
        cin >> tmp >> tmp;
        whichclothes.insert(pair<string, int>(tmp, 1));
        for(int j = 1; j < n; j++){
            cin >> tmp >> tmp;
            if(whichclothes.find(tmp) != whichclothes.end()){
                whichclothes[tmp] += 1;
            }
            else {
                whichclothes.insert(pair<string, int>(tmp, 1));
            }
        }
        if(!whichclothes.empty()){
            for(iter = whichclothes.begin(); iter != whichclothes.end(); iter++){
                answer *= (*iter).second+1;
            }
        }
        cout << answer-1 << '\n';
    }
}