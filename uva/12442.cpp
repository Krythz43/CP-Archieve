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
const int N=50005;
bool vis[N];
int a[N],ans[N];
int ca=0;

void dfs(int i)
{
    cout<<"Rountinw runnign"<<endl;
    ca++;
    vis[i]=true;
    if(vis[a[i]]==false)
    dfs(a[i]);
}
int main()
{
    fastio;
    int t;
    cin>>t;
    rep(o,t,0)
    {
        int n;
        cin>>n;
        vi a(n+1);
        memset(vis,false, sizeof vis);
        int x,y;
        rep(i,n+1,1)
        {
            cin>>x>>y;
            a[x]=y;
        }
        int fans=0,fi=1;
        memset(vis,false, sizeof vis);
        memset(ans,0, sizeof ans);
        rep(i,n+1,1)
        {
            ca=0;
            if(vis[i]==false)
            {
                dfs(i);
                ans[i]=ca;
            }
            else
            {
                ans[i]=ans[a[i]]+1;
            }
            if(fans<ans[i])
            {
                fans=ans[i];
                fi=i;
            }
            
        }

        cout<<"Case "<<o+1<<": "<<fi<<endl;
    }
}