class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break;
            }
        }
        if(i==-1)
        {
            sort(nums.begin(),nums.end());
            for(auto k: nums) cout<<k;
        }
        else
        {
            for(int j=n-1;j>=0;j--)
            {
                if(nums[j]>nums[i])
                {
                    swap(nums[i],nums[j]);
                    break;
                }
            }
            sort(nums.begin()+(i+1),nums.end());
            for(auto i:nums) cout<<i;
        }
        cout<<endl;
    }
};
