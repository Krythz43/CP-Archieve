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
    int t;
    cin>>t;
    double coins=10,tu=0;
    while(t--)
    {
        // cout<<coins<<" "<<tu<<endl;

        int c;  //2 is buy coin
        double y,z;
        cin>>c>>y>>z;
        if(c==2)
        {
            
            cout<<setprecision(20)<<tu*(y/z)<<endl;
            fflush(stdout);
            coins+=tu*(y/z)-tu*(y/z)*0.0005;
            tu=0;
        }
        else
        {
            cout<<setprecision(20)<<coins<<endl;
            fflush(stdout);
            tu+=coins*(z/y)-coins*(z/y)*0.0005;
            coins=0;
        }
    }
}