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

int n;
vi a[108];
vector<bool> vis(108);


void dfs(int s)
{
    rep(i,a[s].size(),0)
    {
        if(vis[a[s][i]]==false)
        {
            vis[a[s][i]]=true;
            dfs(a[s][i]);
        }
    }
}


int main()
{
    fastio;
    while(1)
    {
        cin>>n;
        if(n==0)
        break;

        rep(i,n+1,0)
        a[i].clear();

        int x,y;
        while(1)
        {
            cin>>x;
            if(x==0)
            break;
            else
            {
                while(1)
                {
                    cin>>y;
                    if(y==0)
                    break;
                    else{
                    a[x].pb(y);
                    }
                }
                
            }
        }

        int q,s;
        cin>>q;
        while(q--)
        {
            cin>>s;
            rep(i,n+1,1)
            vis[i]=false;
            dfs(s);
            int c=0;
            rep(i,n+1,1)
            if(vis[i]==false)
            c++;
            if(c!=0)
            cout<<c<<" ";
            else
            cout<<c;
            int z=0;
            rep(i,n+1,1)
            if(vis[i]==false)
            {
                if(z==c-1)
                cout<<i;
                else
                cout<<i<<" ";
                z++;
                if(z==c)
                break;
            }

            nl;
        }
    }
}