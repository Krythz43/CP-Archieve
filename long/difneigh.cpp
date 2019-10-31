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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int main()
{
    fastio;
    int n=2;
    // cin>>n;
    int q;
    cin>>q;


    int a[50][50];
    int t[50][2];
    memset(a,0,sizeof a);
    memset(t,0,sizeof t);


    for(int i=0;i<50;i++)
    {
        t[i][0]=t[i][1]=i%3+1;
    }

    for(int i=0;i<50;i++)
    {
        int j=0;
        while(j<50 && i+j<50)
        {
            if((i/2)%2)
            a[j][i+j]=j%2?4:2;
            else
            a[j][i+j]=j%2?3:1;
            j++;
        }
    }
    for(int i=1;i<50;i++)
    {
        int j=0;
        while(j<50 && i+j<50)
        {
            if(((i-1)/2)%2)
            a[i+j][j]=j%2?3:1;
            else
            a[i+j][j]=j%2?4:2;
            j++;
        }
    }
    // displaymatrix(a,m,n)
    // for(int i=1;i<n-1;i++)
    // {
    //     for(int j=1;j<m-1;j++)
    //     {
    //         set <int> te;
    //         te.insert(a[i+1][j]);
    //         te.insert(a[i-1][j]);
    //         te.insert(a[i][j+1]);
    //         te.insert(a[i][j-1]);
    //         if(te.size()!=4)
    //         {
    //             cout<<"Anamoly at "<<i<<","<<j<<endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout<<"All good!"<<endl;


    while(q--)
    {
        int n,m;
        cin>>n>>m;
        if(m==2)
        {
            set <int> te;
            rep(i,n,0)
            rep(j,m,0)
            te.insert(t[i][j]);
            cout<<te.size()<<endl;
            rep(i,n,0)
            {
                rep(j,m,0)
                cout<<t[i][j]<<" ";
                nl;
            }
        }
        else if(n==2)
        {
            set <int> te;
            rep(i,n,0)
            rep(j,m,0)
            te.insert(t[j][i]);
            cout<<te.size()<<endl;
            rep(i,n,0)
            {
                rep(j,m,0)
                cout<<t[j][i]<<" ";
                nl;
            }
        }
        else{
            set <int> te;
            rep(i,n,0)
            rep(j,m,0)
            te.insert(a[i][j]);
            cout<<te.size()<<endl;
            rep(i,n,0)
            {
                rep(j,m,0)
                cout<<a[i][j]<<" ";
                nl;
            }
        }
    }    
}
