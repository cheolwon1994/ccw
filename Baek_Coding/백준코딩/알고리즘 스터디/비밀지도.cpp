#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mul[17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    mul[0]=1;
    for(int i=1;i<17;i++)
        mul[i]=2*mul[i-1];
    for(int i=0;i<n;i++){
        string str="";
        for(int j=0;j<n;j++)
            str+=" ";
        int na = arr1[i];
        int nb = arr2[i];
        int idx=0;
        for(int k=n-1;k>=0;k--){
            if(na/mul[k]>0){
                na %= mul[k];
                str[idx]='#';
            }
            if(nb/mul[k]>0){
                nb %= mul[k];
                str[idx]='#';
            }
            idx++;
        }
        answer.push_back(str);
    }            
    return answer;
}