#include<iostream>
#include<vector>
#define ppiipii pair<pair<int, int>, pair<int, int>>
#define pii pair<int, int>
using namespace std;

int n;
int p[3001];
int cnt[3001];
int answerCnt, maxCnt;
vector<ppiipii>l;

int findP(int a){
    if(p[a] == a)return a;
    else return p[a] = findP(p[a]);
}

int ccw(pii a, pii b, pii c){
    int ret = (a.first*b.second + b.first*c.second + c.first*a.second) - (a.second*b.first + b.second*c.first + c.second*a.first);
    if(ret > 0)return 1;
    else if(ret < 0)return -1;
    else return 0;
}

bool check(ppiipii l1, ppiipii l2){
    int abc = ccw(l1.first, l1.second, l2.first);
    int abd = ccw(l1.first, l1.second, l2.second);
    int cda = ccw(l2.first, l2.second, l1.first);
    int cdb = ccw(l2.first, l2.second, l1.second);
    //cout << abc << ' ' << abd << ' ' << cda << ' ' << cdb << '\n';
    if(abc * abd == 0 && cda * cdb == 0){
        pii tmp[4];
        tmp[0] = l1.first; tmp[1] = l1.second; tmp[2] = l2.first; tmp[3] = l2.second;
        if(tmp[0] > tmp[1])swap(tmp[0], tmp[1]); 
        if(tmp[2] > tmp[3])swap(tmp[2], tmp[3]);
        if(tmp[0] <= tmp[3] && tmp[1] >= tmp[2])return true;
        else return false;
    }
    else {
        if((abc*abd <= 0) && (cda*cdb <= 0)){
            return true;
        }
        else return false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        l.push_back({{x1, y1}, {x2, y2}});
        p[i] = i;
    }
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(findP(i) == findP(j)){
                continue;
            }
            if(check(l[i], l[j])){
                p[findP(j)] = i;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cnt[findP(i)]++;
    }
    for(int i = 0; i < n; i++){
        if(cnt[i] > 0){
            answerCnt++;
            maxCnt = max(maxCnt, cnt[i]);
        }
    }
    cout << answerCnt << '\n' << maxCnt;
}