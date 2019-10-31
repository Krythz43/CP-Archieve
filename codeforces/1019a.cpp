#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<long long,long long>
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'
	ll n,m,p,c;
	vector<ll> v[3001];
	ll a[3001]={0};
ll find(ll x)
{  priority_queue <ll, vector<ll>, greater<ll> > pq; //min heap
  ll ctr=v[1].size(),cost=0;
  for(ll j=2;j<=m;j++)
  {
  	ll len=v[j].size();
    for(ll t=0;t<len;t++)
    {
    	if(t<=len-x )
    	{
             cost+=v[j][t]; //cout<<cost<<endl;
             ctr++;
             //t++;
            // if(ctr>=x)break;
    	} 
    	else pq.push(v[j][t]);
    }
  }
  while(ctr<x)
    {
      ctr++;
      cost+=pq.top();//cout<<cost<<endl;
      pq.pop();
    }
  return cost;
}
int main()
{  fast;

	cin>>n>>m;
	ll tp=n;
	while(tp--)
	{
      cin>>p>>c;
      v[p].pb(c);
      a[p]=1;
	}
	for(ll i=2;i<=m;i++)
		{if(a[i]==1)
		sort(v[i].begin(),v[i].end());
	}
	ll ans=LLONG_MAX;

for(ll z=1;z<=n;z++)
{  
	ans=min(ans,find(z));	
}
cout<<ans<<endl;
return 0;	
}