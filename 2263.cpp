#include<iostream>
using namespace std;

int n;
int inOrder[100001];//왼쪽 > 부모 > 오른쪽
int inIndex[100001];
int postOrder[100001];//왼쪽 > 오른쪽 > 부모
//preOrder : 부모 > 왼쪽 > 오른쪽

void printPreOrder(int inS, int inE, int postS, int postE){
    if(inS > inE || postS > postE)return;
    cout << postOrder[postE] << ' ';
    printPreOrder(inS, inIndex[postOrder[postE]]-1, postS, postS + inIndex[postOrder[postE]]-inS-1);
    printPreOrder(inIndex[postOrder[postE]]+1, inE, postS + inIndex[postOrder[postE]] - inS, postE-1);
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> inOrder[i];
        inIndex[inOrder[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> postOrder[i];
    }
    printPreOrder(1, n, 1, n);
}