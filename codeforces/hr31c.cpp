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

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    vinput(a,n);
    while(m--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        vi sum(n,0);
        sum[0]=a[0];
        rep(i,n,1)
        {
            sum[i]=sum[i-1]+a[i];
        }

        int ans=-1;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sans;
                int xi;
                for(int k=i;k<=j;k++)
                {
                    if(i==0)
                    {
                        xi=(k-i+1)*sum[k];
                    }
                    else
                    {
                        xi=(k-i+1)*(sum[k]-sum[i-1]);
                    }
                }

                if(xi>=x)
                {
                    int maxe=-1;
                    for(int r=i;r<=j;r++)
                    maxe=max(maxe,a[r]);

                    if(ans==-1)
                    {
                        ans=maxe;
                    }
                    else
                    ans=min(ans,maxe);
                }
            }
        }

        cout<<k<<endl;
    }
}