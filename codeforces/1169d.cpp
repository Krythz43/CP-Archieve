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
    string s;
    cin>>s;
    lli ans=0;
    int n=s.length();
    vi last_min(n+1,n);
    for(int i=n-1;i>=0;i--)
    {
        last_min[i]=last_min[i+1];
        for(int k=1;i+2*k<last_min[i];k++)
        {
            if(s[i]==s[i+k] && s[i+k]==s[i+2*k])
            {
                last_min[i]=min(last_min[i],i+2*k);
                break;
            }
        }
        ans+=n-last_min[i];      
    }
    cout<<ans<<endl;
}
