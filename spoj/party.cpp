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


vector<ipair> party;

ipair dp[105][505];

ipair solve(int i,int b)
{
    // cout<<"recurring for "<<i<<" "<<b<<endl;
    if(i<0 || b<0)
    return {0,0};

    ipair &ans=dp[i][b];

    if(ans.ff!=-1)
    return ans;
    ipair p={0,0},np;
    if(b-party[i].ff>=0)
    {
        p=solve(i-1,b-party[i].ff);
        p.ff+=party[i].ss;
        p.ss+=party[i].ff;
    }
    np=solve(i-1,b);

    if(p.ff==np.ff)
    {
        if(p.ss>np.ss)
        return np;
        else
        return p;
    }
    if(p.ff>np.ff)
    return ans=p;
    else
    return ans=np;
}

int main()
{
    fastio;
    int x,y;
    int n,b;
    while(true)
    {
        rep(i,105,0)
        rep(j,505,0)
        dp[i][j]=mp(-1,-1);
        party.clear();
        cin>>b>>n;
        if(n==0 && b==0)
        break;
        rep(i,n,0)
        {
            cin>>x>>y;
            party.pb(mp(x,y));
        }

        ipair ans=solve(n-1,b);
        cout<<ans.ss<<" "<<ans.ff<<endl;
    }
}