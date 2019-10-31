#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

int maxcomp=0,comp=0,cc=0;

vector <int> a[20];
vector <bool> vis(20,false);


int dfs(int i)
{
    vis[i]=true;
    for(int j=0;j<a[i].size();j++)
    {
        
        if(vis[a[i][j]]==false)
        {
            dfs(a[i][j]);
        }
    }
}

int main()
{
    fastio;
    int n;
    cin>>n;

    int x,y,z;

    rep(i,n+1,1)
    rep(j,n+1,1)
    {
        cin>>x;
        if(x==1)
        {
            a[i].pb(j);
        }
    }


    rep(i,n+1,1)
    {
        comp=1;
        if(vis[i]==false)
        {
            cc++;
            vis[i]=true;
            dfs(i);
        }
    }

    rep(i,n+1,1)
    {
        maxcomp=max(maxcomp,(int)a[i].size());
    }

    cout<<maxcomp+1;
}