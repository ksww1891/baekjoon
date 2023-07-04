#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t;
    string order;
    int arrlen;
    string tmp;
    int save = 0;

    cin >> t;

    while(t--){
        cin >> order >> arrlen >> tmp;
        vector<int>arr;
        bool iserror = 0;
        bool isFlip = 0;
        for(int i = 0; i < tmp.size(); i++){
            if(tmp[i] >= '0' && tmp[i] <= '9')
                save  = save*10 + tmp[i] - '0';
            if(tmp[i] == ','|| tmp[i] == ']'){
                if(save == 0)
                    continue;
                arr.push_back(save);
                save = 0;
            }
        }
        int start = 0;
        int end = arr.size()-1;
        //명령대로 배열 R or D 연산 수행
        for(int i = 0; i < order.size(); i++){
            if(order[i] == 'R'){
                if(!arr.empty())
                    isFlip = !isFlip;  
            }
            if(order[i] == 'D'){
                if(arr.empty() || start > end){
                    iserror = 1;
                }
                else{
                    if(!isFlip)
                        start++;
                    else
                        end--;
                }
            }
        }
        //출력
        if(!iserror){
            cout << '[';
            if(start <= end){
                if(!isFlip){
                    for(int i = start; i < end; i++)
                        cout << arr[i] << ',';
                    cout<< arr[end];
                }
                else{
                    for(int i = end; i > start; i--)
                        cout << arr[i] << ',';
                    cout << arr[start];
                }
            }
            cout << ']'<< '\n';
        }
        else if(iserror)
            cout << "error" << '\n';
    }
    return 0;
}