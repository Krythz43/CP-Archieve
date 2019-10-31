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
    int n;
    cin>>n;
    vinput(a,n);
    SO(a);
    int ans1,ans2;
    ans1=ans2=1;
    if(a[n-2]==a[n-1])
    {
        cout<<a[n-1]<<" "<<a[n-1]<<endl;
        return 0;
    }
    else
    ans1=a[n-1];

    for(int i=n-2;i>=0;i--)
    {
        if(__gcd(ans1,a[i])!=a[i])
        {
            ans2=a[i];
            cout<<ans1<<" "<<ans2<<endl;
            return 0;
        }
    }

    for(int i=n-1;i>0;i--)
    {
        if(a[i]==a[i-1])
        {
            cout<<ans1<<" "<<a[i]<<endl;
            return 0;
        }
    }
}