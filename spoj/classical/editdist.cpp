#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nyyl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define priority_queue pq;
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i];} cout<<endl

int main()
{
  int t;
  fastio;
  cin>>t;
  while(t--)
  {
    string n,m;
    cin>>n>>m;
    int ml=m.length();
    int nl=n.length();
    vector< vector<int> > a(nl+1,vector<int> (ml+1));

    rep(i,nl+1,0)
    {
      rep(j,ml+1,0)
      {
        if(i==0)
        a[i][j]=j;
        else if(j==0)
        a[i][j]=i;
        else if(n[i-1]==m[j-1])
        {
        //cout<<"same"<<endl;
        a[i][j]=a[i-1][j-1];
        }
        else
        {
          //cout<<"not"<<endl;
        a[i][j]=1+min(min(a[i-1][j],a[i][j-1]),a[i-1][j-1]);
      }
    }
    }
    cout<<a[nl][ml]<<endl;
  //  displaymatrix(a,nl,ml)
  }
}
