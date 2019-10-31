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
        long double a,b,c,d,e,W,vol,t1;
        cin>>a>>b>>c>>W>>e>>d;
        t1=4*(pow(a,2)*pow(b,2)*pow(c,2))- pow(a,2)*pow((pow(b,2)+pow(c,2)-pow(d,2)),2) - pow(b,2)*pow((pow(c,2)+pow(a,2)-pow(e,2)),2) - pow(c,2)*pow((pow(a,2)+pow(b,2)-pow(W,2)),2) +(pow(b,2)+pow(c,2)-pow(d,2))*(pow(c,2)+pow(a,2)-pow(e,2))*(pow(a,2)+pow(b,2)-pow(W,2));
        vol=sqrt(t1)/12;
        cout<<fixed<<setprecision(4)<<vol<<endl;

    }
}
