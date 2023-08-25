#include<iostream>
#include<string>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    string a, b, c;
    int answer;
    cin >> a >> b >> c;
    if(a[0] != 'F' && a[0] != 'B')
        answer = stoi(a)+3;
    else if(b[0] != 'F' && b[0] != 'B')
        answer = stoi(b)+2;
    else if(c[0] != 'F' && c[0] != 'B')
        answer = stoi(c)+1;
    if(answer % 15 == 0){
        cout << "FizzBuzz";
        return 0;
    }
    if(answer % 5 == 0){
        cout << "Buzz";
        return 0;
    }
    if(answer % 3 == 0){
        cout << "Fizz";
        return 0;
    }
    cout << answer;
}


