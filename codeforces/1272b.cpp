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
    while(t--)
    {
        string s;
        cin>>s;
        int u,l,d,r;
        u=l=d=r=0;
        rep(i,s.length(),0){
            if(s[i]=='U')u++;
            if(s[i]=='D')d++;
            if(s[i]=='R')r++;
            if(s[i]=='L')l++;
        }
        if(u && l && r && d)
        {
            lli ans=min(u,d)+min(l,r);
            u=min(u,d);
            r=min(l,r);
            cout<<2*ans<<endl;
            rep(i,u,0)cout<<"U";
            rep(i,r,0)cout<<"R";
            rep(i,u,0)cout<<"D";
            rep(i,r,0)cout<<"L";
        }
        else if( (u && d) || (r && l)){
            cout<<2<<endl;
            if(u && d)cout<<"UD";
            else cout<<"LR";
        }
        else
        cout<<0;
        nl;
    }
}