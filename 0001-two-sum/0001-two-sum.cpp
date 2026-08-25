#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;  // Store number and index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // Find complement
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};  // Return indices
            }
            num_map[nums[i]] = i;  // Store current number and index
        }
        return {};  // Should never reach here (problem guarantees a solution)
    }
};