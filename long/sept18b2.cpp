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
    while(t--)
    {
        int n,m,x,y,n1,n2;
        cin>>n>>m>>x>>y;
        n--;
        m--;
        n1=n-1;
        n2=m-1;
        int flag=0;

        n%=x;
        m%=y;

        if(n1!=-1)
        n1%=x;

        if(n2!=-1)
        n2%=y;


        if((n==0 && m==0) || (n1==0 && n2==0))
        cout<<"Chefirnemo";
        else
        cout<<"Pofik";

        // cout<<" "<<n<<" "<<m<<" "<<n1<<" "<<n2;
        nl;
    }
}