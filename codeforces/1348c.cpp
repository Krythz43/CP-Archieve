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

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,int> M;
        rep(i,n,0)M[s[i]]++;

        string ans = "";

        int f = 0;
        char ch;

        // if(k == 1){
        //     for(auto x: M){
        //         rep(i,x.ss,0)cout<<x.ff;
        //     }
        //     nl;
        //     continue;
        // }

        int z  = 0;
        for(auto x: M)ch = x.ff;
        int fleft = 0;

        for(auto x: M){

            if(fleft){rep(i,x.ss,0)ans += x.ff;continue;}

            if(x.ff == ch){
                rep(i,x.ss/k + (x.ss%k != 0),0)ans += x.ff;
                break;
            }

            if(f){
                int K = 0;
                for(auto y: M){
                    if(x.ff == y.ff)K = 1;
                    if(K) rep(i,y.ss,0)ans += y.ff;
                }
                break;
            }

            if(x.ss < k){
                z = 1;
                break;
            }

            ans += x.ff;
            fleft = x.ss - k;
            f = 1;
            if(fleft){
                rep(i,fleft,0)ans+=x.ff;
            }
        }

        if(z){
            for(auto x: M){
                rep(i,x.ss,0){
                    if(k == z)ans += x.ff;
                    z++;
                }
            }
        }

        cout<<ans<<endl;
    }
}