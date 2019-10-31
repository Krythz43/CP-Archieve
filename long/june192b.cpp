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


struct kry
{
    char text[15];
    int index;
};

bool comp(kry a, kry b)
{
    if(strcmp(a.text,b.text)<0)
    return true;
    else
    return false;
}

int main()
{
       int n;
       fastio;
       cin>>n;
       
       vector <kry> a(n);
       
       rep(i,n,0)
       {
         cin>>a[i].text;
         a[i].index=i;
       }

       sort(a.begin(),a.end(),comp);

       int q;
       cin>>q;
       while(q--)
       {
           int r;
           char p[15];
           cin>>r>>p;

           vi check(r,0);
           int lp=strlen(p),zp=0;

           int counter=0;

           for(int i=0;i<n;i++)
           {
               if(a[i].index<r)
               {
               int cc=0;
               int cl=strlen(a[i].text);
               cl=min(cl,lp);

               rep(j,cl,0)
               {
                   if(a[i].text[j]==p[j])
                   {
                       cc++;
                   }
                   else
                   {
                       break;
                   }
               }
               zp=max(cc,zp);
               counter++;

               if(counter==r)
               break;
               }
           }

           lp=min(lp,zp);

           for(int i=0;i<n;i++)
           {
               if(a[i].index<r)
               {
               int f=1;
               if(strlen(a[i].text)>=lp)
               {
                 rep(j,lp,0)
                 {
                     if(a[i].text[j]!=p[j])
                     {
                         f=0;
                         break;
                     }
                 }
               }
               else
               f=0;

               if(f)
               {
                   cout<<a[i].text<<endl;
                   break;
               }  
               }
           }
       }
}