#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());    
    long long l=times[0],r=(long long)times[times.size()-1]*(long long)n,mid;
    while(l<=r){
        mid = l + (r-l)/2;
        long long temp = 0;
        for(int i=0;i<times.size();i++)
            temp+=(mid/times[i]);
        if(temp>=n){
            answer=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return answer;
}