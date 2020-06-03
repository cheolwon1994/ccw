#include <string>
#include <vector>
#include <vector>
#include <queue>
using namespace std;
bool check[200]={false,};
vector<int> v[200];
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();i++){
        for(int j=i+1;j<computers[i].size();j++){
            if(computers[i][j]==1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for(int i=0;i<computers.size();i++){
        if(!check[i]){
            answer++;
            check[i]=true;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int cidx = q.front();
                q.pop();
                for(int j=0;j<v[cidx].size();j++){
                    int next = v[cidx][j];
                    if(check[next]) continue;
                    check[next]=true;
                    q.push(next);
                }
            }
        }
    }
    return answer;
}