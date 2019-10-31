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

vi a(100005);
int n;

bool F(int mid)
{

    if(a[0]==mid)
    mid--;
    
    rep(i,n-1,0)
    {
        if(a[i+1]-a[i]>mid)
        return false;
        if(a[i+1]-a[i]==mid)
        mid--;
    }

    return true;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    rep(z,t,0)
    {
        cin>>n;
        rep(i,n,0)
        cin>>a[i];

        int high=a[n-1],low=a[0],mid;

        while(high-low>1)
        {
            mid=(high+low)/2;
            if(F(mid))
            high=mid;
            else
            low=mid;
        }

        cout<<"Case "<<z+1<<": ";
        if(F(low))
        cout<<low<<endl;
        else
        cout<<high<<endl;
    }
}