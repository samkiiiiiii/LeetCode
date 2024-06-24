class Solution {
public:
        int minSubArrayLen(int target, vector<int>& nums) {
                int n = nums.size();

		// two pointers
                int left = 0;
                int right = 0;
                int tmpTarget = target;
                int ans = INT_MAX;

		// sliding window
                while (right < n ) {
                        if (nums[right] == target) return 1;
                        do {
                                tmpTarget -= nums[right];
                                right++;
                        } while (tmpTarget > 0&&right!=n);

			// 收敛
                        if(tmpTarget <= 0)ans = min(ans, right - left);
                        do {
                                tmpTarget += nums[left];
                                left++;
                                if (tmpTarget <= 0) ans = min(ans, right - left);
                        } while (tmpTarget <= 0 && left != n);
                }
                return ans == INT_MAX ? 0 : ans;
        }
};