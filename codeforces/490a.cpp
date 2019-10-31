#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

vector<int> a[3];

int main()
{
    fastio;
    int n;
    cin>>n;

    vi b(4,0);

    rep(i,n,0)
    {
        int t;
        cin>>t;
        a[t-1].pb(i+1);
        b[t]++;
    }
    int ans=0;


    if(b[1] && b[2] && b[3])
    ans=min(a[0].size(),min(a[1].size(),a[2].size()));

    cout<<ans<<endl;
   // cout<<a[0].size()<<" "<<a[1].size()<<" "<<a[2].size()<<endl;
   rep(i,ans,0)
   cout<<a[0][i]<<" "<<a[1][i]<<" "<<a[2][i]<<endl;
}