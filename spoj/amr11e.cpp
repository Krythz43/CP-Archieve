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

#define SIZE 4000

vector<bool>prime(SIZE,true);
vector<int>primes;

void SieveOfEratosthenes(int n) 
{
    for (int p=2; p*p<=n; p++) 
    if (prime[p] == true) 
    {   
        for (int i=p*p; i<=n; i += p) 
        prime[i] = false; 
    } 
} 

int main()
{
    fastio;
    int t;
    cin>>t;
    SieveOfEratosthenes(SIZE);
    rep(i,SIZE,2)
    if(prime[i])
    primes.pb(i);

    vector<int> ans;
    rep(i,SIZE,2)
    {
        int c=0;
        rep(j,primes.size(),0)
        {
            if(i<primes[j])
            break;
            if(i%primes[j]==0)
            c++;
        }
        if(c>2)
        ans.pb(i);
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n-1]<<endl;
    }
}
