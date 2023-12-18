#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<pair<double, double>>star;
vector<pair<double, pair<int, int>>>edge;
int n;
int p[101];
double answer;

int find (int x){
    if(p[x] == x)return x;
    else return p[x] = find(p[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    double x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        star.push_back({x, y});
        p[i] = i;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            double cost = sqrt((star[i].first - star[j].first)*(star[i].first - star[j].first)
                        + (star[i].second - star[j].second)*(star[i].second - star[j].second));
            edge.push_back({cost, {i, j}});
        }
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        int star1 = find(edge[i].second.first);
        int star2 = find(edge[i].second.second);
        if(star1 == star2)continue;
        p[star1] = star2;
        answer += edge[i].first;
    }
    cout << answer;
    return 0;
}