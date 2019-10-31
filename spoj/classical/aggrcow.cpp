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
vlli a;
lli t,high,low,mid,n,c;

bool F(lli mid)
{
    int ip=0,lp=1,co=1;

    for(;;)
    {
        if(a[lp]-a[ip]>=mid)
        {
            ip=lp;
            lp++;
            co++;
        }
        else
        lp++;

        if(co==c)
        return true;

        if(lp==n)
        break;
    }
    // cout<<"cow count:"<<co<<endl;
    return false;
}

int main()
{
    fastio;
    cin>>t;

    while(t--)
    {
        cin>>n>>c;
        a.resize(n);
        rep(i,n,0)
        cin>>a[i];

        sort(a.begin(),a.end());

        high=low=1e9;
        rep(i,n-1,0)
        {
            if(low>a[i+1]-a[i])
            low=a[i+1]-a[i];
        }

        while(high-low>1)
        {
            mid=(high+low)/2;
            // cout<<"query mid="<<mid<<":";
            if(F(mid))
            {low=mid;
            // 
            }
            else
            {
                high=mid;
                // cout<<"false"<<endl;
            }
            // cout<<"high:"<<high<<" low:"<<low<<endl;
        }
        if(F(high))
        cout<<high;
        else
        cout<<low;
        nl;

    }
}