#include<iostream>

using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    int answer[50001] = {0, };

    for(int i = 1; i*i <= 50000; i++){
        answer[i*i] = 1;
    }
    for(int i = 1; i*i <= 50000; i++){
        for(int j = 1; i*i+j*j <= 50000; j++){
            if(!answer[i*i+j*j])
                answer[i*i+j*j] = 2;
        }
    }
    for(int i = 1; i*i <= 50000; i++){
        for(int j = 1; i*i+j*j <= 50000; j++){
            for(int k = 1; i*i+j*j+k*k<=50000; k++){
                if(!answer[i*i+j*j+k*k])
                    answer[i*i+j*j+k*k] = 3;
            }
        }
    }
    if(!answer[n])
        cout << 4;
    else cout << answer[n];
}