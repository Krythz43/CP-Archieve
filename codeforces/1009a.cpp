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
    int n,m;
    cin>>n>>m;
    vi a(n);
    rep(i,n,0)
    cin>>a[i];
    vi b(m);

    rep(i,m,0)
    cin>>b[i];

    int ai=0,bi=0,c=0;

    while(1)
    {
        if(a[ai]<=b[bi])
        {
            c++;
            ai++;
            bi++;
        }
        else
        {
            ai++;
        }

        if(ai==n || bi==m)
        break;
    }

    cout<<c;
}