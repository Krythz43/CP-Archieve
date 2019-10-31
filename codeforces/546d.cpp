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

const lli S = 5000005;
vlli prime_div(S,0);
vlli prime_fac(S,0);
vlli ans(S,0);

void precal(){
    for(lli i=2;i<S;i++){
        if(!prime_div[i]){
            for(lli j=i;j<S;j+=i){
                lli temp = j;
                while(temp%i == 0){
                    prime_div[j]++;
                    temp/=i;
                }
            }
        }
    }
    rep(i,S,2)ans[i]=ans[i-1]+prime_div[i];
}


int main()
{
    fastio;
    int t;
    cin>>t;
    precal();

    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<ans[a]-ans[b]<<endl;
    }

    // rep(i,11,0)cout<<i<<" = "<<prime_div[i]<<endl;
}