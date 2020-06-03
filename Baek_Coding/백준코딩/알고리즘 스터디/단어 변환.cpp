#define MAX 987654321
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> m;
map<string,int> ::iterator it;
string result;
vector<string> v;
int ans = MAX;
void dfs(string str, int change){
    if(change >ans) return;
    if(str==result){
        if(change<ans){
            ans = change;
            m[str]=ans;
        }
        return;
    }
    for(int i=0;i<v.size();i++){
        string ss = v[i];
        int diff=0;
        for(int j=0;j<ss.size();j++)
            if(ss[j]!=str[j])
                diff++;
        if(diff==1){        //1개만 차이나는 경우
            it = m.find(ss);
            if(it==m.end()){      //아직 방문못해본 경우
                m[ss]=change+1;
                dfs(ss,change+1);
            }
            else{
                if(it->second>change+1){
                    m[ss]=change+1;
                    dfs(ss,change+1);
                }
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    result=target;
    v=words;
    dfs(begin,0);
    if(ans==MAX) ans=0;
    answer=ans;
    return answer;
}