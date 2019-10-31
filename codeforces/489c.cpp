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

int n,m,x,i;
string s,s1;
int main()
{
    fastio;

    cin>>n>>m;
    x=m;
    if(n==1 && m<10)
    {
        cout<<m<<" "<<m;
        return 0;
    }
    if((n>1 && m==0)||(n==1 && m>9)){cout<<"-1 -1";return 0;}
    for(i=0;i<n;i++)
    {
        if(x>8){s=s+"9";x-=9;}
        else if(x<9){s=s+char(x+48);x=0;}
    }
    if(x!=0){cout<<"-1 -1";return 0;}
    s1=s;
    reverse(s1.begin(),s1.end());
    if(s1[0]=='0')
    {
        for(i=0;i<s1.length();i++)
            if(s1[i]!='0'){s1[i]=char(int(s1[i])-1);s1[0]='1';break;}
    }
    cout<<s1<<" "<<s;
    return 0;
}