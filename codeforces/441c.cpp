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

int n,m,k;
vector<ipair > kr[100005];
int d=0;
int vis;
void ct(int x,int y,int r,int t)
{
    // cout<<"visited "<<t<<" at "<<vis<<endl;
    kr[t].pb(mp(x,y));
    vis++;
    if(vis==n*m)
    return;
    
    // vis++;

    if(y==m)
    {
        if(d==0)
        {
            x++;
            d=(d+1)%2;
        }
        else
        y--;
    }
    else if(y==1)
    {
        if(d==1)
        {
            x++;
            d=(d+1)%2;
        }
        else
        y++;
    }
    else
    {
        if(d)   //d==1 move left 
        y--;
        else
        y++;
    }

    r++;
    if(r>2 && t!=k)
    {
        r=1;
        t++;
    }
    ct(x,y,r,t);
}

int main()
{
    fastio;
    cin>>n>>m>>k;
    vis=0;
    ct(1,1,1,1);
    rep(i,k+1,1)
    {
        cout<<kr[i].size()<<" ";
        rep(j,kr[i].size(),0)
        cout<<kr[i][j].ff<<" "<<kr[i][j].ss<<" ";
        nl;
    }
}