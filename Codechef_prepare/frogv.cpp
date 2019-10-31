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
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}


struct fro
{
    int i;
    lli d;
};

bool comp(fro a, fro b)
{
    return a.d<b.d;
}

int main()
{
    fastio;
    int n,p;
    lli k;
    cin>>n>>k>>p;
    vector <fro> a(n);
    rep(i,n,0)
    {
        cin>>a[i].d;
        a[i].i=i;
    }    

    vector <int> hash(n);
    sort(a.begin(),a.end(),comp);

     int r=1;hash[a[0].i]=r;
    rep(i,n,1)
    {
        if(a[i].d-a[i-1].d<=k)
        hash[a[i].i]=r;
        else
        {
            r++;
            hash[a[i].i]=r;
        }
    }

    // printarray(hash,n)
    while(p--)
    {
        int x,y;
        cin>>x>>y;
        if(hash[x-1]==hash[y-1])
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
}