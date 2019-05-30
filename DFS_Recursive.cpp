#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void DFS(int s,vector<int> v[],int visited[]){
    visited[s]=1;
        cout<<s<<" ";
        for(int i=0;i<v[s].size();i++){
            if(visited[v[s][i]]==0){
                DFS(v[s][i],v,visited);
            }
        }
    }


int main(){
    int vertices;
    int edges;
    cin>>vertices>>edges;
    vector<int> v[vertices];
    int visited[vertices]={0};
    for(int a,b, i=0;i<edges;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int s=0;
    DFS(s,v,visited);


}
