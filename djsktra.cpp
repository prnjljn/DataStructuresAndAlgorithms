#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
#define mp make_pair
void djsktra(int source,vector<vector<int> > path,int n){
   priority_queue<ipair,vector<ipair >,greater<ipair > > pq;
   int dis[n];
   for(int i=0;i<n;i++){
       dis[i]=INT_MAX;
   }
   dis[source]=0;
   pq.push(mp(dis[source],source));
   while(!pq.empty()){
       int curr=pq.top().second;
        pq.pop();
       for(int i=0;i<n;i++){
           if(path[curr][i]!=0 && (dis[i]>dis[curr]+path[curr][i])){
               dis[i]=dis[curr]+path[curr][i];
               pq.push(mp(dis[i],i));
           }
       }
   }
   for(int i=0;i<n;i++){
       cout<<dis[i]<<endl;
   }

}

int main(){
    int n =9;
   vector<vector<int> > path{ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    
    djsktra(0,path,9);



}