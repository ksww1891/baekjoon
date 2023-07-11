#include<iostream>
#include<queue>
using namespace std;

int input, target;



void convert(int a, int b);
int D(int a);
int S(int a);
int L(int a);
int R(int a);
long long bfs();

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> input >> target;
        long long answer;
        answer = bfs();
        char answering[5] = {0, 'D', 'S', 'L', 'R'};
        char realanswer[10000] = {0, };
        int i=0;
        //출력
        while(answer>0){
            realanswer[i] = answering[answer%10];
            answer /= 10;
            i++;
        }
        for(int j = i-1; j >=0; j--){
            cout <<realanswer[j];
        }
        cout << '\n';
    }
}
int D(int a){
    return (a*2)%10000;
}
int S(int a){
    if(a == 0)
        return 9999;
    return a-1;
}
int L(int a){
    int tmp = a/1000;
    a = (a*10)%10000;
    return a+tmp;
}
int R(int a){
    int tmp = a%10;
    a /= 10;
    return tmp*1000+a;
}
long long bfs(){
    queue<pair<long long, int>>q;
    bool visited[10000] = {0, };
    visited[input] = 1;
    q.push(make_pair(0, input));
    while(1){
        int tmp = q.front().second;
        int tmpDSLR[4] = {D(tmp), S(tmp), L(tmp), R(tmp)};
        for(int i = 0; i < 4; i++){
            if(tmpDSLR[i] == target)
                return (q.front().first)*10+i+1;
            else if(!visited[tmpDSLR[i]]){
                visited[tmpDSLR[i]] = 1;
                q.push(make_pair((q.front().first)*10+i+1, tmpDSLR[i]));     
            }
        }
        q.pop();
    }
}

