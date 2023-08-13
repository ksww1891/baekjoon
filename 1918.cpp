#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

string input;
void solving(int start, int end);
int whereBracket(int start);

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> input;
    solving(0, (int)input.size());
    return 0;
}

void solving(int start, int end){
    stack<char>s;
    for(int i = start; i < end; i++){
        if(input[i]=='('){
            int tmp = whereBracket(i+1);
            solving(i+1, tmp);
            i = tmp-1;
        }
        if(input[i] >= 'A' && input[i] <= 'Z')
            cout << input[i];
        else if((input[i] == '+' || input[i] == '-')){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            s.push(input[i]);
        }
        else if(input[i] == '*' || input[i] == '/'){
            if(!s.empty()){
                if(s.top() == '*' || s.top() == '/'){
                    cout << s.top();
                    s.pop();
                }
            }
            s.push(input[i]);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

int whereBracket(int start){
    int a = 1;
    for(int i = start; i < input.size(); i++){
        if(input[i] == ')'){
            a--;
            if(a==0) return i+1;
        }
        if(input[i] == '(')
            a++;
    }
}