#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int distance(string a, string b, string c);

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t, n;
    string tmp;
    
    cin >> t;
    while(t--){
        vector<string>mbti;
        vector<int>peopleDistance;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            mbti.push_back(tmp);
        }
        if(n > 32){
            cout << 0 << '\n';
            continue;
        }
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    peopleDistance.push_back(distance(mbti[i], mbti[j], mbti[k]));
                    //cout << distance(mbti[i], mbti[j], mbti[k]) <<' '<< mbti[i] <<' '<< mbti[j] << ' '<< mbti[k] << '\n';
                }
            }
        }
        sort(peopleDistance.begin(), peopleDistance.end());
        cout << peopleDistance[0] << '\n';
    }
}
    
int distance(string a, string b, string c){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        if(a[i] != b[i]){
            ret+=2;
        }
        else if(b[i] != c[i])
            ret+=2;
    }
    return ret;
}