/*
    This solution is wrong because it assumes connected components which fails when there are indices outside (x,y) that satisfy the property,
    See file 1169eALT.cpp for AC approach.
*/

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

int n,con=0;
vi a[20],b[300005],connected;
bool vis_index[300005],vis_layer[20];

void dfs_num(int id);

void dfs_layer(int id)
{
    vis_layer[id]=true;
    for(auto x:a[id])
    {
        if(vis_index[x]==false)
        dfs_num(x);
    }
}

void dfs_num(int id)
{
    vis_index[id]=true;
    connected[id]=con;
    for(auto x:b[id])
    {
        if(vis_layer[x]==false)
        dfs_layer(x);
    }
}


int main()
{
    fastio;
    int q,x,lv;
    cin>>n>>q;
    connected.resize(n+1,0);
    memset(vis_index,false,sizeof vis_index);
    memset(vis_layer,false,sizeof vis_layer);
    rep(i,n,0)
    {
        cin>>x;
        lv=0;
        while(x)
        {
            if(x%2==1)
            a[lv].pb(i);
            b[i].pb(lv);
            lv++;
            x/=2;
        }
    }

    rep(i,n,0)
    {
        for(auto id:b[i])
        {
            if(vis_layer[id]==false)
            {
                con++;
                dfs_layer(id);
            }
        }
    }

    // rep(i,20,0)
    // {
    //     cout<<"layer "<<i<<":";
    //     for(auto z: a[i])
    //     cout<<z<<" ";
    //     nl;
    // }

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(connected[x-1]==connected[y-1])
        cout<<"Shi"<<endl;
        else
        cout<<"Fou"<<endl;
    }
}
