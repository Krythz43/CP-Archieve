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
    // 10
    // 3 6 9 15 19 21 24  47 56 72
    fastio;
    int n,q;
    cin>>n;
    vi a(n);
    rep(i,n,0)
    cin>>a[i];
    cin>>q;
    while(q--)
    {
        int z,a1=-1,a2=-1;
        cin>>z;
        int x=lower_bound(a.begin(),a.end(),z)-a.begin();
        int y=upper_bound(a.begin(),a.end(),z)-a.begin();
        if(y<n)
        a2=y;
        if(x-1>=0)
        a1=x-1;

        if(a1==-1)
        cout<<"X ";
        else
        cout<<a[a1]<<" ";

        if(a2==-1)
        cout<<"X";
        else
        cout<<a[a2];
        nl;
    }
}