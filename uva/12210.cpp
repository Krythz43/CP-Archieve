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
    int b,s;
    int t=1;
    for(;;t++)
    {
        cin>>b>>s;
        if(b==0 && s==0)
        break;
        int n=0,ans=0;
        vi a(b),c(s);
        rep(i,b,0)
        cin>>a[i];
        rep(i,s,0)
        cin>>c[i];


        if(b-s>=0)
        {
            n=min(1,b-s);
            ans=b-s;
        }
        sort(a.begin(),a.end());
        cout<<"Case "<<t<<": "<<ans;
        if(n==1)
        cout<<" "<<a[0];
        nl;
    }
}