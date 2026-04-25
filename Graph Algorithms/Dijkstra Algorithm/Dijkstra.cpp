//Dijkstra Algorithm example code
//This algorithm can be used if the lengths of all edges are positive
//This algorithm can calculate minimum distances of starting vertex to other verteces
//time complexity : O(V*E*log V) V is number of vertex, E is number of edge
//maximum number of verteces is 20000, and maximum number of Edges is 300000, printing values are distances to all verteces from starting vertex
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define INF 0x3f3f3f3f //this value can used in memset
using namespace std;
typedef struct
{
  int to,cost;
}Edge;
int v,e,st //number of verteces, number of edges, starting vertex
vector<Edge> graph[20001];
inline void Dijkstra()
{
  dist[st]=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min heap
  pq.push({0,st});
  while(!pq.empty())
  {
    pair<int,int> tmp=pq.top();
    pq.pop();
    int d=tmp.first,cur=tmp.second;
    if(dist[cur]<d) continue; //alreaedy visited
    for(int i=0;i<graph[cur].size();++i)
    {
      int next=graph[cur][i].to;
      if(dist[next]>dist[cur]+graph[cur][i].cost)
      {
        dist[next]=dist[cur]+graph[cur][i].cost;
        pq.push({dist[next],next});
      }
    }
  }   
}
int main()
{
  memset(dist,INF,sizeof(dist));
  cin>>v>>e>>st;
  for(int i=0;i<e;++i)
  {
    int from,to,cost;
    cin>>from>>to>>cost;
    graph[a].push_back({b,c});
  }
  Dijkstra();
  for(int i=1;i<=v;++i)
  {
      if(dist[i]>=INF) cout<<"Can't go there\n";
      else cout<<dist[i]<<'\n';
  }
  return 0;  
}
