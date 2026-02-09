#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define MW_YH ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ----------------------------Functions---------------------------- //
void Mohammed_Waleed(){
  MW_YH
}
vector<ll>temp;
void mark(vector<bool>&cycle)
{
  for(auto i:temp) cycle[i]=1;
}
void dfs(ll node, map<ll,vector<ll>>&adj, ll start, vector<bool>&cycle, ll level, vector<bool>&vis)
{
  vis[node] = 1;
  for(auto neg:adj[node])
  {
    temp.push_back(neg);
    if(neg==start) mark(cycle);
    else if(!vis[neg]) dfs(neg,adj,start,cycle,level+1,vis);
    temp.pop_back();
  }
}
// ----------------------------------------------------------------- //
void solution(){
  ll n, m, u, v, su, sv;
  cin >> n >> m;
  map<ll,vector<ll>>adj;
  vector<bool>cycle(n+1);
  for(int i = 0; i < m; i++)
  {
    cin >> u >> v >> su >> sv;
    if(su>sv) adj[u].push_back(v);
    else adj[v].push_back(u);
  }
  for(ll i = 1; i <= n; i++)
  {
    vector<bool>vis(n+1);
    if(!cycle[i]) dfs(i,adj,i,cycle,0,vis);
  }
  ll res = 0;
  for(int i = 1; i <= n; i++) if(cycle[i]) res++;
  cout << res;
}

int main(){
  Mohammed_Waleed();
  int ntimes = 1;
  while (ntimes--)
  {
    solution();
  }
}
