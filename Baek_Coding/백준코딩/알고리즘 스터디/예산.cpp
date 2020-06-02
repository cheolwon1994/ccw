#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> v;

bool cal(int mid, int M){
    long long temp=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<=mid)  temp+=v[i];
        else{
            temp+=(mid*(v.size()-i));
            break;
        }
    }
    if(temp<=M) return true;
    return false;
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    v = budgets;
    sort(v.begin(),v.end());
    
    long long l=0,r=v[v.size()-1],mid;
    while(l<=r){
        mid = l+(r-l)/2;        //»óÇÑ¾×
        if(cal(mid,M)){
            answer=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return answer;
}