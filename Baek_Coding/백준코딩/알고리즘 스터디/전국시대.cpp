#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int par[100001];
int power[100001];

int find_p(int x){
    if(par[x]==x) return x;
    return par[x] = find_p(par[x]);
}

void make_union(int a,int b){
    int pa = find_p(a);
    int pb = find_p(b);
    //�������� ���� ��ġ�� + ���� ó��
    if(pa<pb){
        par[pb] = pa;
        power[pa]+=power[pb];
        power[pb]=0;
    } 
    else if(pa>pb){
        par[pa] = pb;
        power[pb]+=power[pa];
        power[pa]=0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int node,edge,a,b,c;
    cin >> node >> edge;
    for(int i=1;i<=node;i++){
        cin >> power[i];
        par[i]=i;   
    }
    for(int i=0;i<edge;i++){
        cin>>a>>b>>c;
        if(a==1)       //����
            make_union(b,c);
        else{       //����
            int pb = find_p(b);
            int pc = find_p(c);
            int vb = power[pb];
            int vc = power[pc];
            if(vb==vc){     //���
                power[pb]=0;
                power[pc]=0;
                par[pb]=0;
                par[pc]=0;
            }
            //�� ���� ���+���� ����+�ӱ� ó��
            else if(vb>vc){    
                power[pb]-=vc;		//���� ����
                power[pc]=0;		//���� ���
                par[pc] = pb;		//�ӱ� ó��
            }
            else {
                power[pb]=0;
                power[pc]-=vb;
                par[pb] = pc;
            }
        }
    }
    vector<int> v;
    for(int i=1;i<=node;i++){
        if(power[i]!=0)
            v.push_back(power[i]);
    }
    sort(v.begin(),v.end());
    
    cout<<v.size()<<'\n';
    for(int i=0;i<v.size();i++)
        cout << v[i]<<" ";
    return 0;
}