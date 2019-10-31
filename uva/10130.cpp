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


int memo[1005][35];
vector <ipair > a;
int n;

int value(int id, int mp)
{
    if(id==n || mp==0)
    return 0;
    if(memo[id][mp]!=-1)return memo[id][mp];
    if(a[id].ss>mp)  return memo[id][mp]=value(id+1,mp);
    else
    return memo[id][mp]=max(value(id+1,mp),a[id].ff+value(id+1,mp-a[id].ss));
}

int main()
{
    fastio;
    int  t;
    cin>>t;
    while(t--)
    {
            memset(memo,-1,sizeof memo);
            a.clear();
            cin>>n;
            int x,y;
            rep(i,n,0)
            {
                cin>>x>>y;
                a.pb(mp(x,y));
            }

            int q,w,ans=0;
            cin>>q;
            while(q--)
            {
                cin>>w;
                ans+=value(0,w);
            }
            cout<<ans<<endl;            
    }
}