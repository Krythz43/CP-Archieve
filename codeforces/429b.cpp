#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    vector<vlli >  a(n,vector<lli>(m));
    rep(i,n,0)rep(j,m,0)cin>>a[i][j];
    vector<vlli> b,c,d,o;
    o=b=c=d=a;

    if(n == 1){
        lli mn = inf;
        lli ans = 0;
        rep(i,m,0){
            ans+=a[0][i];
            mn = min(mn,a[0][i]);
        }
        cout<<ans - mn<<endl;
        return 0;
    }
    else if(m == 1){
        lli mn = inf;
        lli ans = 0;
        rep(i,n,0){
            ans+=a[i][0];
            mn = min(mn,a[i][0]);
        }
        cout<<ans - mn<<endl;
        return 0;
    }

    /*
      1      4
        \ | /
        -   -
        / | \
       2      3
    */

    
    // 1 A

    rep(i,n,1)a[i][0] += a[i-1][0];
    rep(i,m,1)a[0][i] += a[0][i-1];

    rep(i,n,1)rep(j,m,1)a[i][j]+=max(a[i-1][j],a[i][j-1]);

    // 2 B

    rrep(i,n-2)b[i][0] += b[i+1][0];
    rep(i,m,1)b[n-1][i] += b[n-1][i-1];

    rrep(i,n-2)rep(j,m,1)b[i][j] += max(b[i+1][j],b[i][j-1]);

    // 3 C
    rrep(i,n-2)c[i][m-1] += c[i+1][m-1];
    rrep(j,m-2)c[n-1][j] += c[n-1][j+1];

    rrep(i,n-2)rrep(j,m-2)c[i][j] += max(c[i+1][j],c[i][j+1]);

    // 4 D

    rep(i,n,1)d[i][m-1] +=d[i-1][m-1];
    rrep(i,m-2)d[0][i]+=d[0][i+1];


    rep(i,n,1)rrep(j,m-2)d[i][j] += max(d[i-1][j],d[i][j+1]);

    // cout<<"Printing A"<<endl;
    // displaymatrix(a,n,m)
    // cout<<"Printing B"<<endl;
    // displaymatrix(b,n,m)
    // cout<<"Printing C"<<endl;
    // displaymatrix(c,n,m)
    // cout<<"Printing D"<<endl;
    // displaymatrix(d,n,m)

    lli ans = 0, temp1 = 0, temp2;
    rep(i,n,0)
    rep(j,m,0){
        temp1 = temp2 = 0;
        // Top traverser down, bottom traverser right
        if(i>0)temp1+=a[i-1][j];
        if(i<n-1)temp1+=c[i+1][j];

        if(j>0)temp1+=b[i][j-1];
        if(j<m-1)temp1+=d[i][j+1];

        // Top Traverser right, bttom taverser up

        if(j>0)temp2+=a[i][j-1];
        if(j<m-1)temp2+=c[i][j+1];

        if(i>0)temp2+=b[i-1][j];
        if(i<n-1)temp2+=d[i+1][j];

        ans=max(ans,max(temp1,temp2));
    }
    cout<<ans<<endl;
}
