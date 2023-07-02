class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
           sum+=nums[i];
           if(sum<0)
           {
               sum=0;
           }
           if(sum>maxi)
           {
               maxi=sum;
           }
        }
        if(maxi==0)
        return *max_element(nums.begin(), nums.end());
        cout<<maxi;
        return maxi;
    }
};