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

int main()
{
    fastio;
    int t;
    cin>>t;
    rep(p,t,0)
    {
        lli n,m,y;
        cin>>n>>m>>y;
        vector <vlli > a(n,vlli (m));
        rep(i,n,0)
        rep(j,m,0)
        {
            cin>>a[i][j];
            if(i>0)
            a[i][j]+=a[i-1][j];
            if(j>0)
            a[i][j]+=a[i][j-1];
            if(i>0 &&  j>0)
            a[i][j]-=a[i-1][j-1];
        }

        lli ma=INT_MAX,area=-INT_MAX,ta,x1,y1,f=0;

        rep(i,n,0)rep(j,m,0)
        {
            rep(k,n,i)rep(l,m,j)
            {
                lli ans=a[k][l];
                // cout<<k<<" "<<l<<endl;
                    
                if(i>0)
                ans-=a[i-1][l];
                    
                if(j>0)
                ans-=a[k][j-1];

                if(i>0 && j>0)
                ans+=a[i-1][j-1];

                // if(ans==10)
                // cout<<i<<" "<<j<<" "<<k<<" "<<l<<" \n";

                x1=k-i+1;y1=l-j+1;ta=x1*y1;

                if(ta>=area)
                {
                    if(ans<=y)
                    {
                        f++;
                        if(ta==area)
                        {
                            if(ma>ans)
                            ma=ans;
                        }
                        else
                        ma=ans;

                        area=ta;
                    }
                }
            }
        }

        // displaymatrix(a,n,m)
        if(f==0)
        area=ma=0;
        cout<<"Case #"<<p+1<<": "<<area<<" "<<ma<<endl;

    }
}