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
    int n,c;
    cin>>n>>c;
    int lo=0,hi=n;
    int hash[150005];
    memset(hash,-1,sizeof hash);
    hash[0]=0;
    int dl=1e4;
    int stat=0;
    
    while(hi-lo>1 && dl>0)
    {
        if(stat)
        {
            cout<<2<<endl;
            cout<<flush;
            stat=0;
        }
        int x=lo,y;
        
        while(x<hi)
        {

            if(hash[x]!=-1)
            {
                if(hash[x]==0)
                {
                    lo=x;
                    x+=dl;
                }
                else
                {
                    hi=x;
                    break;
                }
            }
            else
            {
                cout<<1<<" "<<x<<endl;
                cout<<flush;
                cin>>y;
                hash[x]=y;
                stat=y;
                if(y)
                {
                    hi=x;
                    break;
                }
                else
                {
                    lo=x;
                    x+=dl;
                }
            }
        }

        dl/=10;
    }

    if(stat)
    {
        cout<<2<<endl;
        cout<<flush;
        stat=0;
    }

    cout<<3<<" "<<hi<<endl;
    cout<<flush;
}