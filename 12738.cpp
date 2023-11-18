#include<iostream>
#include<vector>

using namespace std;

vector<int>v;
vector<int>answer;
int n;

int binaryFunction(int num){
    int s = 0, e = answer.size()-1;
    int mid;
    while(s < e){
        mid = (s + e)/2;
        if((answer[mid] >= num)){
            e = mid;
        }
        else {
            s = mid+1;
        }
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int tmp;
    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    answer.push_back(v[0]);
    for(int i = 1; i < n; i++){
        if(v[i] > answer.back()){
            answer.push_back(v[i]);
        }
        else if(v[i] < answer.back()){
            answer[binaryFunction(v[i])] = v[i];
        }
    }
    cout << answer.size();
}