#include<iostream>
#include<stack>
#include<string>
using namespace std;

string EOD, str;
stack<char>s;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> str >> EOD;
	for(int i = str.length()-1; i >= 0; i--){
		if((str[i] == EOD[0])&&(s.size()+1 >= EOD.length())){
			stack<char>tmp;
			bool possible = 1;
			for(int j = 1; j < EOD.length(); j++){
				if(s.top() != EOD[j]){
					possible = 0;
				}
				tmp.push(s.top());
				s.pop();
			}
			if(possible == 0){
				while(!tmp.empty()){
					s.push(tmp.top());
					tmp.pop();
				}
				s.push(str[i]);
			}
		}
		else s.push(str[i]);
	}
	if(s.empty()){
		cout << "FRULA";
		return 0;
	}
	while(!s.empty()){
		cout<< s.top();
		s.pop();
	}

}