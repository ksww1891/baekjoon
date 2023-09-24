#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int arr[9];
vector<int>numbers;

void recursive(int cnt, int lastN){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = lastN; i < numbers.size(); i++){
        arr[cnt] = numbers[i];
        recursive(cnt+1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n>> m;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        bool possible = 1;
        for(int j = i-1; j>= 0; j--){
            if(numbers[j] == tmp)
                possible = 0;
        }
        if(possible)numbers.push_back(tmp);

    }
    sort(numbers.begin(), numbers.end());
    recursive(0, 0);
}