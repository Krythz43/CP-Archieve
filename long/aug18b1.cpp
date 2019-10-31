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
    int t;
    cin>>t;
    while(t--)
    {
        char a[3],b[3];
        cin>>a>>b;
        int f=0;
        
        if(a[0]=='b')
        {
            if(a[1]=='o'&&b[2]=='b')
            f=1;
            if(a[1]=='b'&&b[2]=='o')
            f=1;
            if(a[2]=='o'&&b[1]=='b')
            f=1;
            if(a[2]=='b'&&b[1]=='o')
            f=1;
            if(a[1]=='o'&&a[2]=='b')
            f=1;
            if(a[1]=='b'&&a[2]=='o')
            f=1;
            if(b[1]=='o'&&b[2]=='b')
            f=1;
            if(b[1]=='b'&&b[2]=='o')
            f=1;
        }

        if(a[1]=='b')
        {
            if(a[0]=='o'&&b[2]=='b')
            f=1;
            if(a[0]=='b'&&b[2]=='o')
            f=1;
            if(a[2]=='o'&&b[0]=='b')
            f=1;
            if(a[2]=='b'&&b[0]=='o')
            f=1;
            if(a[0]=='o'&&a[2]=='b')
            f=1;
            if(a[0]=='b'&&a[2]=='o')
            f=1;
            if(b[0]=='o'&&b[2]=='b')
            f=1;
            if(b[0]=='b'&&b[2]=='o')
            f=1;
        }

        if(a[2]=='b')
        {
            if(a[1]=='o'&&b[0]=='b')
            f=1;
            if(a[1]=='b'&&b[0]=='o')
            f=1;
            if(a[0]=='o'&&b[1]=='b')
            f=1;
            if(a[0]=='b'&&b[1]=='o')
            f=1;
            if(a[1]=='o'&&a[0]=='b')
            f=1;
            if(a[1]=='b'&&a[0]=='o')
            f=1;
            if(b[1]=='o'&&b[0]=='b')
            f=1;
            if(b[1]=='b'&&b[0]=='o')
            f=1;
        }

        if(b[0]=='b')
        {
            if(a[1]=='o'&&b[2]=='b')
            f=1;
            if(a[1]=='b'&&b[2]=='o')
            f=1;
            if(a[2]=='o'&&b[1]=='b')
            f=1;
            if(a[2]=='b'&&b[1]=='o')
            f=1;
            if(a[1]=='o'&&a[2]=='b')
            f=1;
            if(a[1]=='b'&&a[2]=='o')
            f=1;
            if(b[1]=='o'&&b[2]=='b')
            f=1;
            if(b[1]=='b'&&b[2]=='o')
            f=1;
        }

        if(b[1]=='b')
        {
            if(a[0]=='o'&&b[2]=='b')
            f=1;
            if(a[0]=='b'&&b[2]=='o')
            f=1;
            if(a[2]=='o'&&b[0]=='b')
            f=1;
            if(a[2]=='b'&&b[0]=='o')
            f=1;
            if(a[0]=='o'&&a[2]=='b')
            f=1;
            if(a[0]=='b'&&a[2]=='o')
            f=1;
            if(b[0]=='o'&&b[2]=='b')
            f=1;
            if(b[0]=='b'&&b[2]=='o')
            f=1;
        }

        if(b[2]=='b')
        {
            if(a[1]=='o'&&b[0]=='b')
            f=1;
            if(a[1]=='b'&&b[0]=='o')
            f=1;
            if(a[0]=='o'&&b[1]=='b')
            f=1;
            if(a[0]=='b'&&b[1]=='o')
            f=1;
            if(a[1]=='o'&&a[0]=='b')
            f=1;
            if(a[1]=='b'&&a[0]=='o')
            f=1;
            if(b[1]=='o'&&b[0]=='b')
            f=1;
            if(b[1]=='b'&&b[0]=='o')
            f=1;
        }

        if(f)
        cout<<"yes";
        else
        cout<<"no";
        nl;

    }
}