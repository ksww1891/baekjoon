#include<iostream>

using namespace std;

int student[1001] = {0, };

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, tmp;
    int answer = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        student[tmp]++;
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1001; j++)
            if(student[j] != 0){
                answer++;
                student[j]--;
            }
    }
    cout << answer;
}