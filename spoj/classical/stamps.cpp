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


int main()
{
    fastio;
    int t;
    cin>>t;
    rep(q,t,0)
    {
        int ma,n;
        cin>>ma>>n;
        lli sum=0;
        vi a(n);
        rep(i,n,0)
        {
            cin>>a[i];
            sum+=a[i];
        }

        cout<<"Scenario #"<<q+1<<":\n";
        if(sum<ma)
        cout<<"impossible"<<endl;
        else
        {
            int c=0;
            sum=0;
            sort(a.begin(),a.end());
            rrep(i,n-1)
            {
                sum+=a[i];
                c++;
                if(sum>=ma)
                {
                    cout<<c<<endl;
                    break;
                }
            }
        }
        nl;
    }
}