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

int ind=0;
vlli a;
int n;

bool F(lli k)
{
    lli id=0;
    rep(i,n,0)
    {
        if(k*id>a[i])
        return false;
        id++;
    }
    id=0;
    for(int i=n-1;i>=0;i--)
    {
        if(k*id>a[i])
        return false;
        id++;
    }

    return true;
}


int main()
{
    fastio;
    cin>>n;
    a.resize(n);
    ainput(a,n);
    lli hi=1e9+5,lo=0,mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(F(mid))
        lo=mid;
        else
        hi=mid;
        // cout<<hi<<" "<<lo<<endl;
    }

    if(F(hi))
    cout<<hi;
    else cout<<lo;
    nl;

}
