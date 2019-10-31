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
#define endl '\n'

int main()
{
    fastio;
    int n;
    cin>>n;
    int cor=n/3;
    string s;
    cin>>s;
    vi a;
    rep(i,n,0)
    a.pb(s[i]-48);

    int o,t,z;
    o=t=z=0;

    rep(i,n,0)
    {
        if(a[i]==0)
        z++;
        else if(a[i]==1)
        o++;
        else
        t++;
    }
    // cout<<z<<" "<<o<<" "<<t<<endl;

    if(z==cor && o==cor && t==cor)
    {
        cout<<s;
        nl;
    }
    else
    {


        if(t>cor)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==2)
                {
                    if(cor-z>0 && t>cor)
                    {
                        a[i]=0;
                        z++;
                        t--;
                    }
                    else if(cor-o>0  && t>cor)
                    {
                        a[i]=1;
                        o++;
                        t--;
                    }
                }
            }
        }


        if(o>cor)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(a[i]==1)
                {
                    if(cor-t>0  && o>cor)
                    {
                        a[i]=2;
                        t++;
                        o--;
                    }
                }
            }

            for(int i=0;i<n;i++)
            {
                if(a[i]==1)
                {
                    if(cor-z>0 && o>cor)
                    {
                        a[i]=0;
                        z++;
                        o--;
                    }
                }
            }
        }







        if(z>cor)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(a[i]==0)
                {
                    if(cor-t>0  && z>cor)
                    {
                        a[i]=2;
                        t++;
                        z--;
                    }
                    else if(cor-o>0 && z>cor)
                    {
                        a[i]=1;
                        o++;
                        z--;
                    }
                }
            }
        }
        
        

        rep(i,n,0)
        cout<<a[i];
        nl;
    }

}