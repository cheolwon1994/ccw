#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
using namespace std;
bool used[100000]={false,};
int tt[100000];
map<string,int> m;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0,cnt=0;
    if(cacheSize==0){
        answer = cities.size()*5;
        return answer;
    }
    for(int i = 0;i<cities.size();i++){
        for(int j=0;j<cities[i].size();j++)
            cities[i][j] = toupper(cities[i][j]);
        if(m.find(cities[i])==m.end())
            m[cities[i]]=cnt++;
    }
    deque<int> dq;          //현재 캐시에 있는 도시번호 저장
    for(int i = 0;i<cities.size();i++){
        string ss = cities[i];
        int sidx = m[ss];
        if(used[sidx]){         //hit
            answer++;
            tt[sidx]=i;     //시간 갱신
        }        
        else{                           //miss
            if(dq.size()<cacheSize){
                used[sidx]=true;
                answer+=5;
                tt[sidx]=i;
                dq.push_back(sidx);
            }
            else{
                int mini = 100001;
                for(int j=0;j<dq.size();j++)
                    mini =min(mini,tt[dq[j]]);                
                for(int j=0;j<dq.size();j++){
                    int vv = dq[j];
                    if(tt[vv]==mini){
                        dq[j] = sidx;
                        used[vv]=false;
                        break;
                    }
                }
                used[sidx]=true;
                answer+=5;
                tt[sidx]=i;
            }
        }
    }
    return answer;
}