#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void a(int y, int x);
void b(int y, int x);
void c(int y, int x);
void d(int y, int x);
void e(int y, int x);
vector<int>v;
int n, m;
int graph[501][501] = {0, };

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    //입력
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a(i, j);
            b(i, j);
            c(i, j);
            d(i, j);
            e(i, j);
        }
    }
    cout << *max_element(v.begin(), v.end());
}

void a(int y, int x){
    if(y+3 <= n)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y+2][x]+graph[y+3][x]);
    if(x+3 <= m)
        v.push_back(graph[y][x]+graph[y][x+1]+graph[y][x+2]+graph[y][x+3]);
    if(y-3 >= 1)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y-2][x]+graph[y-3][x]);
    if(x-3 >= 1)
        v.push_back(graph[y][x]+graph[y][x-1]+graph[y][x-2]+graph[y][x-3]);
    return;
}
void b(int y, int x){
    if(y+1 <= m && x+1 <= n)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y][x+1]+graph[y+1][x+1]);
    if(y-1 >= 1 && x+1 <= n)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y][x+1]+graph[y-1][x+1]);
    if(y+1 <= m && x-1 >= 1)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y][x-1]+graph[y+1][x-1]);
    if(y-1 >= 1 && x-1 >= 1)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y][x-1]+graph[y-1][x-1]);
}
void c(int y, int x){
    if(y+2 <= n && x+1<= m)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y+2][x]+graph[y+2][x+1]);
    if(y+2 <= n && x-1 >= 1)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y+2][x]+graph[y+2][x-1]);
    if(y+1 <= n && x-2 >= 1)
        v.push_back(graph[y][x]+graph[y][x-1]+graph[y][x-2]+graph[y+1][x-2]);
    if(y-1 >= 1 && x-2 >= 1)
        v.push_back(graph[y][x]+graph[y][x-1]+graph[y][x-2]+graph[y-1][x-2]);
    if(y-2 >= 1 && x+1 <= m)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y-2][x]+graph[y-2][x+1]);
    if(y-2 >= 1 && x-1 >= 1)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y-2][x]+graph[y-2][x-1]);
    if(y+1 <= n && x+2 <= m)
        v.push_back(graph[y][x]+graph[y][x+1]+graph[y][x+2]+graph[y+1][x+2]);
    if(y-1 >= 1 && x+2 <= m)
        v.push_back(graph[y][x]+graph[y][x+1]+graph[y][x+2]+graph[y-1][x+2]);
}
void d(int y, int x){
    if(y+2<=n && x+1 <=m)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y+1][x+1]+graph[y+2][x+1]);
    if(y+2<=n && x-1 >= 1)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y+1][x-1]+graph[y+2][x-1]);
    if(y+1 <= n && x-2 >= 1)
        v.push_back(graph[y][x]+graph[y][x-1]+graph[y+1][x-1]+graph[y+1][x-2]);
    if(y-1 >= 1 && x-2 >= 1)
        v.push_back(graph[y][x]+graph[y][x-1]+graph[y-1][x-1]+graph[y-1][x-2]);
    if(y-2 >=1 && x-1 >=1)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y-1][x-1]+graph[y-2][x-1]);
    if(y-2 >=1 && x+1 <= m)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y-1][x+1]+graph[y-2][x+1]);
    if(y+1 <= n && x+2 <= m)
        v.push_back(graph[y][x]+graph[y][x+1]+graph[y+1][x+1]+graph[y+1][x+2]);
    if(y-1 >= 1 && x+2 <= m)
        v.push_back(graph[y][x]+graph[y][x+1]+graph[y-1][x+1]+graph[y-1][x+2]);
}
void e(int y, int x){
    if(x+2 <= m && y+1 <= n)
        v.push_back(graph[y][x]+graph[y][x+1]+graph[y][x+2]+graph[y+1][x+1]);
    if(y-1 >= 1 && x+2 <= m)
        v.push_back(graph[y][x]+graph[y][x+1]+graph[y][x+2]+graph[y-1][x+1]);
    if(y+2 <= n && x+1 <= m)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y+1][x+1]+graph[y+2][x]);
    if(y+2 <= n && x-1 >= 1)
        v.push_back(graph[y][x]+graph[y+1][x]+graph[y+1][x-1]+graph[y+2][x]);
    if(y+1 <= n && x-2 >= 1)
        v.push_back(graph[y][x]+graph[y][x-1]+graph[y][x-2]+graph[y+1][x-1]);
    if(y-1 >= 1 && x-2 >= 1)
        v.push_back(graph[y][x]+graph[y][x-1]+graph[y-1][x-1]+graph[y][x-2]);
    if(y-2 >= 1 && x+1 <=m)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y-1][x+1]+graph[y-2][x]);
    if(y-2 >=1 && x-1 >= 1)
        v.push_back(graph[y][x]+graph[y-1][x]+graph[y-1][x-1]+graph[y-2][x]);
}