#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(lli i=z;i<n;i++)
#define rrep(i,z) for(lli i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<lli>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <lli,lli>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(lli i=0;i<m;i++){for(lli j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

typedef struct data
{
	data* bit[2];
	lli cnt = 0;
}trie;

trie* head;

void insert(lli x)
{
	trie* cur = head;
	for(lli i=32;i>=0;i--)
	{
		lli b = (x>>i) & 1;
		if(!cur->bit[b])
			cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}

lli maxxor(lli x)
{
	trie* cur = head;
	lli ans = 0;
	for(lli i=32;i>=0;i--)
	{
		lli b = (x>>i)&1;
		if(cur->bit[!b] && cur->bit[!b]->cnt>0)
		{
			ans += (1LL<<i);
			cur = cur->bit[!b];
		}
		else
			cur = cur->bit[b];
	}
	return ans;
}


int main()
{
    fastio;
    lli n;
    cin>>n;
    vinput(a,n);
    head = new trie();
    rep(i,n,0)insert(a[i]);

    lli ans = inf;
    rep(i,n,0)ans=min(ans,maxxor(a[i]));
    rep(i,30,0)ans=min(ans,maxxor(1LL<<(i)));
    cout<<ans<<endl;
}