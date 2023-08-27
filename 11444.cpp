#include<iostream>
#include<unordered_map>
using namespace std;

long long fibo(long long a);
unordered_map<long long, long long>memo;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long n;
    cin >> n;
    cout << fibo(n);
}
long long fibo(long long a){
    if(a==0)return 0;
    if(a==1)return 1;
    if(a==2)return 1;
    if(memo.count(a)>0)return memo[a];
    if((a%2)==1){
        long long tmp1 = fibo(a/2);
        long long tmp2 = fibo((a/2) + 1);
        memo[a]=(((tmp1%1000000007)*(tmp1%1000000007))%1000000007 + ((tmp2%1000000007)*(tmp2%1000000007))%1000000007)%1000000007;
        return memo[a];
    }
    else {
        long long tmp1 = fibo((a/2)+1)%1000000007;
        long long tmp2 = fibo((a/2)-1)%1000000007;
        long long tmp3 = fibo(a/2)%1000000007;
        memo[a] = (((tmp1+tmp2)%1000000007)*(tmp3%1000000007))%1000000007;
        return memo[a];
    }
}