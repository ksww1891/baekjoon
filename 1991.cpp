#include<iostream>
#include<stack>
using namespace std;

int n;
char tree[256][2] = {0, };

void input();
void pre();
void in();
void post();

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    input();
    pre();
    cout << '\n';
    in();
    cout << '\n';
    post();
}

void input(){
    cin >> n;
    char tmp, tmp1, tmp2;
    for(int i = 0; i < n; i++){
        cin >> tmp >> tmp1 >> tmp2;
        if(tmp1 != '.'){
            tree[tmp][0] = tmp1;
        }
        if(tmp2 != '.'){
            tree[tmp][1] = tmp2;
        }
    }
}

void pre(){
    bool visited[256] = {0, };
    stack<int>s;
    cout << 'A';
    visited['A'] = 1;
    s.push('A');
    while(!s.empty()){
        if(visited[tree[s.top()][0]] == 0 && tree[s.top()][0] != 0){
            visited[tree[s.top()][0]] = 1;
            cout << tree[s.top()][0];
            s.push(tree[s.top()][0]);
            continue;
        }
        if(visited[tree[s.top()][1]] == 0 && tree[s.top()][1] != 0){
            visited[tree[s.top()][1]] = 1;
            cout << tree[s.top()][1];
            s.push(tree[s.top()][1]);
            continue;
        }
        s.pop();
    }
}

void in(){
    bool visited[256] = {0, };
    stack<int>s;
    visited['A'] = 1;
    s.push('A');
    while(!s.empty()){
        if(visited[tree[s.top()][0]] == 0 && tree[s.top()][0] != 0){
            visited[tree[s.top()][0]] = 1;
            s.push(tree[s.top()][0]);
            continue;
        }
        if(visited[tree[s.top()][1]] == 0){
            cout << (char)s.top();
            if(tree[s.top()][1] != 0){
                visited[tree[s.top()][1]] = 1;
                s.push(tree[s.top()][1]);
                continue;
            }
        }
        s.pop();
    }
}

void post(){
    bool visited[256] = {0, };
    stack<int>s;
    visited['A'] = 1;
    s.push('A');
    while(!s.empty()){
        if(visited[tree[s.top()][0]] == 0 && tree[s.top()][0] != 0){
            visited[tree[s.top()][0]] = 1;
            s.push(tree[s.top()][0]);
            continue;
        }
        if(visited[tree[s.top()][1]] == 0 && tree[s.top()][1] != 0){
            visited[tree[s.top()][1]] = 1;
            s.push(tree[s.top()][1]);
            continue;
        }
        cout << (char)s.top();
        s.pop();
    }
}