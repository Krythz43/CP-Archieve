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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'



int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        vi a,b;
        int x,ans=0;
        a.pb(0);
        while(1)
        {
            cin>>x;
            if(x)
            a.pb(x);
            else
            break;
        }

        while(1)
        {
            b.clear();
            cin>>x;
            if(x==0)
            break;
            b.pb(0);
            b.pb(x);
            while(1)
            {
                cin>>x;
                if(x)
                b.pb(x);
                else
                break;
            }
            
            int t1[a.size()][b.size()],z;
            memset(t1,0,sizeof t1);


            rep(i,a.size(),1)
            {
                rep(j,b.size(),1)
                {
                    t1[i][j]=max(t1[i-1][j],t1[i][j-1]);
                    if(a[i]==b[j])
                    t1[i][j]=t1[i-1][j-1]+1;
                }
            }
            // displaymatrix(t1,a.size(),b.size())
            ans=max(ans,t1[a.size()-1][b.size()-1]);
        }
        cout<<ans<<endl;
    }
}
