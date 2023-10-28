class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& s) {
        vector<int>ans;
        vector<int>num;
        int n=s.size();
        int k=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=="prev")
            {
                if(s[i]==s[i+1])
                {
                    k++;
                }
            
            else
            {
                int l=num.size();
                if(l-k-1>=0)ans.push_back(num[l-k-1]);
                else
                {
                    ans.push_back(-1);
                }
                
            }
        }
        else
        {
            num.push_back(stoi(s[i]));
        }
        }
        for(auto i:num) cout<<i;
        for(int i=0;i<k;i++)
        {
            
                int l=num.size();
                if(l-k-1>=0)ans.push_back(num[l-k-1]);
                else
                {
                    ans.push_back(-1);
                }
        }
        return ans;
    }
};