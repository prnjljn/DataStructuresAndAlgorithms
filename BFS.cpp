#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int vertices;
    cin>>vertices;
    int edges;
    cin>>edges;
    vector<int> v[vertices];
    int visited[vertices]={0};
    for(int a,b,i=0;i<edges;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int start=0;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int cv= q.front();
        q.pop();
        cout<<cv<<" ";
        for(int i=0;i<v[cv].size();i++){
            if(visited[v[cv][i]]==0){
                q.push(v[cv][i]);
                visited[v[cv][i]]=1;
            }
        }
    }
}
