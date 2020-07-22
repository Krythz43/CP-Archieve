#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

lli F(lli a, lli b, lli x, lli y){
	x--,y--;
	lli sum = (y * (y - 1) - x * (x - 1)) / 2;
	return a * (y - x) + sum * b;
}


int main()
{
    fastio;
	lli a,b,q;
	cin>>a>>b>>q;

	while(q--){
		lli l,t,m;
		cin>>l>>t>>m;

		lli lo = l,hi = 2e6 + 5;
		while (hi - lo > 1){
			lli mid = (lo + hi)/2;
			if (a + (mid - 2)*b <= t && F(a, b, l, mid) <= t * m) lo = mid;
			else hi = mid;
		}

		if (lo == l) lo = 0;
		cout<<lo-1<<endl;
	}
}