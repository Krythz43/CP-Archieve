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
    int n,q;
    int t=1;
    while(1)
    {
        cin>>n>>q;
        if(n==0 && q==0)
        break;
        vi a(n);
        rep(i,n,0)
        cin>>a[i];
        sort(a.begin(),a.end());
        
        cout<<"CASE# "<<t<<":"<<endl;
        t++;
        int x;
        while(q--)
        {
            cin>>x;
            int ans=lower_bound(a.begin(),a.end(),x)-a.begin();
            if(a[ans]==x)
            cout<<x<<" found at "<<ans+1<<endl;
            else
            cout<<x<<" not found"<<endl;
        }
    }
}