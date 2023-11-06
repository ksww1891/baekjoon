#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    int alphabet[27] = {0, };
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++){
        alphabet[str[i] - 'a']++;
    }
    if(n%2 == 0){
        for(int i = 0; i < 27; i++){
            if(alphabet[i] % 2 > 0){
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";
    }
    else {
        char middle = str[(n/2)];
        if(alphabet[middle - 'a']%2 == 0){
            cout << "No";
            return 0;
        }
        
        for(int i = 0; i < 27; i++){
            if(i == (middle -'a'))continue;
            if(alphabet[i] % 2 > 0){
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";

    }
    
}