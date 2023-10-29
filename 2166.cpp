#include<iostream>
#include<vector>

using namespace std;

int n;
vector<pair<double, double>>p;

int main(){
    cin >> n;
    double tmp1, tmp2;
    for(int i = 0; i < n; i++){
        cin >> tmp1 >> tmp2;
        p.push_back({tmp1, tmp2});
    }
    double answer = 0;
    for(int i = 1; i < n-1; i++){
        answer += (double)(p[0].first*p[i].second + p[i].first*p[i+1].second + p[i+1].first*p[0].second 
        - p[i].first * p[0].second - p[i+1].first * p[i].second - p[0].first * p[i+1].second)/2;
    }
    printf("%0.1lf", answer>=0?answer:-answer);
}   