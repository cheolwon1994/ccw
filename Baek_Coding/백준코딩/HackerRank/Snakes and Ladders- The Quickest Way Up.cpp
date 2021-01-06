#include <bits/stdc++.h>

using namespace std;
struct info{
    int loc,val;
};
info tmp;
int check[101];
// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    int result=-1;
    for(int i=2;i<=100;i++)
        check[i]=987654321;
    queue<info> q;
    tmp.loc=1;
    tmp.val=0;
    q.push(tmp);
    while(!q.empty()){
        int cl = q.front().loc;
        int cv = q.front().val;
        q.pop();
        if(cl==100){
            result=cv;
            break;
        }
        for(int i=1;i<7;i++){
            int nl = cl+i;
            if(check[nl]>cv+1){
                check[nl]=cv+1;
                //사다리 타고 이동
                for(int j=0;j<ladders.size();j++){
                    int ls = ladders[j][0];
                    if(ls!=nl) continue;
                    
                    if(check[ladders[j][1]]>cv+1){
                        check[ladders[j][1]]=cv+1;
                        nl = ladders[j][1];
                        break;
                    }                  
                }
                //뱀의 머리에 먹혀서 밑으로 이동
                for(int j=0;j<snakes.size();j++){
                    int ss = snakes[j][0];
                    if(ss!=nl) continue;
                    if(check[snakes[j][1]]>cv+1){
                        check[snakes[j][1]]=cv+1;
                        nl = snakes[j][1];
                        break;
                    }
                }
                tmp.loc=nl;
                tmp.val=cv+1;
                q.push(tmp);
            }
        }
    }
    return result;
}