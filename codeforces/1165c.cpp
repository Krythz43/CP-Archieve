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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'



int main()
{
    fastio;
    int n;
    string s;
    cin>>n;
    cin>>s;
    vi hash(n,0);
    int x=0,y=1;
    while(x<n && y<n)
    {
        hash[x]++;
        while(s[x]==s[y])
        {
            if(y==n)
            break;
            y++;
        }
        if(y==n)
        break;
        hash[y]++;
        x=y+1;
        y=x+1;
    }

    int ch=0;
    rep(i,n,0)
    {
        if(hash[i]==1)
        ch++;
    }
    if(ch%2)
    ch--;
    cout<<n-ch<<endl;
    // printarray(hash,n)
    rep(i,n,0)
    {
        if(ch==0)
        break;
        if(hash[i])
        {
            cout<<s[i];
            ch--;
        }
    }
    nl;
}
