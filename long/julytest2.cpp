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

vi a(50);
int n,m,c;


bool summer(vi ans,int i,int s,int l)
{
    if(i==l)
    {
        if(s!=0)
        {
            if(s%m==0)
            return true;
            else
            return false;
        }
        else
        return true;
    }
    else
    {
        bool ch=summer(ans,i+1,s+ans[i],l);
        bool sh=summer(ans,i+1,s,l);

        return (sh && ch);
    }
}

bool check(vi as)
{
    int l=as.size();
    // printarray(as,l);
    // nl;
    if(l==0)
    return false;
    return summer(as,0,0,l);
}

void ms(vi ans,int i)
{
    i++;
    if(i==n)
    {
        if(check(ans))
        c++;
    }
    else
    {
        ms(ans,i);
        ans.pb(a[i]);
        ms(ans,i);
    }
}

void solve(){
    vector <int> ans;
    ms(ans,0);
    ans.pb(a[0]);
    ms(ans,0);
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
 
        rep(i,n,0)
        cin>>a[i];
        c=0;

        solve();
        cout<<c<<endl;
    }
} 