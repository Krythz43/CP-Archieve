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
// #define mp make_pair
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
// #define endl '\n'



int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    map<int,int> mp,ind;
    
    rep(i,n,0)
    {
        mp[a[i]]=i+1;
        ind[i+1]=a[i];
    }

    vector <ipair> query;
    int p1=0,p2=n/2;

    while(p1<n/2 && p2<n)
    {
        if(mp[p1+1]==p1+1)
        {
            p1++;
            // break;
        }
        else if(mp[p2+1]==p2+1)
        p2++;
        else
        {
            if(mp[p1+1]<=n/2 && mp[p2+1]>n/2)
            {
                query.pb(make_pair(p1+1,p2+1));
                cout<<"push1"<<endl;
                swap(mp[ind[p1+1]],mp[ind[p2+1]]);
                swap(ind[p1+1],ind[p2+1]);
            }
            else if(mp[p1+1]>n/2)
            {
                rep(i,n,0)
                cout<<ind[i+1]<<" ";
                nl;
                rep(i,n,0)
                cout<<mp[i+1]<<" ";
                nl;
                query.pb(make_pair(p1+1,mp[p1+1]));
                cout<<"push2"<<endl;
                swap(mp[p1+1],mp[ind[p1+1]]);
                swap(ind[p1+1],ind[ind[p1+1]]);   
            }
            else if(mp[p2+1]<=n/2)
            {
                cout<<"push3"<<endl;
                query.pb(make_pair(p2+1,mp[p2+1]));
                swap(mp[ind[p2+1]],mp[ind[ind[p2+1]]]);
                swap(ind[p2+1],ind[ind[p2+1]]);   
            }
        }
    }

    if(p1==n/2 && p2==n)
    {
        cout<<query.size()<<endl;
        rep(i,query.size(),0)
        cout<<query[i].ff<<" "<<query[i].ss<<endl;
        return 0;
    }   
    int p3;
    if(p1==n/2)
    {
        while(p2!=n)
        {
            if(mp[p2+1]==p2+1)
            p2++;
            else
            {
                p3=p2+1;
                while(mp[p3+1]==p3+1)
                {
                    p3++;
                }
                query.pb(make_pair(n/2,p3+1));
                query.pb(make_pair(n/2,p2+1));
                query.pb(make_pair(n/2,p3+1));     
                swap(mp[ind[p3+1]],mp[ind[n/2]]);
                swap(ind[p3+1],ind[n/2]);
            }
        }
    }
    else
    {
        while(p1!=n/2)
        {
            if(mp[p1+1]==p1+1)
            p1++;
            else
            {
                p3=p1+1;
                while(mp[p3+1]==p3+1)
                {
                    p3++;
                }
                query.pb(make_pair(n,p3+1));
                query.pb(make_pair(n,p1+1));
                query.pb(make_pair(n,p3+1));
                swap(mp[ind[n]],mp[ind[p1+1]]);
                swap(ind[n],ind[p1+1]);                
            }
        }
    }

    rep(i,n,0)
    cout<<ind[i+1]<<" ";
    nl;
    rep(i,n,0)
    cout<<mp[i+1]<<" ";
    nl;
    cout<<query.size()<<endl;
    rep(i,query.size(),0)
    cout<<query[i].ff<<" "<<query[i].ss<<endl;
    return 0;
}
