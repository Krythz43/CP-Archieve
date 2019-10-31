#include <bits/stdc++.h>
using namespace  std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define ff first
#define ss second
#define rep(i,n,z) for(long long i=z;i<n;i++)
#define rrep(i,z) for(long long i=z;i>=0;i--)
#define fillv(a,k) memset(a,k,sizeof(a))

#define leadzero(a) __builtin_clz(a) //count leading zeros
#define trailzero(a) __builtin_ctz(a) //count trailing zeros
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln cout<<"\n"
#define sp cout<<" "

#define all(c) c.begin(),c.end()

typedef long long int ll;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<p64> vp64;
typedef vector<v64> vv64;
typedef map<ll,ll> m64;


typedef long double ld;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<long long,long long> p32;
typedef pair<long long,p32> p96;
typedef vector<string> vs;
typedef vector<long long> v32;
typedef vector<v32> vv32;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;

const long long LIM = 1e5+5, MOD = 1e9+7;

#define sumv(v) accumulate(all(v),ll(0))
#define productv(v) accumulate(all(v), ll(1), multiplies< ll >())

struct node
{
	long long x,y,z;
	long long i;
};
bool compare(struct node a, struct node b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	if(a.y!=b.y)
		return a.y<b.y;

	return a.z<b.z;
}
int main()
{
	fastio;
	ll n;
	vector < struct node > v;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		struct node t;
		t.x=x;
		t.y=y;
		t.z=z;
		t.i=i+1;
		v.pb(t);
	}	
	sort(all(v),compare);

	vector< pair< pair<long long,pair<long long,long long> >, pair<long long,long long> > > d;
	for(ll i=0;i<v.size()-1;i++)
	{
		struct node a,b;
		a=v[i];
		b=v[i+1];
		pair<long long,pair<long long,long long> > diff = mp(abs(a.x-b.x),mp(abs(a.y-b.y),abs(a.z-b.z)));
		d.pb(mp(diff,mp(a.i,b.i)));
	}
	sort(all(d));
	ll vis[n+1]={0};
	for(ll i=0;i<d.size();i++)
	{
		pair<long long,long long> p;
		p=d[i].ss;
		if(vis[p.ff]==0 && vis[p.ss]==0)
		{
			vis[p.ff]=1;
			vis[p.ss]=1;
			cout<<p.ff<<" "<<p.ss<<endl;
		}
	}
	

}
