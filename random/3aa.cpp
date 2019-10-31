#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}


int wayc=0,n,k;


void func(vector<int> a)
{
    int z=0;
    vector <bool> vis(n+1,false);
    rep(i,n,0)
    {
        if(a[i]==0)
        z++;
        else
        vis[a[i]]=true;
    }
    

    if(z==0)
    {
        int rc=0;

        rep(i,n-1,0)
        {
            if(a[i+1]>a[i])
            rc++;
         //   cout<<a[i]<<" ";
        }
      //  cout<<a[n-1];
      //  nl;

        if(rc==k)
        wayc++;
    }
    else
    {
        rep(i,n,0)
        {
            if(a[i]==0)
            {
                rep(j,n+1,1)
                {
                    if(vis[j]==false)
                    {
                        a[i]=j;
                        func(a);
                        a[i]=0;
                    }
                }

                break;
            }
        }
    }
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        wayc=0;
        cin>>n>>k;
        vi a(n);
        int z=0;
        rep(i,n,0)
        {
            cin>>a[i];
            if(a[i]==0)
            z++;
        }

        func(a);
        cout<<wayc<<endl;
    }
}