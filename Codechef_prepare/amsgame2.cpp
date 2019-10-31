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
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}


lli gcd(lli a, lli b)
{
    if (a == 0 || b == 0)
       return 0;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

vector<lli> a(100);
map<ipair, lli> cache;
lli n;

lli f(int lp,lli cg)
{
    if(lp == n)
    {
        if(cg==1)
        return 1;
        else
        return 0;
    }

    ipair key=mp(lp,cg);
    if(cache.find(key)!=cache.end()) return cache[key];
    if(cg==0)
    {
        return cache[key]= f(lp+1,a[lp])+f(lp+1,0);
    }
    else
    return cache[key]=f(lp+1,cg)+f(lp+1,gcd(cg,a[lp]));
}

int main()
{
    fastio;
    lli t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cache.clear();
        rep(i,n,0)
        cin>>a[i];
        lli ans=0;

        ans=f(1,a[0])+f(1,0);
        cout<<ans<<endl;

    }
}