class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        int j = 0;

        // Find the longest sequential prefix
        for(int i = 0; i < n - 1; i++) {

            if(nums[i] + 1 == nums[i + 1]) {
                j = i + 1;
            }
            else {
                break;
            }
        }

        // Find sum of sequential prefix
        int sum = 0;

        for(int i = 0; i <= j; i++) {
            sum += nums[i];
        }

        // Find the smallest missing integer >= sum
        while(true) {

            bool found = false;

            for(int i = 0; i < n; i++) {

                if(nums[i] == sum) {
                    found = true;
                    break;
                }
            }

            if(found == false) {
                return sum;
            }

            sum++;
        }
    }
};