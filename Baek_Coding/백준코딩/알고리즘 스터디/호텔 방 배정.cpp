#include <string>
#include <vector>
#include <map>
using namespace std;
//long long par[1000000000001];
map<long long, long long> m;
map<long long, long long> ::iterator it;

long long find_p(long long x){
    it = m.find(x);
    if(it==m.end())  return x;
    return m[x] = find_p(it->second);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(long long i=0;i<room_number.size();i++){
        long long want = room_number[i];
        long long canGo = find_p(want);
        answer.push_back(canGo);
        m[canGo]=find_p(canGo+1);
    }
    return answer;
}