class Solution {
public:
    string removeDuplicateLetters(string s) {
     map<char,int>m;
     map<char,int>vis;
     stack<char>st;
     for(auto i:s)
     {
         m[i]++;
     }
     for(auto i:s)
     {
        if(st.size()==0)
        {
            if(vis[i]==0 && m[i]!=0)
            {
            st.push(i);
            m[i]--;
            vis[i]=1;
            }
        }
        else if(i<=st.top() && m[st.top()]!=0 && vis[i]==0) 
        {
        while(st.top()>=i && m[st.top()]!=0 && !st.empty())
        {
            vis[st.top()]=0;
            st.pop();
        }
        st.push(i);
        m[i]--;
        vis[i]=1;
        }
        else
        {
            if(vis[i]==0)
            {
        st.push(i);
        m[i]--;
        vis[i]=1;
            }
        }
     }
     string ans="";
     while(!st.empty())
     {
     ans+=st.top();
     st.pop();
     }
     return ans;
    }

};