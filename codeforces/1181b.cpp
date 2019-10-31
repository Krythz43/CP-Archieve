#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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

string s;

string smaller(string s1,string s2){
    
    if(s1.length()==s2.length())
    {
        rep(i,s1.length(),0)
        {
            if(s1[i]-48>s2[i]-48)
            return s2;
            if(s1[i]-48<s2[i]-48)
            return s1;
        }
        return s1;
    }
    
    if(s1.length()>s2.length())
    return s2;
    else
    return s1;
}

string f(int s1,int e1,int s2,int e2)
{
    string ans="";
    // for(int i=s1;i<=e1;i++)
    // cout<<s[i];
    // cout<<" ";
    // for(int i=s2;i<=e2;i++)
    // cout<<s[i];
    // cout<<" ";


    if(s2=='0')
    return ans;
    int carry=0;
    int p1=e1,p2=e2;
    while(p1!=s1-1 || p2!=s2-1)
    {
        int su=0;
        if(p1!=s1-1)
        {
            su+=s[p1]-48;
            p1--;
        }
        if(p2!=s2-1)
        {
            su+=s[p2]-48;
            p2--;
        }
        su+=carry;
        carry=su/10;
        su%=10;
        ans+=(char)(su+48);
    }
    if(carry)
    ans+=(char)(carry+48);
    reverse(ans.begin(),ans.end());
    // for(int i=0;i<ans.length();i++)
    // cout<<ans[i];
    // cout<<endl;
    return ans;
}
int main()
{
    fastio;
    int l,n;
    cin>>l;
    n=l;
    cin>>s;
    int ls=n;
    for(int i=l-1;i>=0;i--)
    {
        if(s[i]=='0')
        ls--;
        else
        break;
    }
    if(ls!=n)
    {
        ls--;
        if(ls<n/2)
        {
            cout<<f(0,ls-1,ls,n-1)<<endl;
            return 0;
        }
    }

    int mid=l/2;
    string s1,s2,s3,s4;
    s1=s2=s3=s4="";
    int c=0;
    for(int i=mid;i<l;i++)
    {
        if(s[i]=='0')
        continue;
        if(c)
        {s2=f(0,i-1,i,n-1);break;}
        else
        {
            c++;
            s1=f(0,i-1,i,n-1);
        }
    }

    c=0;
    for(int i=mid-1;i>0;i--)
    {
        if(s[i]=='0')
        continue;
        if(c)
        {s4=f(0,i-1,i,n-1);break;}
        else{
            c++;
            s3=f(0,i-1,i,n-1);
        }
    }









    string ans="";
    if(s1!="" && s2!="")
    {
        ans=smaller(s1,s2);
    }
    else if(s1!="")
    ans=s1;
    else if(s2!="")
    ans=s2;

    if(ans=="")
    {
        if(s3!="" && s4!="")
        {
            ans=smaller(s3,s4);
        }
        else if(s3!="")
        ans=s3;
        else if(s4!="")
        ans=s4;
    }
    if(s3!="")
    {
        ans=smaller(ans,s3);
    }
    if(s4!="")
    {
        ans=smaller(ans,s4);
    }

    // cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;

    cout<<ans<<endl;
}