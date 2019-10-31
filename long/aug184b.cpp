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
lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli mod=1e9+7;
lli mod1=1e9+7;


lli multi(lli x,lli n)
{
    x%=mod;

    if(n==1)
    return x%mod;
    
    if(n%2)
    {
        return ((x%mod)*((multi(((x%mod)*(x%mod))%mod,(n-1)/2))%mod)%mod)%mod;
    }
    else
    return multi(((x%mod)*(x%mod))%mod,n/2)%mod;
}

lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {   
        lli a,b,n,ap,bp;
        lli ans;
        cin>>a>>b>>n;


        if((a-b)==0)
        {
            mod=1e9+7;
            ap=multi(a,n)%mod;
            ans=(2*ap)%mod;
        }
        else    
        {
            mod=(a-b);
            // cout<<"Check:"<<a<<" "<<b<<" "<<mod<<endl;
            ap=multi(a,n);
            bp=multi(b,n);
            // cout<<"Check:"<<ap<<" "<<bp<<endl;
            ans=gcd(mod,(ap+bp)%mod);
        }

        cout<<ans%mod1<<endl;
    }
}