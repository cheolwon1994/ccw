#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
bool visit[3001]={false,};
struct info{
    int idx,val;
};
struct cmp{
    bool operator()(info &a, info &b){
        return a.val > b.val;
    }
};
info tmp;
vector<info> v[3001];
// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    for(int i=0;i<edges.size();i++){
        int a = edges[i][0];
        int b = edges[i][1];
        int val = edges[i][2];
        tmp.val = val;
        tmp.idx = b;
        v[a].push_back(tmp);
        tmp.idx=a;
        v[b].push_back(tmp);
    }
    
    priority_queue<info,vector<info>,cmp> pq;
    queue<int> q;
    int result=0;
    q.push(start);
    visit[start]=true;
    while(!q.empty()){
        int cidx = q.front();
        q.pop();
        for(int i=0;i<v[cidx].size();i++){
            int next = v[cidx][i].idx;
            if(visit[next]) continue;
            int nv = v[cidx][i].val;
            tmp.idx = next;
            tmp.val = nv;
            pq.push(tmp);
        }
        while(!pq.empty()){
            cidx = pq.top().idx;
            int cv = pq.top().val;
            pq.pop();
            if(visit[cidx]) continue;
            visit[cidx]=true;
            result+=cv;
            q.push(cidx);
            break;
        }       
    }
    return result;
}