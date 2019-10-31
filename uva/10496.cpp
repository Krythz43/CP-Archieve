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
lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int mapi[20][20];
vector<ipair > a;
int n;
int memo [15][1<<11];

int tsp(int pos,int mask)
{
    // cout<<mask<<endl;
    if(mask==(1<<(n+1))-1)
    return mapi[pos][0];
    if(memo[pos][mask]!=-1)
    return memo[pos][mask];

    int ans=INT_MAX;

    for (int nxt = 0; nxt <= n; nxt++)
        if (nxt != pos && !(mask & (1 << nxt)))
        {
            ans = min(ans, mapi[pos][nxt] + tsp(nxt, mask | (1 << nxt)));
            // cout<<mapi[pos][nxt]<<"              "<<tsp(nxt,mask|(1<<nxt))<<endl;
        }

    // cout<<ans<<endl;
    
    return memo[pos][mask] = ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        a.clear();
        int xsize,ysize;
        cin>>xsize>>ysize;
        ipair sp;
        cin>>sp.ff>>sp.ss;
        int x,y;
        cin>>n;
        a.pb(mp(sp.ff,sp.ss));
        rep(i,n,0)
        {
            cin>>x>>y;
            a.pb(mp(x,y));
        }

        rep(i,n+1,0)
        rep(j,n+1,0)
        {
            mapi[i][j]=fabs(a[i].ff-a[j].ff)+fabs(a[i].ss-a[j].ss);
        }

        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", tsp(0, 1));
    }
}