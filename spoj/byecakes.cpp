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
    while(1)
    {
        int a,b,c,d,_a,_b,_c,_d;
        cin>>a>>b>>c>>d>>_a>>_b>>_c>>_d;
        if(a==-1)
        break;
        int macake=0,t;
        t=d/_d;
        if(d%_d)
        t++;
        macake=max(t,macake);
        t=c/_c;
        if(c%_c)
        t++;
        macake=max(t,macake);
        t=b/_b;
        if(b%_b)
        t++;
        macake=max(t,macake);
        t=a/_a;
        if(a%_a)
        t++;
        macake=max(t,macake);
        cout<<macake*_a-a<<" ";
        cout<<macake*_b-b<<" ";
        cout<<macake*_c-c<<" ";
        cout<<macake*_d-d<<" ";
        nl;
    }
}
