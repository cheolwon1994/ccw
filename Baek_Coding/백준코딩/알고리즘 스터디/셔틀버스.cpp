#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> arr[10];

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int cnt;
    vector<int> v;
    for(int i=0;i<timetable.size();i++){
        string str,str1;
        istringstream ss(timetable[i]);
        while(getline(ss,str,',')){
            istringstream iss(str);
            int num=0,val;
            cnt=0;
            while(getline(iss,str1,':')){
                val = atoi(str1.c_str());
                if(cnt==0) num = val*60;
                else num+=val;
                cnt++;
            }
            v.push_back(num);
        }
    }
    queue<int> q;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        q.push(v[i]);
    int ctime = 9*60,result;
    
    for(int i=0;i<n;i++){
        cnt=0;
        while(!q.empty() && cnt<m){
            int ct = q.front();     //크루 도착 시간
            if(ct>ctime) break;     //셔틀보다 늦게 오는 경우
            else{
                arr[i].push_back(ct);
                q.pop();
                cnt++;
            }
        }
        ctime+=t;
    }
    if(arr[n-1].size()<m)     //마지막 셔틀 도착시간에 도착하면 될 때
        result = ctime-t;
    
    else
        result = arr[n-1][m-1]-1;
        
    int hour = result/60;
    int min = result%60;
    if(hour<10) answer = "0"+to_string(hour);
    else answer = to_string(hour);
    answer+=":";
    if(min<10) answer += "0"+to_string(min);
    else answer += to_string(min);
    return answer;
}