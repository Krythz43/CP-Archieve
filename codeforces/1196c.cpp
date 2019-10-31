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

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        lli x,y,f1,f2,f3,f4;
        int f=1;
        lli xmax,xmin,ymax,ymin;
        xmax=ymax=inf;
        xmin=ymin=-inf;

        rep(i,n,0){
            cin>>x>>y>>f1>>f2>>f3>>f4;
            if(!f1){
                if(x>xmax)f=0;
                else xmin=max(xmin,x);
            }
            if(!f3){
                if(x<xmin)f=0;
                else xmax=min(xmax,x);
            }

            if(!f4){
                if(y>ymax)f=0;
                else ymin=max(y,ymin);
            }
            if(!f2){
                if(y<ymin)f=0;
                else ymax=min(y,ymax);
            }

        }

        // nl;
        // cout<<xmax<<" "<<xmin<<" "<<ymax<<" "<<ymin<<endl;

        if(f){
            if(xmin<=xmax && ymin<=ymax){
                cout<<"1 "<<max(xmin,-100000LL)<<" "<<max(ymin,-100000LL)<<endl;
            }
            else cout<<0<<endl;
        }
        else
        cout<<f<<endl;
    }
}