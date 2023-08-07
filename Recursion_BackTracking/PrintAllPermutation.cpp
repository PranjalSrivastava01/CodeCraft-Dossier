//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void myFun(vector<string> &ans,string s ,string temp , int freq[])
    {
        if(s.size()==temp.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
         if(freq[i]!=1)
         {
          temp.push_back(s[i]);
          freq[i]=1;
          myFun(ans,s,temp,freq);
          temp.pop_back(); 
          freq[i]=0;
         }
          
        }
    }
    vector<string> permutation(string s)
    {
       vector<string>ans;
       string temp;
       int freq[s.size()]={0};
       myFun(ans,s,temp,freq);
       sort(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends