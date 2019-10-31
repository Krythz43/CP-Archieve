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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

vector <int> s;

void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          s.pb(p); 
} 
  

int main()
{
    fastio;
    int n;
    cin>>n;
    vi a(n);

    rep(i,n,0)
    cin>>a[i];
    int gcd;
    gcd=__gcd(a[0],a[1]);

    rep(i,n,2)
    {
        gcd=__gcd(gcd,a[i]);
    }

    int maxe=a[0]/gcd;

    rep(i,n,0)
    {
        a[i]/=gcd;
        maxe=max(a[i],maxe);
    }
    SieveOfEratosthenes(5000); 

    int ans=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>maxe)
        break;
        int c=0;
        rep(j,a.size(),0)
        {
            if(a[j]%s[i]==0)
            c++;
        }
        ans=max(c,ans);
    }
    if(ans==0)
    cout<<-1;
    else
    cout<<n-ans;
}