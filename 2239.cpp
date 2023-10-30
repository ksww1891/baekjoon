#include<iostream>
#include<string>
#include<cstring>
#include<bitset>
using namespace std;

int board[10][10];
bool answer;
int r[9];
int c[9];
int s[3][3];
int FULL = (1<<9)-1;

void recur(int row , int column){
	//cout << row << ' ' << column <<  ' ' << bitset<9>(r[row]) << ' ' << bitset<9>(c[column]) << ' ' <<
	//bitset<9>(s[row/3][column/3]) << '\n';

	if(row == 9){
		answer = 1;
		for(int i = 0; i < 9; i++){
			for(int j  = 0 ; j < 9; j++){
				cout << board[i][j];
			}
			cout << '\n';
		}
		return;
	}
	if(board[row][column] != 0){
		if(column == 8)recur(row+1, 0);
		else recur(row, column+1);
		return;
	}

	for(int i = 1; i < 10; i++){
		if((r[row] & (1<<(i-1))) == (1<<(i-1)))continue;
		if((c[column] & (1<<(i-1))) == (1<<(i-1)))continue;
		if((s[row/3][column/3] & (1<<(i-1))) == (1<<(i-1)))continue;

		board[row][column] = i;
		r[row] = (r[row] | (1<<(i-1)));
		c[column] = (c[column] | (1<<(i-1)));
		s[row/3][column/3] = (s[row/3][column/3] | (1<<(i-1)));

		if(column == 8)recur(row+1, 0);
		else recur(row, column+1);

		if(answer)return;
		board[row][column] = 0;
		r[row] = (r[row] ^ (1<<(i-1)));
		c[column] = (c[column] ^ (1<<(i-1)));
		s[row/3][column/3] = (s[row/3][column/3] ^ (1<<(i-1)));
	}
	
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(r, (1<<9), sizeof(r));
	memset(c, (1<<9), sizeof(c));
	memset(s, (1<<9), sizeof(s));
	for(int i = 0; i < 9; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < 9; j++){
			board[i][j] = tmp[j]-'0';
			if(board[i][j] == 0)continue;
			r[i] = (r[i]|(1<<(board[i][j]-1)));
			c[j] = (c[j]|(1<<(board[i][j]-1)));
			s[i/3][j/3] = (s[i/3][j/3]|(1<<(board[i][j]-1)));
		}
	}
	recur(0, 0);
}