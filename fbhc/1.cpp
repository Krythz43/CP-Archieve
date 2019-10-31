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

int main()
{
    fastio;
    int t;
    cin>>t;
    rep(ca,t,0)
    {
        cout<<"Case #"<<ca+1<<": ";
        lli n,k,v;
        cin>>n>>k>>v;
        vector <string> a(n);

        rep(i,n,0)
        cin>>a[i];

        lli cf=((v-1)*k)%n;
        vi ans(k);
        int ak=0,tk=k;

        for(int i=cf;;i=(i+1)%n)
        {
            k--;
            ans[ak]=i;
            ak++;
            if(k==0)
            break;
        }

        sort(ans.begin(),ans.end());

        rep(i,tk,0)
        cout<<a[ans[i]]<<" ";
        nl;
    }
}