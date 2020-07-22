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
// #define endl '\n'

const lli mod = 1e9 + 7;

lli solve(lli x){
    lli taken = 0;
    lli ans = 0;
    lli tt = 1;
    lli lso = 1;
    lli lse = 2;

    int turn = 1;

    lli a,l,sum;

    while(1){
        if(taken + tt > x)tt = x - taken;
        if(tt == 0)break;
        
        if(turn&1){
            a = lso;
            l = lso + 2*(tt - 1);
            sum = a + l;
            sum /= 2;
            sum%= mod;
            sum = (sum*(tt%mod))%mod;
            ans = (ans + sum)%mod;
            lso = l + 2;
        }
        else{
            a = lse;
            l = lse + 2*(tt - 1);
            sum = a + l;
            sum /= 2;
            sum%= mod;
            sum = (sum*(tt%mod))%mod;
            ans = (ans + sum)%mod;
            lse = l + 2;
        }

        turn ^= 1;
        taken += tt;
        tt *= 2;
    }
    return ans;
}

int main()
{
    fastio;
    lli l,r;
    cin>>l>>r;
    cout<<( (solve(r) - solve(l - 1))%mod + mod)%mod<<endl;

    // while(1){
    //     cin>>l;
    //     cout<<solve(l)<<endl;
    // }
}