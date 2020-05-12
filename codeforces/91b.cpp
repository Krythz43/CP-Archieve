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
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

vlli a;
vlli tilh;


int main()
{
    fastio;
    int n;
    cin>>n;
    a.resize(n);
    ainput(a,n);
    reverse(all(a));
    lli mn = inf;

    for(auto x:a){
        mn = min(x,mn);
        tilh.pb(mn);
    }

    reverse(all(a));
    reverse(all(tilh));

    vlli ans(n,-1);

    rep(i,n-1,0){
        lli lo = i+1,hi = n-1;
        lli mid = (lo+hi)/2;

        while(hi-lo>1){
            mid = (lo+hi)/2;
            if(a[i] > tilh[mid])lo=mid;
            else hi = mid;
        }

        if(a[hi] < a[i])ans[i]=(hi-i-1);
        else if(a[lo] < a[i])ans[i]=(lo-i-1);
    }

    printarray(ans,n)

}