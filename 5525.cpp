#include<iostream>
#include<string>
using namespace std;

int n, m;
int answerCnt = 0;
void plusAnswerCnt(int length);

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    bool isNextI = 1;
    int smallCnt = 0;
    string p;

    cin >> n >> m >> p;
    
    for (int i = 0; i < m-1; i++){
        //OI
        if(isNextI && p[i] == 'I'){
            smallCnt++;
            isNextI = 0;
            continue;
        }
        //II
        if(!isNextI && p[i] == 'I'){
            plusAnswerCnt((smallCnt-1)/2);
            smallCnt = 1;
            isNextI = 0;
            continue;
        }
        //OO
        if(isNextI && p[i] == 'O'){
            smallCnt--;
            plusAnswerCnt((smallCnt-1)/2);
            smallCnt=0;
            isNextI = 1;
            continue;
        }
        //IO
        if(!isNextI && p[i] == 'O'){
            smallCnt++;
            isNextI = 1;
            continue;
        }
    }
    //OI
    if(isNextI && p[m-1] == 'I'){
        smallCnt++;
        plusAnswerCnt((smallCnt-1)/2);
    }
    //II
    else if(!isNextI && p[m-1] == 'I'){
        plusAnswerCnt((smallCnt-1)/2);
    }
    //OO
    else if(isNextI && p[m-1] == 'O'){
        smallCnt--;
        plusAnswerCnt((smallCnt-1)/2);
    }
    //IO
    else if(!isNextI && p[m-1] == 'O'){
        plusAnswerCnt((smallCnt-1)/2);
    }
    cout << answerCnt;
}

void plusAnswerCnt(int length){
    if(n <= length)
        answerCnt += length-n+1;
    return;
}