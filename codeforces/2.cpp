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
#define endl '\n'

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vi row(n+1,0),col(n+1,0);
        int x,y;
        vector<ipair> ans;
        rep(i,k,0)
        {
            cin>>x>>y;
            row[x]++;
            col[y]++;
        }

        int p1=1,p2=1;
        while(p1<=n && p2<=n)
        {
            if(row[p1]==0 && col[p2]==0)
            {
                ans.pb(mp(p1,p2));
                p1++;
                p2++;
                // cout<<"s1"<<endl;
            }
            else
            {
                if(row[p1]!=0)
                p1++;
                if(col[p2]!=0)
                p2++;
                // cout<<"s2"<<endl;
            }
        }
        cout<<ans.size()<<" ";
        rep(i,ans.size(),0)
        {
            cout<<ans[i].ff<<" "<<ans[i].ss<<" ";
        }
        nl;
    }
}