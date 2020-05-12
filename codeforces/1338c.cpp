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


llipair solve(lli bit, lli loc){
    if(bit == 0)return {1,2};

    lli cur = (1LL << (bit - 2));
    auto ans = solve(bit - 2, loc%cur);
    ans.ff ^= (1LL<<(bit - 2));
    ans.ss ^= (1LL<<(bit - 1));
    loc /= cur;

    if (loc == 1) {
        ans.ff ^= (1LL << (bit - 2));
        ans.ss ^= (1LL << (bit - 1));
    }
    if (loc == 2) {
        ans.ff ^= (1LL << (bit - 1));
        ans.ss ^= (1LL << (bit - 1)) ^ (1LL << (bit - 2));
    }
    if (loc == 3) {
        ans.ff ^= (1LL << (bit - 1)) ^ (1LL << (bit - 2));
        ans.ss ^= (1LL << (bit - 2));
    }
    ans.ff ^= 1LL << bit;
    ans.ss ^= 1LL << (bit + 1);
    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;

    while(t--){
        lli n, N;
        cin>>n;
        N = n;
        N--;

        lli bit,sum = 0;
        n = (n-1) / 3;
        for(bit = 0 ; ; bit += 2){
            sum = (1LL << bit);
            if(sum > n){
                auto ans = solve(bit,n);
                if(N%3 == 0)cout<<ans.ff<<endl;
                else if(N%3 == 1)cout<<ans.ss<<endl;
                else cout<<(ans.ff^ans.ss)<<endl;
                break;
            }
            n -= sum;
        }
    }
}