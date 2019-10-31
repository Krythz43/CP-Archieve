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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'
#define S 200005
int n,m;
vector <int> a[S];
vector <bool> vis(S,false);
vector <ipair> ans;

void bfs(int i)
{
    queue <int> q;
	int z;
	z=i;
	q.push(z);
	vis[z]=true;
	
	while(q.empty()==false)
	{
		int p=q.front();
		q.pop();
		rep(i,a[p].size(),0)
		{
			if(vis[a[p][i]]==false)
			{
                q.push(a[p][i]);
			    ans.pb(mp(p,a[p][i]));
			    vis[a[p][i]]=true;
		    }
		}
	}
}
int main()
{
    fastio;
    cin>>n>>m;
    int x,y;
    rep(i,m,0)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    int st=0;
    rep(i,n+1,1)
    {
        if(a[st].size()<a[i].size())
        st=i;
    }

    bfs(st);

    rep(i,ans.size(),0)
    cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
}