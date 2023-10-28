#include<bits/stdc++.h>
using namespace std;
bool Prnjl(string s)
{
    int c=0;
    for(auto i:s)
    {
        if(i!='-')
        {
            if(i>='A'&& i<='Z') c++;
        }
    }
    if(c==(s.size()-1)) return false;
    if(s[0]>='A' && s[0]<='Z')
    {
     if(c-1<=1) return true;
    }
  return false;
}
int main()
{
int n=0;
cout<<"enter the number of statements"<<endl;
cin>>n;
vector<string>v;
for(int i=0;i<n;i++)
{
    string s;
    cin>>s;
    v.push_back(s);
}
bool ans=false;
for(int i=0;i<n;i++)
{
    ans=Prnjl(v[i]);
    if(ans==false)
    {
        cout<<"the given program is not accepted by regular language"<<endl;
        break;
    }
}
if(ans)cout<<"the given program is accepted by regular language"<<endl;
}