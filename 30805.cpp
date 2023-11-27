#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>answerS;
vector<pair<int, int>>arrA;
vector<pair<int, int>>arrB;
int n, m;

bool compare(pair<int, int>a, pair<int,int>b){{
    if(a.first == b.first){
        return a.second < b.second;
    }
    else return a.first > b.first;
}

}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arrA.push_back({tmp, i});
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        arrB.push_back({tmp, i});
    }
    sort(arrA.begin(), arrA.end(), compare);
    sort(arrB.begin(), arrB.end(), compare);
    int idx1 = 0, idx2 = 0;
    int idx1t = 0, idx2t = 0;
    while(idx1 < n && idx2 < m){
        if(arrA[idx1].second < idx1t){
            idx1++;
            continue;
        }
        if(arrB[idx2].second < idx2t){
            idx2++;
            continue;
        }
        if(arrA[idx1].first == arrB[idx2].first){
            idx1t = arrA[idx1].second;
            idx2t = arrB[idx2].second;
            answerS.push_back(arrA[idx1].first);
            idx1++;
            idx2++;
        }
        else if(arrA[idx1].first > arrB[idx2].first){
            idx1++;
        }
        else {
            idx2++;
        }
    }
    cout << answerS.size() << '\n';
    for(int i = 0; i < answerS.size(); i++){
        cout << answerS[i] << ' ';
    }
}