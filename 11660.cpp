#include<iostream>

using namespace std;

int n, m;
int graph[1025][1025] = {0, };
int rowSum[1025][1025]= {0, };

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
            rowSum[i][j] = rowSum[i][j-1]+graph[i][j];
        }
    }

    while(m--){
        int x1 , y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int answer = 0;
        for(int i = x1; i <= x2; i++){
            answer += rowSum[i][y2]-rowSum[i][y1-1];
        }
        cout << answer<<'\n';
    }
}