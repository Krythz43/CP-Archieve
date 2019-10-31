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

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    vi a[100005];

    int x,y;
    rep(i,m,0)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    if(n==1)
    cout<<"NO"<<endl;
    else
    {
        rep(i,n+1,1)
        {
            if(a[i].size()!=n-1)
            {
                cout<<"YES"<<endl;
                int k=-1;
                a[i].pb(i);
                SO(a[i]);

                while(a[i].size()!=n)
                {
                    a[i].pb(0);
                }
                rep(j,a[i].size(),0)
                {
                    if(a[i][j]!=j+1)
                    {
                        k=j+1;
                        // cout<<"setting k at:"<<k<<" as "<<a[i][j]<<" is not equal to "<<j+1<<endl;
                        break;
                    }
                    // else
                    // cout<<"safe check at "<<j<<endl;
                }

                // cout<<"change at "<<i<<","<<k<<" at size "<<n<<endl;
                rep(j,n,0)
                cout<<j+1<<" ";
                nl;
                rep(j,n,0)
                {
                    if(j==k-1)
                    {
                        if(j==0)
                        cout<<j+2<<" ";
                        else
                        cout<<j<<" ";
                    }
                    else
                    cout<<j+1<<" ";
                }
                nl;
                return 0;
            }
        }
        cout<<"NO"<<endl;
    }
}