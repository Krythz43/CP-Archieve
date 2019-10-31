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


vector<ipair > a;
int n,m;

void add(int c,int d)
{
    if(a.size()==m)
    return;
    if(c>n || d>n)
    return;
    a.pb(mp(c,d));
    add(c+d,d);
    if(a.size()==m)
    return;
    add(c,c+d);
}


int main()
{
    fastio;
    cin>>n>>m;

        rep(i,n+1,2)
        {
            if(a.size()==m)
            break;
            a.pb(mp(1,i));
        }

        rep(i,n+1,2)
        {
            if(a.size()==m)
            break;
            if(a.size()==m)
            break;
            add(1+i,i);
        }

    // cout<<a.size()<<endl;
    if(a.size()!=m || m<n-1)
    cout<<"Impossible";
    else
    {
        cout<<"Possible"<<endl;
        rep(i,a.size(),0)
        cout<<a[i].ff<<" "<<a[i].ss<<endl;
    }
}