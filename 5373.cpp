#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
//[layerNUM][각 layer 별 위치(시계방향)]
//first : 무슨 조각 / second : orientation
pair<int, int> edge[12];
pair<int, int> corner[8];
char edgePieces[12][2] = 
{{'y', 'o'},{'y', 'b'},{'y', 'r'},{'y', 'g'},
{'o','g'},{'o', 'b'},{'r', 'b'},{'r', 'g'},
{'w', 'o'}, {'w', 'b'},{'w', 'r'},{'w', 'g'}};
char cornerPieces[8][3] = 
{{'y', 'g', 'o'}, {'y', 'o', 'b'}, {'y', 'b','r'}, {'y', 'r', 'g'}
,{'w', 'o', 'g'}, {'w', 'b', 'o'}, {'w','r','b'},{'w','g','r'}};

void edgeTurning(int a, int b, int c, int d);
void edgeOriToggle(int a, int b, int c, int d);
void cornerTurning(int a, int b, int c, int d);
void cornerOriToggle(int a, int b, int c, int d);
void reset();
int main (){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    string tmp;
    cin >> t;
    while(t--){
        reset();
        int n;
        cin >> n;
        while(n--){
            cin >> tmp;
            if(tmp == "R+"){
                edgeTurning(9, 5, 1, 6);
                cornerTurning(6, 5, 1, 2);
                cornerOriToggle(6, 5, 1, 2);
            }
            else if(tmp == "R-"){
                edgeTurning(9, 6, 1, 5);
                cornerTurning(6, 2, 1, 5);
                cornerOriToggle(6, 2, 1, 5);
            }
            else if(tmp == "L+"){
                edgeTurning(11, 7, 3, 4);
                cornerTurning(4, 7, 3, 0);
                cornerOriToggle(4, 7, 3, 0);
            }
            else if(tmp == "L-"){
                edgeTurning(11, 4, 3, 7);
                cornerTurning(4, 0, 3, 7);
                cornerOriToggle(4, 0, 3, 7);
            }
            else if(tmp == "U+"){
                edgeTurning(8, 9, 10, 11);
                cornerTurning(4, 5, 6, 7);
            }
            else if(tmp == "U-"){
                edgeTurning(8, 11, 10, 9);
                cornerTurning(4, 7, 6, 5);
            }
            else if(tmp == "D+"){
                edgeTurning(2, 1, 0, 3);
                cornerTurning(3, 2, 1, 0);
            }
            else if(tmp == "D-"){
                edgeTurning(2, 3, 0, 1);
                cornerTurning(3, 0, 1, 2);
            }
            else if(tmp == "F+"){
                edgeTurning(10, 6, 2, 7);
                edgeOriToggle(10, 6, 2, 7);
                cornerTurning(7, 6, 2, 3);
                cornerOriToggle(7, 6, 2, 3);
            }
            else if(tmp == "F-"){
                edgeTurning(10, 7, 2, 6);
                edgeOriToggle(10, 7, 2, 6);
                cornerTurning(7, 3, 2, 6);
                cornerOriToggle(7, 3, 2, 6);
            }
            else if(tmp == "B+"){
                edgeTurning(8, 4, 0, 5);
                edgeOriToggle(8, 4, 0, 5);
                cornerTurning(5, 4, 0, 1);
                cornerOriToggle(5, 4, 0, 1);
            }
            else if(tmp == "B-"){
                edgeTurning(8, 5, 0, 4);
                edgeOriToggle(8, 5, 0, 4);
                cornerTurning(5, 1, 0, 4);
                cornerOriToggle(5, 1, 0, 4);
            }
        }
        //출력
        
        cout << cornerPieces[corner[4].first][corner[4].second%3]
        << edgePieces[edge[8].first][edge[8].second]
        << cornerPieces[corner[5].first][corner[5].second%3] << '\n'
        << edgePieces[edge[11].first][edge[11].second]
        <<'w' << edgePieces[edge[9].first][edge[9].second]<<'\n'
        <<cornerPieces[corner[7].first][corner[7].second%3]
        <<edgePieces[edge[10].first][edge[10].second]
        <<cornerPieces[corner[6].first][corner[6].second%3]<<'\n';
    }
}

void reset(){
    for(int i = 0; i <12; i++){
        edge[i].first = i;
        edge[i].second = 0;
    }
    for(int i = 0; i < 8; i++){
        corner[i].first = i;
        corner[i].second = 0;
    }
}

void edgeTurning(int a, int b, int c, int d){
    pair<int, int> temp = edge[d];
    edge[d] = edge[c];
    edge[c] = edge[b];
    edge[b] = edge[a];
    edge[a] = temp;
}

void edgeOriToggle(int a, int b, int c, int d){
    edge[a].second ^= 1;
    edge[b].second ^= 1;
    edge[c].second ^= 1;
    edge[d].second ^= 1;
}
void cornerTurning(int a, int b, int c, int d){
    pair<int, int> temp = corner[d];
    corner[d] = corner[c];
    corner[c] = corner[b];
    corner[b] = corner[a];
    corner[a] = temp;
}
void cornerOriToggle(int a, int b, int c, int d){
    corner[a].second +=2;
    corner[b].second ++;
    corner[c].second +=2;
    corner[d].second ++;
}