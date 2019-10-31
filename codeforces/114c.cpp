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
// #define endl '\n'

const lli S=1e6+9;
bool prime[S]; 

bool isPrime(lli n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (lli i = 2; i*i <= n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int main()
{
    fastio;
    lli n,b;
    cin>>n>>b;
    vector<lli> fact;
    lli st=b;
    for(lli i=2;i*i<=b;i++)
    {
        if(b%i)
            continue;
        while(b%i==0)
            b/=i;
        fact.push_back(i);
    }
    if(b!=1)
        fact.push_back(b);
    b=st;

    lli ans=1e18;
    if(fact.size()==0)
    fact.pb(b);
    // cout<<fact.size()<<endl;
    // printarray(fact,fact.size());

    for(int i=0;i<fact.size();i++)
    {
        lli c1=0,c2=0;
        lli x=fact[i];
        lli y=b;
        // cout<<y<<" "<<fact[i]<<endl;
        while(y)
        {
            if(y%x==0)
            {
                c1++;
                y/=x;
            }
            else
            break;
        }

        y=n;
        while(y)
        {
            c2+=y/x;
            y/=x;
        }

        // cout<<x<<" "<<c1<<" "<<c2<<endl;

        if(c1!=0)
        ans=min(ans,c2/c1);
    }

    if(ans==1e18)
    ans=0;
    cout<<ans<<endl;


}