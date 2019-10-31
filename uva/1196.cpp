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
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)
        {
            cout<<"*"<<endl;
            break;
        }
        
        vector  <ipair> a;
        int x,y;
        rep(i,n,0)
        {
            cin>>x>>y;
            a.pb(mp(x,y));
        }

        sort(a.begin(),a.end());

        vi lis(n,1);

        rep(i,n,1)
        {
            rep(j,i,0)
            {
                if(a[i].ss>=a[j].ss)
                lis[i]=max(lis[i],lis[j]+1);
            }
        }

        int ma=1;

        rep(i,n,1)
        {
            ma=max(ma,lis[i]);
        }

        cout<<ma<<endl;
    }
}