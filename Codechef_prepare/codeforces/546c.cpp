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
    lli n,k1,k2,x;
    cin>>n>>k1;
    vlli a1,b1,a2,b2;
    rep(i,k1,0)
    {
        cin>>x;
        a1.pb(x);
        a2.pb(x);
    }

    cin>>k2;

    rep(i,k2,0)
    {
        cin>>x;
        b1.pb(x);
        b2.pb(x);
    }

    lli t=0;

    while(a1.size()!=0 && b1.size()!=0)
    {

        if(t>3000)
        {
            cout<<-1;
            return 0;
        }
        t++;
        int f=0;

        if(a1[0]>b1[0])
        {
            f=1;
            a1.pb(b1[0]);
        }
        else
        b1.pb(a1[0]);

        rep(i,a1.size()-1,0)
        swap(a1[i],a1[i+1]);

        rep(i,b1.size()-1,0)
        swap(b1[i],b1[i+1]);

        if(f)
        b1.pop_back();
        else
        a1.pop_back();

        // cout<<"Array a:";
        // printarray(a1,a1.size())
        // cout<<"Array b:";
        // printarray(b1,b1.size())


        int fc=0;
        if(a1.size()==k1 && b1.size()==k2)
        {if(a1.size()==k1)
        {
            rep(i,a1.size(),0)
            {
                if(a1[i]!=a2[i])
                {
                    fc+=1;
                    break;
                }
            }
        }

        if(b1.size()==k2)
        {
            rep(i,b1.size(),0)
            {
                if(b1[i]!=b2[i])
                {
                    fc+=1;
                    break;
                }
            }
        }

        if(fc==0)
        {
            cout<<-1;
            return 0;
        }}
    }



    cout<<t<<" ";
    if(a1.size()==0)
    cout<<2;
    else
    cout<<1;

}