#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define MW_YH ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ----------------------------Functions---------------------------- //
void Mohammed_Waleed(){
  MW_YH
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);
}
void dfs(ll node, map<ll,vector<ll>>&adj, vector<bool>&vis, ll &x1, ll &x2, ll &y1, ll &y2, vector<pair<ll,ll>>&a)
{
  vis[node]=1;
  x1 = min(x1,a[node].first);
  x2 = max(x2,a[node].first);
  y1 = min(y1,a[node].second);
  y2 = max(y2,a[node].second);
  for(auto neg:adj[node])
  {
    if(!vis[neg]) dfs(neg,adj,vis,x1,x2,y1,y2,a);
  }
}
// ----------------------------------------------------------------- //
void solution(){
  ll n, m, u, v;
  cin >> n >> m;
  vector<pair<ll,ll>>a(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  map<ll,vector<ll>>adj;
  vector<bool>vis(n+1,false);
  for(int i = 0; i < m; i++)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ll res = LONG_LONG_MAX;
  for(int i = 1; i <= n; i++)
  {
    if(!vis[i])
    {
      ll x1 = a[i].first, x2 = a[i].first;
      ll y1 = a[i].second, y2 = a[i].second;
      dfs(i,adj,vis,x1,x2,y1,y2,a);
      res = min(res,(x2-x1+y2-y1)*2);
    }
  }
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
