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
    int n,k;
    cin>>n>>k;
    vinput(a,n);
    int e,s;
    e=s=0;
    for(int i=0;i<n;i++)
    if(a[i]==1)
    e++;
    else
    s++;

    int ans=0;
    int e1=e,s1=s;
    for(int i=0;i<n;i++)
    {
        e=e1,s=s1;
        for(int j=i;j<n;j+=k)
        {
            if(a[j]==1)
            e--;
            else
            s--;
        }

        for(int j=i-k;j>=0;j-=k)
        {
            if(a[j]==1)
            e--;
            else
            s--;
        }
        ans=max(ans,(int)fabs(e-s));
    }

    cout<<ans<<endl;
}