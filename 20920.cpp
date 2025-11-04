#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

unordered_map<string, int>map;
vector<string>voca;

bool compare(string a, string b){
    if(map[a] == map[b]){
        if(a.size() == b.size()){
            return a < b;
        }
        return a.size() > b.size();
    }
    return map[a] > map[b];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        if(input.length() >= m){
            
            if(map.find(input) != map.end()){
                map[input]++;
            }
            else {
                map.insert({input, 1});
                voca.push_back(input);
            }
        }
    }
    sort(voca.begin(), voca.end(), compare);
    for(int i = 0; i < voca.size(); i++){
        cout << voca[i] << '\n';
    }
}