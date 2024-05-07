#include<iostream>
#include<string>

using namespace std;

string word;
int x;

string rot(string a){
    string tmp1 = a;
    int idx = 1;
    for(int i = 2; i < a.size(); i+=2){
        tmp1[i] = a[idx++];
    }
    idx = a.size()-1;
    for(int i = 1; i < a.size(); i+=2){
        tmp1[i] = a[idx--];
    }
    return tmp1;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> x >> word;
    string tmp = word;
    int cnt = 1;
    tmp = rot(tmp);
    while(word != tmp){
        cnt++;
        tmp = rot(tmp);
    }
    for(int i = 0 ; i < cnt - x%cnt; i++){
        word = rot(word);
    }
    cout << word;
}