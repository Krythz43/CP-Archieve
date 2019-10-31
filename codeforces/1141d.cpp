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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
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
    string s1,s2;
    cin>>s1>>s2;
    vector<int> q1,q2;
    vector<int> a[26],b[26];
    rep(i,n,0)
    {
        if(s1[i]=='?')
        q1.pb(i+1);
        else
        a[s1[i]-97].pb(i+1);

        if(s2[i]=='?')
        q2.pb(i+1);
        else
        b[s2[i]-97].pb(i+1);
    }

    vector <ipair> ans;
    int p1,p2;
    int qc1,qc2;
    qc1=qc2=0;

    rep(i,26,0)
    {
        if(a[i].size()!=b[i].size())
        {
            while(a[i].size()<b[i].size() && q1.size()!=qc1)
            {
                a[i].pb(q1[qc1]);
                qc1++;
            }

            while(a[i].size()>b[i].size() && q2.size()!=qc2)
            {
                b[i].pb(q2[qc2]);
                qc2++;
            }
        }
    }

    while(q1.size()!=qc1 || q2.size()!=qc2)
    {
        ans.pb(mp(q1[qc1],q2[qc2]));
        qc1++;
        qc2++;
    }


    rep(i,26,0)
    {
        rep(j,min(a[i].size(),b[i].size()),0)
        {
            ans.pb(mp(a[i][j],b[i][j]));
        }
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size(),0)
    cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
}