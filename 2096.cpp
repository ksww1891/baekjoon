#include<iostream>
#include<algorithm>
using namespace std;

int plate[100001][3] = {0, };
int dpMin[3];
int dpMax[3] = {0, };

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> plate[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        dpMin[i] = dpMax[i] = plate[0][i];
    }

    for(int i = 1; i < n; i++){
        int M1 = plate[i][0] + max(dpMax[0], dpMax[1]);
        int M2 = plate[i][1] + max(dpMax[0], max(dpMax[1], dpMax[2]));
        int M3 = plate[i][2] + max(dpMax[1], dpMax[2]);
        int N1 = plate[i][0] + min(dpMin[0], dpMin[1]);
        int N2 = plate[i][1] + min(dpMin[0], min(dpMin[1], dpMin[2]));
        int N3 = plate[i][2] + min(dpMin[1], dpMin[2]);
        dpMax[0] = M1;
        dpMax[1] = M2;
        dpMax[2] = M3;
        dpMin[0] = N1;
        dpMin[1] = N2;
        dpMin[2] = N3;
    }
    cout << max(dpMax[0], max(dpMax[1], dpMax[2])) << ' ' << min(dpMin[0], min(dpMin[1], dpMin[2]));
}