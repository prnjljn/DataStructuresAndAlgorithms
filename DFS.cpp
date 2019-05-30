#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void DFS(int start,vector<int> v[],int visited[]){
    stack<int> sta;
    sta.push(start);
    visited[start]=1;
    while(!sta.empty()){
        int s= sta.top();
        cout<<s<<" ";
        sta.pop();
        for(int i=0;i<v[s].size();i++){
            if(visited[v[s][i]]==0){
                sta.push(v[s][i]);
                visited[v[s][i]]=1;
            }
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
