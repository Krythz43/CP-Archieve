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
    for(int t=1;;t++)
    {
        int n;
        cin>>n;
        if(n==0)
        break;

        lli a[n][3];
        rep(i,n,0)
        rep(j,3,0)
        cin>>a[i][j];

        a[n-1][0]+=a[n-1][1];
        a[n-2][2]+=a[n-1][1];
        a[n-2][1]+=min(a[n-1][1],min(a[n-1][0],a[n-2][2]));
        a[n-2][0]+=min(a[n-1][1],min(a[n-1][0],a[n-2][1]));

        for(int i=n-3;i>=0;i--)
        {
            a[i][2]+=min(a[i+1][1],a[i+1][2]);
            a[i][1]+=min(a[i+1][1],min(a[i+1][0],min(a[i+1][2],a[i][2])));
            a[i][0]+=min(a[i+1][1],min(a[i+1][0],a[i][1]));
        }

        cout<<t<<". "<<a[0][1]<<endl;
    }
}
