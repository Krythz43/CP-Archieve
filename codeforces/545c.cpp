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

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int n;
ipair memo[(int)1e5+5][3];
vector <ipair> a;


int main()
{
    fastio;
    cin>>n;
    int x,y;

    rep(i,n,0)
    {
        cin>>x>>y;
        a.pb(mp(x,y));
    }

    memo[0][0]=mp(0,a[0].ff);
    memo[0][1]=mp(1,a[0].ff);
    if(n>1)
    {
        if(a[0].ff+a[0].ss<a[1].ff)
        memo[0][2]=mp(1,a[0].ff+a[0].ss);
        else
        memo[0][2]=mp(0,a[0].ff);
    }

    ipair mx;
    int maxe=-1;
    rep(i,n-1,1)
    {
        x=a[i].ff;
        y=a[i].ss;

        //stay
        rep(j,3,0)
        maxe=max(maxe,memo[i-1][j].ff);
        memo[i][0]=mp(maxe,a[i].ff);

        //left

        int l=x-y;
        if(memo[i-1][0].ss<x-y)
        {
            mx=mp(max(memo[i-1][0].ff,memo[i-1][1].ff)+1,x);
            if(memo[i-1][2].ss<x-y)
            {
                if(mx.ff<memo[i-1][2].ff+1)
                mx=mp(memo[i-1][2].ff+1,x);
            }
            memo[i][1]=mx;
        }
        else
        {
            memo[i][1]=mp(maxe,a[i].ff);
        }

        //right

        if(a[i+1].ff>x+y)
        {
            mx=mp(max(memo[i-1][0].ff,max(memo[i-1][1].ff,memo[i-1][2].ff))+1,x+y);
            memo[i][2]=mx;
        }
        else
        {
            memo[i][2]=mp(maxe,a[i].ff);
        }
    }

    // rep(i,n-1,0)
    // {
    //     rep(j,3,0)
    //     {
    //         cout<<memo[i][j].ff<<" "<<memo[i][j].ss<<"\t";
    //     }
    //     nl;
    // }

    if(n==1)
    cout<<1<<endl;
    else
    cout<<1+max(memo[n-2][0].ff,max(memo[n-2][1].ff,memo[n-2][2].ff))<<endl;
}