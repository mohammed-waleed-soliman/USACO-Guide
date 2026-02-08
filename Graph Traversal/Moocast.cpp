#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define MW_YH ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ----------------------------Functions---------------------------- //
void Mohammed_Waleed(){
  MW_YH
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
}
ll distance(ll x1, ll x2, ll y1, ll y2)
{
  return ceil(sqrtl(pow(abs(x1-x2),2)+pow(abs(y1-y2),2)));
}
ll dfs(ll node, map<ll,vector<ll>>&adj, vector<bool>&vis)
{
  vis[node]=1;
  int x = 0;
  for(auto neg:adj[node])
  {
    if(!vis[neg]) x+=dfs(neg,adj,vis);
  }
  return x+1;
}
// ----------------------------------------------------------------- //
void solution(){
  ll size;
  cin >> size;
  vector<pair<pair<ll,ll>,ll>>v(size);
  for(int i = 0; i < size; i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;
  map<ll,vector<ll>>adj;
  for(int i = 0; i < size; i++)
  {
    ll x = v[i].second;
    for(int j = 0; j < size; j++)
    {
      if(i==j) continue;
      ll d = distance(v[i].first.first,v[j].first.first,v[i].first.second,v[j].first.second);
      if(d<=x)
      {
        adj[i].push_back(j);
      }
    }
  }
  ll res = 0;
  for(int i = 0; i < size; i++)
  {
    vector<bool>vis(size,0);
    res = max(res,dfs(i,adj,vis));
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
