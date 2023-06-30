class Solution {
public:
    void sortColors(vector<int>& arr) {
       int cnt0=0,cnt1=0,cnt2=0;
       for(auto i: arr)
       {
         if(i==0) cnt0++;
         else if(i==1) cnt1++;
         else
         {
           cnt2++;
         }
       }
         for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < cnt0+cnt1+cnt2; i++) arr[i] = 2;
    }
};