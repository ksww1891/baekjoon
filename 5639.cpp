#include<iostream>

using namespace std;
int a = 0;
int arr[10001] = {0, };


void solving(int start, int end){
    if(start >= end)return;
	int newEnd = start+1;
    while(newEnd < end){
		if(arr[start] < arr[newEnd])break;
		newEnd++;
	}
	solving(start+1, newEnd);
	solving(newEnd, end);
    cout << arr[start] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tmp, idx = 0;
    while(cin >> tmp){
		arr[idx++] = tmp;
	}
    solving(0, idx);

}