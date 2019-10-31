#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

lli dp[15][105];

int count(int n, int k)
{
	if(n == 0)
		return 0;
	if(k == 0)
		return 1;
	if(dp[n][k] != -1)
		return dp[n][k];
	int val = 0;
	for(int i = 0; i < n && k-i >= 0; i++)
		val += count(n-1,k-i);
	return (dp[n][k] = val);
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        memset(dp,-1,sizeof dp);
        cout<<count(n,k)<<endl;
    }
}
