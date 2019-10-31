#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,d) for(int i=d;i<n;i++)
#define rrep(i,d) for(int i=d;i>=0;i--)
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


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        rep(n,100,1)
        rep(p,100,n)
       {
        // int n,p;
        // cin>>n>>p;
           int m=0;
       rep(i,p+1,1)
       rep(j,p+1,1)
       rep(k,p+1,1)
       m=max(m,(((n%i)%j)%k)%n);
       lli ans1=0;
       rep(i,p+1,1)
       rep(j,p+1,1)
       rep(k,p+1,1)
       if((((n%i)%j)%k)%n==m)
       {
        //    printf("%d %d %d\n",i,j,k);
           ans1++;
        }

        //////////////////////////////////////////////////////////////


        lli ans=0;
        // // int m=0;
        rep(i,p+1,1)
        m=max(m,(n%i)%n);
        lli multi;

        rep(i,n+1,1)
        {
            if(m==n%i)
            {
                multi=max(p-m,p+1-i);
                ans+=multi*multi;
            }
        }

        cout<<ans<<endl;
        lli tans=0;
        if(p>n)
        {
            rep(i,p+1,1)
            {
                if(m==(n%i))
                {
                    tans+=2*p-m-n;
                }
            }
            // cout<<tans<<endl;

            ans+=(p-n)*tans;
            if(m==0)
            ans+=(p-n)*(p-n)*(p-n);
        }

        if(ans!=ans1)
        {printf("WA at %d,%d when %d should have come at %d\n",n,p,ans1,ans);
        return 0;}
        else
        cout<<"correct"<<n<<endl;
    }
    }
}