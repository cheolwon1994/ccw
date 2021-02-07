#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
struct info{
    int a, b;
    long long val;
};
bool cmp(info &a, info &b){
    return a.val < b.val;
};
info tmp;
int arr[601];

int main() {
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>arr[i];
    vector<info> v;
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            long long add = arr[i]+arr[j];
            tmp.a=i;
            tmp.b=j;
            tmp.val = add;
            v.push_back(tmp);
        }
    }
    sort(v.begin(),v.end(),cmp);
    long long result=9876543210;
    
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i].a!=v[j].a && v[i].a!=v[j].b && v[i].b!=v[j].a && v[i].b!=v[j].b){
                result = min(result,v[j].val-v[i].val);
                break;
            }
        }
    }
    cout<<result;
    return 0;
}