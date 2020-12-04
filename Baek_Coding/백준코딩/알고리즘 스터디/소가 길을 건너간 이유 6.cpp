#define MAX 987654321
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
struct info{
    int x,y,val;
};
struct cmp{
    bool operator()(info &a, info &b){
        return a.val > b.val;
    }
};
info tmp;
int num,k,r;
set<int> result;
int dist[101][101];
bool road[101][101][101][101]={false,};
vector<info> cow;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

void dijkstra(int y, int x, int idx){
    for(int i=1;i<=num;i++)
        for(int j=1;j<=num;j++)
            dist[i][j]=MAX;
    priority_queue<info,vector<info>,cmp> pq;
    tmp.x=x;
    tmp.y=y;
    tmp.val=0;
    pq.push(tmp);
    dist[y][x]=0;
    
    while(!pq.empty()){
        int cx = pq.top().x;
        int cy = pq.top().y;
        int cv = pq.top().val;
        pq.pop();
        if(dist[cy][cx]<cv) continue;
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>0 && ny>0 && nx<=num && ny<=num){
                int plus=0;
                if(road[ny][nx][cy][cx] || road[cy][cx][ny][nx])
                    plus=1;
                if(dist[ny][nx]>cv+plus){
                    dist[ny][nx]=cv+plus;
                    tmp.x=nx;
                    tmp.y=ny;
                    tmp.val=cv+plus;
                    pq.push(tmp);
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        if(i==idx) continue;
        int ny = cow[i].y;
        int nx = cow[i].x;
        if(dist[ny][nx])
            result.insert(max(idx,i)*1000+min(idx,i));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b,c,d;
    cin >> num >> k>>r;
    for(int i=0;i<r;i++){
        cin>>a>>b>>c>>d;
        road[a][b][c][d]=true;
        road[c][d][a][b]=true;
    }
    for(int i=0;i<k;i++){
        cin>>a>>b;
        tmp.y=a;
        tmp.x=b;
        cow.push_back(tmp);
    }
    for(int i=0;i<k;i++)
        dijkstra(cow[i].y, cow[i].x, i);
    cout<<result.size();
    return 0;
}