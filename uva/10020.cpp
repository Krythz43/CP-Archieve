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
    int m,t;
    cin>>t;
    while(t--)
    {
        cin>>m;
        vector<ipair > a,ans;
        int x,y;
        while(1)
        {
            cin>>x>>y;
            if(x==0 && y==0)
            break;
            else
            a.pb(mp(x,y));
        }

        sort(a.begin(),a.end());
        ipair bp,lp;
        bp.ff=-INT_MAX;
        bp.ss=0;
        lp=bp;
        int be=0;

        rep(i,a.size()-1,0)
        {
            if(a[i].ff>be || a[i].ff>=m)
            {break;
            // cout<<"breaking";
            }
            else
            {
                // cout<<"loop:"<<a[i].ff<<" "<<a[i].ss<<" "<<be<<endl;
                if(a[i].ss>be && a[i].ff<=be)
                {
                    bp=a[i];
                    be=a[i].ss;
                }

                if(a[i+1].ff>lp.ss)
                {   
                    ans.pb(bp);
                    lp=bp;
                }
            }
        }

        int n=a.size();
        if(be<m && a[n-1].ss>be && a[n-1].ff<=bp.ss)
        {ans.pb(a[n-1]);
        be=a[n-1].ss;
        // cout<<"adding last";
        }

        // cout<<"best ending "<<be<<endl;
        if(ans.size()==0 || be<m)
        cout<<"0"<<endl;
        else
        {
            cout<<ans.size()<<endl;
            rep(i,ans.size(),0)
            cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
        }
        nl;
    }

}