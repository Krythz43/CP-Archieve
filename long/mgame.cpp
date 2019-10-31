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
        // int n,p;
        // cin>>n>>p;
        // lli ans=0;
        // int m=0;
        // rep(i,p+1,1)
        // m=max(m,(n%i)%n);
        // lli multi;

        // rep(i,n+1,1)
        // {
        //     if(m==n%i)
        //     {
        //         multi=max(p-m,p+1-i);
        //         ans+=multi*multi;
        //     }
        // }

        // // cout<<ans<<endl;
        // lli tans=0;
        // if(p>n)
        // {
        //     rep(i,p+1,1)
        //     {
        //         if(m==(n%i))
        //         {
        //             tans+=2*p-m-n;
        //         }
        //     }
        //     // cout<<tans<<endl;

        //     ans+=(p-n)*tans;
        //     if(m==0)
        //     ans+=(p-n)*(p-n)*(p-n);
        // }

        // cout<<ans<<endl;

        lli n,p;
        cin>>n>>p;
        if(n==1 || n==2)
        cout<<p*p*p<<endl;
        else if(n==p)
        cout<<(n/2+1)*(n/2+1)<<endl;
        else
        cout<<(n/2)*(n/2) + (n/2)*5+7 +(p-n-1)*((n/2-1)*3+15+(p-n-2)*3)<<endl;
    }
}