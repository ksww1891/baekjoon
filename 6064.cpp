#include<iostream>

using namespace std;

int khaing(int m ,int n ,int x ,int y);
int findGcd(int a, int b);

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << khaing(m, n, x, y) << '\n';
    }
}

int khaing(int m ,int n ,int x ,int y){
    int gcd = findGcd(m, n);
    int lcm = (m/gcd)*(n/gcd)*gcd;
    if(m == 1 && n != 1){
        return y;
    }
    else if(n == 1 && m != 1){
        return x;
    }
    else if(m==1 & n==1){
        return 1;
    }
    else{
        for(int i = x; i <= lcm; i+=m){
            int ny = i%n;
            if(ny == 0)
                ny = n;
            if(ny == y)
                return i;
        }
    }
    return -1;
}

int findGcd(int a, int b){
    int c;
    while(b != 0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}