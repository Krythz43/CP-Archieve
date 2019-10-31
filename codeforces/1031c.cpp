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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int n,m;
int main()
{
    cin>>n>>m;
    lli lo=0,hi=1e9,mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(((mid)*(mid+1))/2<=n+m)
        lo=mid;
        else
        hi=mid;
    }
    lli ans;
    if((hi*(hi+1))/2<=n+m)
    ans=hi;
    else
    ans=lo;
    vlli a1,a2;
    lli s1=0,s2=0;
    for(int i=ans;i>0;i--)
    {
        if(s1+i>n)
        {
            a2.pb(i);
            s2+=i;
        }
        else
        {
            a1.pb(i);
            s1+=i;
        }   
    }

    cout<<a1.size()<<endl;
    printarray(a1,a1.size())
    cout<<a2.size()<<endl;
    printarray(a2,a2.size())
}