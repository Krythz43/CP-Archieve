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

int main()
{
    fastio;
    int n;
    while(cin>>n)
    {
    vector <vi > a(n, vector <int>  (n));

    rep(i,n,0)
    rep(j,n,0)
    {
        cin>>a[i][j];
        if(i>0)
        a[i][j]+=a[i-1][j];
        if(j>0)
        a[i][j]+=a[i][j-1];
        if(i>0 && j>0)
        a[i][j]-=a[i-1][j-1];
    }

    int maxe=-INT_MAX;
    rep(i,n,0)
    {
        rep(j,n,0)
        {
            rep(k,n,i)
            {
                rep(l,n,j)
                {
                    int ans=a[k][l];
                    // cout<<k<<" "<<l<<endl;
                    
                    if(i>0)
                    ans-=a[i-1][l];
                    
                    if(j>0)
                    ans-=a[k][j-1];

                    if(i>0 && j>0)
                    ans+=a[i-1][j-1];

                    maxe=max(maxe,ans);
                }
            }
        }
    }
    cout<<maxe<<endl;}
}