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

int main()
{
    fastio;
    int n,m,q;
    cin>>n>>m>>q;
    string s,sb;
    cin>>s;
    cin>>sb;
    int l1,l2;
    l1=s.length();
    l2=sb.length();

    vector <ipair> a;

    rep(i,l1,0)
    {
        if(s[i]==sb[0])
        {
            int f=0;
            for(int j=0;j<l2 && i+j<l1;j++)
            {
                if(s[i+j]==sb[j])
                f++;
                else
                break;
            }
            // cout<<f<<endl;
            if(f==l2)
            {
                a.pb(mp(i+1,i+l2));
            }

        }
    }

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int ans=0;
        rep(i,a.size(),0)
        {
            if(a[i].ff>=x && a[i].ss<=y)
            ans++;
        }
        cout<<ans<<endl;
    }

}