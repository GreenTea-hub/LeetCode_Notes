class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int i=0,k=0;
       while(i!=nums.size())
       {
            if(nums[i]==val)i++;
            else
            {
                nums[k++]=nums[i++];
            }
       }
       return k;
    }
};
