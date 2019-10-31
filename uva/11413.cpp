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
lli n,k,maxe,sum;
vi a(1007);

bool F(lli mid)
{
    lli c=1,csum=0;

    for(int i=0;i<n;)
    {
        // cout<<csum<<" "<<a[i]<<endl;
        if(csum + a[i] >mid)
        {
            if(csum==0)
            {
                // cout<<"mid value passed: "<<mid<<" count: "<<c<<endl;
                return false;
            }
            else
            {
                csum=0;
                c++;
            }
        }
        else
        {
            csum+=a[i];
            i++;
        }
    }
    // cout<<"mid value passed: "<<mid<<" count: "<<c<<endl;
    if(c<=k)
    return true;
    else
    return false;
}

int main()
{
    fastio;
    while(cin>>n)
    {
        cin>>k;
        maxe=sum=0;
        rep(i,n,0)
        {
            cin>>a[i];
            maxe=llmax(maxe,a[i]);
            sum+=a[i];
        }
        lli low=maxe;
        lli high=sum;

        while(high-low>1)
        {
            lli mid=(high+low)/2;
            if(F(mid))
            high=mid;
            else
            low=mid;
        }
        if(F(low))
        cout<<low<<endl;
        else
        cout<<high<<endl;
    }
}