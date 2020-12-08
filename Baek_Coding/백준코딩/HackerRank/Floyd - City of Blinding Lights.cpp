#define MAX 987654321
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
int arr[401][401];
int node;

void floyd(int node){
    for(int k=1;k<=node;k++)
        for(int i=1;i<=node;i++)
            for(int j=1;j<=node;j++)
                if(arr[i][j]>arr[i][k]+arr[k][j])
                    arr[i][j]=arr[i][k]+arr[k][j];             
}


int main()
{
    int road_nodes;
    int road_edges;
    
    for(int i=1;i<=400;i++)
        for(int j=1;j<=400;j++){
            if(i==j) arr[i][j]=0;
            else arr[i][j]=MAX;
        }
            
    cin >> road_nodes >> road_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int a,b,val;

    for (int i = 0; i < road_edges; i++) {
        cin>>a>>b>>val;
        arr[a][b]=val;      
    }
    floyd(road_nodes);
    
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);
        arr[x][y]==MAX ? cout<< -1 : cout<<arr[x][y];
        cout<<'\n';
    }   
    return 0;
}