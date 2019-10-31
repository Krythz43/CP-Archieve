#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define lli long long int
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define llipair pair <lli,lli>

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

#define S 105

int n,k;

vi a[S];
vi dis[S];
vector <bool> vis(S,false);
vi col(S);


void dfs(int s,int id,int ls,int d)
{
    for(auto x:a[id])
    {
        if(x==ls)
        continue;
        cout<<"update "<<s<<","<<x<<":"<<d+1<<endl;
        dis[s].pb(d+1),dis[x].pb(d+1);
        dfs(s,x,id,d+1);
    }
}
int main()
{
    fastio;
    cin>>n>>k;
    rep(i,n,0)
    cin>>col[i];
    int x,y;
    rep(i,n-1,0)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    rep(i,n+1,1)
    dfs(i,i,-1,0);

    rep(i,n+1,0)
    {
        rep(j,n+1,0)
        {
            if(dis[i][j])
            cout<<"dis between "<<i<<" and "<<j<<" is "<<dis[i][j]<<endl;
        }
    }

    int ans=INT_MAX;

    rep(i,n+1,1)
    {
        if
    }

}