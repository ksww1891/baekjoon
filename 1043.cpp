#include<iostream>

using namespace std;

int peopleNum, partyNum, answer = 0;
int people[52] = {0, };
int knowingPeople[52] = {0, };
int knowingPeopleNum = 0;
int party[52][52] = {0, };
int partyPeopleNum[52] = {0, };

void merge(int x, int y);//y의 루트노드를 x,의루트노드로 바꿈
int find(int x);//x의 루트노드 찾기

int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin >> peopleNum >> partyNum;
    cin >> knowingPeopleNum;
    for(int i = 1; i <= peopleNum; i++){
        people[i] = i;
    }
    //진실을 아는 사람 입력
    for (int i = 0; i < knowingPeopleNum; i++){
        cin >> knowingPeople[i];
    }

    //각 파티별 참석하는 사람 입력
    for (int i = 1; i <= partyNum; i++){
        cin >> partyPeopleNum[i];
        for (int j = 1; j <= partyPeopleNum[i]; j++){
            cin >> party[i][j];
        }
    }

    //같은 이야기를 듣는 사람끼리 같은 집합
    for (int i = 1; i <= partyNum; i++){
        for(int j = 1; j < partyPeopleNum[i]; j++)
            merge(party[i][j], party[i][j+1]);
    }
    //
    for(int k = 0; k < knowingPeopleNum; k++){
        people[find(knowingPeople[k])] = -1;
    }
    for(int i = 1; i <= partyNum; i++){
        if(find(party[i][1]) != -1)
            answer++;
    }
    cout << answer;
    
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    people[y] = x;
}

int find(int x){
    if(people[x] == x)
        return x;
    if(people[x] == -1)
        return -1;
    else return find(people[x]);
}