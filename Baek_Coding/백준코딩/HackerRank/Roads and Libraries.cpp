#include <bits/stdc++.h>

using namespace std;
bool flag[100001];
vector<int> v[100001];
vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    long long result=0;
    if(c_road >= c_lib) {
        result = n;
        return c_lib * result;
    }
    for(int i=1;i<=n;i++){
        flag[i]=false;
        v[i].clear();
    }
    
    for(int i=0;i<cities.size();i++){
        int a = cities[i][0];
        int b = cities[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            flag[i]=true;
            int cnt=1;         
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int cidx = q.front();
                q.pop();
                for(int k=0;k<v[cidx].size();k++){
                    int next = v[cidx][k];
                    if(!flag[next]){
                        flag[next]=true;
                        cnt++;
                        q.push(next);
                    }
                }
            }
            result+=(cnt-1)*c_road + c_lib;           
        } 
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}