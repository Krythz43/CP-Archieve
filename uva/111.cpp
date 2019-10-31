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

    vi lis(1007,1);
    vi lop(1007);
    vector<pair<int,ipair > > a;

bool comp(pair<int,ipair > a, pair<int,ipair > b)
{
    return a.ss.ff<b.ss.ff;
}

void printans(int i)
{
    if(lis[i]==1)
    {
        cout<<a[i].ff<<endl;
        return;
    }
    printans(lop[i]);
    cout<<a[i].ff<<endl;
    return;
}

int main()
{
    fastio;
    int x,y;
    int s=0;
    while(cin>>x)
    {
        s++;
        cin>>y;
        a.pb(mp(s,(mp(x,y))));
    }

    sort(a.begin(),a.end(),comp);
    int n=a.size();
    rep(i,n,1)
    {
        rep(j,i,0)
        {
            if(a[i].ss.ff>a[j].ss.ff)
            {
                // cout<<"check2";
                if(a[i].ss.ss<a[j].ss.ss)
                {
                    // cout<<"check1";
                    if(lis[i]<lis[j]+1)
                    {
                        // cout<<"check";
                        lis[i]=lis[j]+1;;
                        lop[i]=j;
                    }
                }
            }
        }
    }

    int maxi=0;
    rep(i,n,1)
    {
        if(lis[i]>lis[maxi])
        maxi=i;
    }

    cout<<lis[maxi]<<endl;
    printans(maxi);
}