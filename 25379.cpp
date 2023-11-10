#include<iostream>
#include<vector>
using namespace std;

vector<int>arr;
int odd, even;
int n, answer;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int tmp;
    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        tmp %= 2;
        arr.push_back(tmp);
        if(tmp)odd++;
        else even++;
    }
    int leftOddAnswer = 0, leftEvenAnswer = 0;
    for(int i = 0 ; i < n; i++){
        if(arr[i]){
            if(i >= odd) leftOddAnswer += i - odd;
            if(i < even) leftEvenAnswer += even - i;
        }
        else{
            if(i < odd) leftOddAnswer += odd - i;
            if(i >= even) leftEvenAnswer += i - even;
        }
    }
    cout << min(leftEvenAnswer, leftOddAnswer);
}