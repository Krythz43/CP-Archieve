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

const lli S=1e6+5;
bool prime[S];
vlli primes;

void SieveOfEratosthenes(int n) 
{ 
    rep(i,n+1,1)prime[i]=true;
 
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i)prime[j]=false;
        }
    }

    for(int i=1;i<=n;i++)if(prime[i])primes.pb(i);
} 
  

int main()
{
    fastio;
    int t,cd=0;
    cin>>t;
    vlli pos;
    pos.pb(1);

    rep(i,1e6+2,2){
        int ed=0,od=0;
        vlli div;
        for(int j=1;j<=sqrt(i);j++){
            if(i%j==0){
                if(i/j==j){
                    div.pb(j);
                }
                else{
                    div.pb(j);
                    div.pb(i/j);
                }
            }
        }

        for(auto x:div){
            if(x&1)ed++;
            else od++;
        }


        if(abs(ed-od)<=2){
            pos.pb(i);
        }
    }

    rep(Q,t+1,1){
        int l,r;
        cin>>l>>r;
        cout<<"Case #"<<Q<<": "<<upper_bound(all(pos),r)-lower_bound(all(pos),l)<<endl;
    }
}