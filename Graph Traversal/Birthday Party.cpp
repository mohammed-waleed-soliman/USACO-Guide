#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define MW_YH ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ----------------------------Functions---------------------------- //
void Mohammed_Waleed(){
  MW_YH
}
void dfs(ll node, map<ll,vector<ll>>&adj, vector<bool>&vis, pair<ll,ll>&cut)
{
  vis[node]=1;
  for(auto neg:adj[node])
  {
    if(!vis[neg] && cut!=make_pair(min(node,neg),max(node,neg))) dfs(neg,adj,vis,cut); 
  }
}
// ----------------------------------------------------------------- //
void solution(){
  while (true)
  {
    ll n, m, u, v;
    cin >> n >> m;
    if(n==0 && m==0) break;
    map<ll,vector<ll>>adj;
    vector<pair<ll,ll>>edge;
    for(int i = 0; i < m; i++)
    {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      edge.push_back({min(u,v),max(u,v)});
    }
    bool cond = true;
    for(int i = 0; i < m; i++)
    {
      vector<bool>vis(n);
      dfs(0,adj,vis,edge[i]);
      for(int j = 0; j < n; j++)
      {
        if(!vis[j])
        {
          cond = false;
          break;
        }
      }
      if(!cond)
      {
        cout << "Yes" << endl;
        break;
      }
    }
    if(cond) cout << "No" << endl;
  }
}

int main(){
  Mohammed_Waleed();
  int ntimes = 1;
  while (ntimes--)
  {
    solution();
  }
}
