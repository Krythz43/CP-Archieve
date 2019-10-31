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

int n,q;
int maxd=3e6;

int main()
{
    fastio;
    int n,q;
    cin>>n>>q;
    long double x,y,ra,l,r,d;
    vector<pair<ipair,int> > a;
    vi ran(maxd,0);
    int maxind=-inf;

    rep(i,n,0)
    {
        cin>>x>>y>>ra;
        a.pb(mp(mp(x,y),ra));
    }
    rep(i,n,0)
    {
        rep(j,n,i+1)
        {
            int r1=a[i].ss;     //r1 is greater
            int r2=a[j].ss;

            if(r1<r2)swap(r1,r2);
            d=sqrt(  (a[i].ff.ff-a[j].ff.ff)*(a[i].ff.ff-a[j].ff.ff)   +   (a[i].ff.ss-a[j].ff.ss)*(a[i].ff.ss-a[j].ff.ss));
            int d1=(int)d;

            int f=1;

            if( d1*d1 == (a[i].ff.ff-a[j].ff.ff)*(a[i].ff.ff-a[j].ff.ff)   +   (a[i].ff.ss-a[j].ff.ss)*(a[i].ff.ss-a[j].ff.ss))
            f=0;


            if(d>=r1+r2)     
            {
                ran[d1-r1-r2+f]++;
                ran[d1+r1+r2+1]--;
                maxind=max(maxind,d1+r1+r2+1);
                // cout<<maxind<<endl;
            }
            else if(a[i].ff.ff==a[j].ff.ff && a[i].ff.ss==a[j].ff.ss)
            {
                ran[r1-r2]++;
                ran[r1-r2+1]--;
                maxind=max(maxind,r1-r2+1);
            }
            else if(d>=r1-r2 && d<r1+r2)
            {
                ran[0]++;
                ran[d1+r1+r2+1]--;
                maxind=max(maxind,d1+r1+r2+1);
            }
            else if(d<r1-r2)
            {
                // ((d<(max-min))&&((dist<(max+min+d)&&dist>(max-min-d))))||
                ran[r1-r2-d1]++;    // 5,3,0.5
                ran[d1+r1+r2+1]--;  
                maxind=max(maxind,d1+r1+r2+1);
            }
            else
            {
                cout<<3/0;
            }
        }
    }

    // printarray(ran,maxind+2)

    int z=0,k;
    rep(i,maxind+2,0)
    {
        z+=ran[i];
        ran[i]=z;
    }

    while(q--)
    {
        cin>>k;
        cout<<ran[k]<<endl;
    }

    // while(q--)
    // {
    //     int dis;
    //     cin>>dis;

    //     int c=0;

    //     rep(i,n,0)
    //     {
    //         rep(j,n,i+1)
    //         {
    //             int r1=a[i].ss;     //r1 is greater
    //             int r2=a[j].ss;

    //             if(r1<r2)swap(r1,r2);
    //             d=sqrt(  (a[i].ff.ff-a[j].ff.ff)*(a[i].ff.ff-a[j].ff.ff)   +   (a[i].ff.ss-a[j].ff.ss)*(a[i].ff.ss-a[j].ff.ss));
                
                
    //             if(d>=r1+r2 && dis>=d-r1-r2 && dis<=d+r1+r2)
    //             c++;
    //             else if(a[i].ff.ff==a[j].ff.ff && a[i].ff.ss==a[j].ff.ss)
    //             {
    //                 if(dis==r1-r2)
    //                 c++;
    //             }
    //             else if(d>=r1-r2 && d<r1+r2)
    //             {
    //                 if(dis<=d+r1+r2)
    //                 c++;
    //             }
    //             else if(d<r1-r2)
    //             {
    //                 if(dis<=d+r1+r2 && dis>=r1-r2-d)
    //                 c++;
    //             }
                
    //         }
    //     }
    //     cout<<c<<endl;
    // }
}

