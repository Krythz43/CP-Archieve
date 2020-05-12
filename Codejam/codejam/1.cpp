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

int main()
{
    fastio;
    int t;
    cin>>t;
    rep(o,t,0)
    {
        int n,k;
        cin>>n>>k;
        vi a(n);

        rep(i,n,0)
        cin>>a[i];

        sort(a.begin(),a.end());

        int d=1,cc=0,ans=0;

        rep(i,n,0)
        {
            if(a[i]>=d)
            {
                ans++;
                cc++;
            }
            if(cc==k)
            {
                d++;
                cc=0;
            }
        }

        cout<<"Case #"<<o+1<<": "<<ans<<endl;
    }
}