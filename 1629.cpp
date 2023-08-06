#include<iostream>

using namespace std;

long long a, c;
long long X(int target);

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long b;
    cin >> a >> b >> c;
    cout << X(b);
}

long long X(int target){
    if (target>1){
        long long cal = X(target/2);
        if(target%2){
            return (((cal * cal)%c)*a)%c;
        }
        else return (cal * cal)%c;
    }
    return a%c;
}