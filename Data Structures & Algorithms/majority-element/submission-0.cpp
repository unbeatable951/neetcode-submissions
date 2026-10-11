class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int candidate = -1;
        for(int i = 0;i<n;i++)
        {
            if(count ==0)
            {
                candidate = nums[i];
            }

            if(candidate == nums[i])
            {
                count++;

            }
            else
            {
                count--;
            }
        }

        count =0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate)
            {
                count++;
            }
        }
        if(count>n/2)
        {
            return candidate;
        }
        else
        {
            return -1;
        }
    }
};