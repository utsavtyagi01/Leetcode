class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        
        int result = min({
            nums[n - 1] - nums[3],   
            nums[n - 2] - nums[2],   
            nums[n - 3] - nums[1],   
            nums[n - 4] - nums[0]    
        });

        return result;
    }
};

/* int i = 0, j = nums.size() - 1;

        // Adjust the pointers up to three times
        for (int k = 0; k < 3; ++k) {
            if ((nums[i + 1] - nums[i]) <= (nums[j] - nums[j - 1])) {
                i++;
            } else {
                j--;
            }
        }

        return nums[j] - nums[i];*/
