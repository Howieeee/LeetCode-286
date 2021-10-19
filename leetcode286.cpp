#include<iostream>
#include<vector>
#include<queue>
#include<limits> //numeric_limits
#include<utility> //pair
using namespace std;

/*
-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF 
as you may assume that the distance to a gate is less than 2147483647.

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
*/

bool moveVaild (int& b_x, int& b_y , pair<int,int>& node){
    if( node.first>= 0 && node.first < b_x  && node.second >=0 && node.second <b_y)
        return true;
    else
        return false;
}

void wallsAndGates(vector<vector<int>>& rooms) {
    int wall = -1, gate=0, room = numeric_limits<int>::max();
    int x = rooms.size();
    int y = rooms[0].size();
    if(x < 1)
        return;
    if(y <1)
        return;
        
    queue<pair<int,int>> que;
    
    for(int i=0;i<rooms.size();i++){
        for(int j=0;j<rooms[i].size();j++){
            if(rooms[i][j] == gate) //將門放入queue
                que.push(pair<int,int>(i,j));
        }
    }
    
    //BFS開始 從門開始走
    int steps =0;
    
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}}; //上下左右 
    
    while(!que.empty()){
        
        for(int s = que.size()-1;s>=0;s--){
            
            pair<int,int> node = que.front();//處理queue的第一個
            que.pop();        
            //cout << node.first <<" " << node.second<< " \n";
            
            if(rooms[node.first][node.second] == room) //是房間就改成步數
                rooms[node.first][node.second] = steps;
            
            if(rooms[node.first][node.second] != wall){ //不是牆壁就可以push進queue
                //if(rooms[node.first][node.second] != gate) //大門也不能push (已經push過了)
                    //que.push(node); //此個點的index
            
            
                for(int i=0;i<direction.size();i++){
                    pair<int,int> t_node = node;
                    t_node.first += direction[i].first;
                    t_node.second += direction[i].second;
                    if( moveVaild(x,y,t_node) && 
                        rooms[t_node.first][t_node.second] == room )
                        que.push(t_node);
                    
                }
            }
            //steps +=1;
        }
        steps +=1;
    }
}


    
int main(){
    int INF  = numeric_limits<int>::max();
    vector<int>row1({INF,-1,0,INF});
    vector<int>row2({INF, INF, INF,  -1});
    vector<int>row3({INF , -1 ,INF , -1});
    vector<int>row4({0 , -1 ,INF ,INF});
    vector<vector<int>> rooms;
    rooms.push_back(row1);rooms.push_back(row2);rooms.push_back(row3);rooms.push_back(row4);
    
    wallsAndGates(rooms);
    
    for(auto i = 0;i<rooms.size();i++){
        for(auto j=0; j< rooms[i].size();j++){
            cout << rooms[i][j] << " ";
        }
        cout << endl;
    }
}