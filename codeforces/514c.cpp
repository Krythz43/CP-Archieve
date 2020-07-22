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

const lli mod = 100000000000000003;

int main()
{
    fastio;
    // cout<<mod<<endl;

    int n,m;
    cin>>n>>m;

    string s;
    map<lli,lli> M;

    lli p = 5,hs;
    rep(i,n,0){
        cin>>s;
        hs = 0;
        for(char c: s)hs = (hs*p + (c - 'a' + 1))%mod;
        M[hs]++;
        // cout<<"hash of "<<i<<" = "<<hs<<endl;
    }

    lli pow[600005];
    pow[0] = 1;
    rep(i,6e5+5,1)pow[i] = p*pow[i - 1]%mod;

    // rep(i,12,0)cout<<pow[i]<<" ";
    // nl;

    rep(T,m,0){
        cin>>s;
        hs = 0;
        for(char c: s)hs = (hs*p + (c - 'a' + 1))%mod;

        char c;

        int f = 0;
        lli tp = 0,rp = 0;
        int l = s.length();
        rep(i,s.length(),0){
            c = s[i];
            rp = hs - (c - 'a' + 1)*pow[l - 1 - i]%mod;
            if(rp < 0)rp += mod;
            rep(k,4,1){
                if(k == (c - 'a' + 1))continue;
                tp = rp + k*pow[l - 1 - i];
                tp %= mod;
                if(M.count(tp)){
                    // cout<<"Answer found by changing at place "<<i<<" to "<<k<<" "<<tp<<endl;
                    f = 1;
                    break;
                }
            }
            if(f)break;
        }

        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}