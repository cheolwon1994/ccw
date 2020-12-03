#define MAX 987654321
#include <bits/stdc++.h>

using namespace std;
struct info{
    int idx,val;
};
struct cmp{
    bool operator()(info &a, info &b){
        return a.val>b.val;
    }
};
info tmp;
vector<info> v[3001];
int dist[3001];
vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    //초기화
    vector<int> result;
    for(int i=1;i<=n;i++){
        v[i].clear();
        dist[i]=MAX;
    }
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
    tmp.idx=s;
    tmp.val=0;
    pq.push(tmp);
    dist[s]=0;
    while(!pq.empty()){
        int cidx = pq.top().idx;
        int cv = pq.top().val;
        pq.pop();
        if(dist[cidx]<cv) continue;
        for(int i=0;i<v[cidx].size();i++){
            int next = v[cidx][i].idx;
            int nv = v[cidx][i].val;
            if(dist[next]>cv+nv){
                dist[next]=cv+nv;
                tmp.val = cv+nv;
                tmp.idx = next;
                pq.push(tmp);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i==s) continue;
        int val = (dist[i]==MAX)? -1 : dist[i];
        result.push_back(val);
    }
    return result;
}