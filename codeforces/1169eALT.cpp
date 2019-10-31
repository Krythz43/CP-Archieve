#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'


typedef long long ll; 
const int N = 3e5 + 7;
const int LG = 20;
 
int go[N][LG];
int a[N];
int last[LG];
 
int main() 
{
    fastio;
    int n,q,x,y;
    cin>>n>>q;
    ainput(a,n);

    rep(i,LG,0)
    last[i]=n;

    rep(i,n+5,0)
    rep(j,LG,0)
    go[i][j]=n;

    for(int i=n-1;i>=0;i--)
    {
        rep(j,LG,0)
        {
            if(((a[i]>>j)&1))
            {
                rep(k,LG,0)
                {
                    go[i][k]=min(go[i][k],go[last[j]][k]);
                    // cout<<last[j]<<" ";
                }
                last[j]=i;
                go[i][j]=i;
            }
        }
    }
    // rep(i,n,0)
    // {
    //     rep(j,LG,0)
    //     cout<<go[i][j]<<" ";
    //     nl;
    // }

    while(q--)
    {
        cin>>x>>y;
        x--,y--;
        int ans=0;
        rep(i,LG,0)
        ans|=(((a[y]>>i)&1) && go[x][i]<=y);
        cout<<(ans?"Shi":"Fou")<<endl;
    }
}