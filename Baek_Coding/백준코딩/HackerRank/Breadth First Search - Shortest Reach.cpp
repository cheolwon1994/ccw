#define MAX 987654321
#include <bits/stdc++.h>

using namespace std;
vector<string> split_string(string);
struct info{
    int idx,val;
};
info tmp;
int dist[1001];
vector<int> v[1001];
// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    //초기화
    vector<int> result;
    for(int i=1;i<=n;i++){
        dist[i]=MAX;
        v[i].clear();
    }
    
    for(int i=0;i<m;i++){
        int a = edges[i][0];
        int b = edges[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<info> q;
    tmp.idx = s;
    tmp.val=0;
    q.push(tmp);
    dist[s] = 0;
    while(!q.empty()){
        int cidx = q.front().idx;
        int cv = q.front().val;
        q.pop();
        for(int i=0;i<v[cidx].size();i++){
            int next = v[cidx][i];
            if(dist[next] > cv+1){
                dist[next]=cv+1;
                tmp.idx = next;
                tmp.val = cv+1;
                q.push(tmp);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i==s) continue;
        if(dist[i]==MAX) result.push_back(-1);
        else result.push_back(6*dist[i]);
    }
    return result;
}