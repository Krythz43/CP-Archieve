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

int main()
{
    fastio;
    lli n,k,a,b;
    cin>>n>>k>>a>>b;
    lli mx=1<<n;
    vinput(arr,k);
    SO(arr);

    function<lli(int,int)> F=[&](int lo,int hi)->lli
    {
        lli av=upper_bound(arr.begin(),arr.end(),hi) - lower_bound(arr.begin(),arr.end(),lo);
        if(lo==hi)
        {
            if(av)
            return b*av;
            else
            return a;
        }

        if(av)
        return min(b*(hi-lo+1)*av,F(lo,lo+(hi-lo)/2)+F(lo+(hi-lo)/2+1,hi));
        else
        return a;
    };
    cout<<F(1,mx)<<endl;
}