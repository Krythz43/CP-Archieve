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

lli mod=1e9+7;

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        lli n,k;
        cin>>n>>k;
        vlli ans(k);
        int r=2;
        lli sum=0;
        rep(i,k,0)
        {
            ans[i]=r;
            r++;
            sum+=ans[i];
        }
        
        if(sum-k>n)
        cout<<-1<<endl;
        else if(sum>n)
        cout<<0<<endl;
        else
        {
            n-=sum;
            lli z;
            z=n/k;
            rep(i,k,0)
            ans[i]+=z;
            n-=z*k;
            r=k-1;
            while(n)
            {
                ans[r]++;
                n--;
                r--;
            }
            lli fans=1;
            rep(i,k,0)
            {
                fans=((fans%mod)*(((ans[i]%mod)*((ans[i]-1)%mod))%mod))%mod;
            }
            cout<<fans<<endl;
        }
    }
}