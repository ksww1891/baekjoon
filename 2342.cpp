#include<iostream>
using namespace std;

int answer[2][5][5];
bool toggle;
int cost[5][5];
const int INF = 987654321;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                answer[i][j][k] = INF;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        cost[i][i] = 1;
        cost[0][i] = 2;
        cost[i][0] = 2;
    }
    cost[1][3] = cost[3][1] = cost[2][4] = cost[4][2] = 4;
    cost[1][2] = cost[1][4] = cost[2][1] = cost[2][3] = cost[3][2] = cost[3][4] = cost[4][1] = cost[4][3] = 3;

    int num;
    cin >> num;
    answer[0][num][0] = 2;
    answer[0][0][num] = 2;

    while(1){
        cin >> num;
        if(num == 0)break;
        toggle = !toggle;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(answer[!toggle][i][j] < INF){
                    //cout << i << j << ' ';
                    answer[toggle][num][j] = min(answer[toggle][num][j], answer[!toggle][i][j] + cost[i][num]);
                    answer[toggle][i][num] = min(answer[toggle][i][num], answer[!toggle][i][j] + cost[j][num]);
                }
            }
        }
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                answer[!toggle][i][j] = INF;
            }
        }
    }
    int ret = INF;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            ret = min(ret, answer[toggle][i][j]);
        }
    }
    cout << ret;
}