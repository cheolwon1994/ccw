#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string,int> m;
    for(int i=0;i<strings.size();i++){
        if(m.find(strings[i])==m.end())
            m[strings[i]]=1;
        else 
            m[strings[i]] +=1;
    }
    vector<int> result;
    for(int i=0;i<queries.size();i++){
        if(m.find(queries[i])==m.end())
            result.push_back(0);
        else
            result.push_back(m[queries[i]]);
    }
    return result;
}