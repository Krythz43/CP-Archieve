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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int b[n][m];
    rep(i,n,0)
    rep(j,m,0)
    cin>>a[i][j];
    rep(i,n,0)
    rep(j,m,0)
    cin>>b[i][j];


    rep(i,n,0)
    rep(j,m,0)
    if (a[i][j] > b[i][j])
    swap(a[i][j],b[i][j]);


    rep(i,n,0)
    rep(j,m,0)
    {
        if (i>0) 
        {
            if (a[i][j]<=a[i - 1][j]) 
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
        if (j>0 && a[i][j]<=a[i][j - 1]) 
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
        
    rep(i,n,0)
    rep(j,m,0)
    {
        if (i>0) 
        {
            if (b[i][j]<=b[i - 1][j]) 
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
        if (j>0 && b[i][j]<=b[i][j - 1]) 
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }


    cout<<"Possible"<<endl;
}
