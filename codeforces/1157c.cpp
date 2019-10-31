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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
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
    vinput(a,n);
    int p1=0,p2=n-1,last=-1;
    string ans="",s1,s2;

    while(p2>=p1)
    {
        // cout<<p1<<" "<<p2<<" "<<last<<endl;
        if(a[p1]<=last && a[p2]<=last)
        break;
        else if(a[p1]==a[p2])
        {
            s1=s2=ans;
            int t=last;
            rep(i,p2,p1)
            {
                if(a[i]>last)
                {
                    last=a[i];
                    s1+="L";
                }
                else
                break;
            }
            last=t;

            for(int i=p2;i>=p1;i--)
            {
                if(a[i]>last)
                {
                    last=a[i];
                    s2+="R";
                }
                else
                break;
            }
            // cout<<s1<<" "<<s2<<endl;
            if(s1.length()>s2.length())
            ans=s1;
            else
            ans=s2;
            break;
        }
        else if(a[p1]>last && a[p2]>last)
        {
            if(a[p1]>a[p2])
            {
                last=a[p2];
                p2--;
                ans+="R";
            }
            else
            {
                last=a[p1];
                p1++;
                ans+="L";
            }
        }
        else if(a[p1]>last)
        {
            last=a[p1];
            p1++;
            ans+="L";
        }
        else{
            last=a[p2];
            p2--;
            ans+="R";
        }
    }
    
    cout<<ans.length()<<endl;
    cout<<ans<<endl;
}
