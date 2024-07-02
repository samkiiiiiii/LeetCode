
#include "_include.h"

class Solution {
public:
        int search(vector<int>& nums, int target) {
                int n = nums.size();
                if (n == 1) return nums[0] == target ? 0 : -1;
// 特殊情况, 没有旋转, 仍未有序数组
                if (nums[0] < nums[n - 1]) {
                        return binarySearch(nums, 0, n - 1, target);
                }

// 一般情况
                else {
                        int left = 0;
                        int right = n - 1;
                        while (left < right) {

				// 通过Mid和左右两边的值来判断mid是属于左区还是右区, 以及位于旋转点的左还是右
                                int mid = (right - left >> 1) + left;
                                if (nums[mid] == target) return mid;
                                if (nums[mid] < nums[n - 1]) {
                                        if (nums[n - 1] >= target) {
                                                if (nums[mid] <= target) return binarySearch(nums, mid + 1, n - 1, target);
                                        }
                                        right = mid - 1;
                                }
                                else {
                                        if (nums[0] <= target) {
                                                if (nums[mid] >= target) return binarySearch(nums, 0, mid - 1, target);
                                        }
                                        left = mid + 1;
                                }
                        }

			//因为二分时mid 采用的是(l+r)/2, 因此最后结果会收敛于左值
                        return nums[left] == target ? left : -1;
                }
        }

        int binarySearch(vector<int>& nums, int left, int right, int target) {
                
                while (left < right) {
                        int mid = (right - left >> 1) + left;
                        if (nums[mid] == target) {
                                return mid;
                        }
                        else if (nums[mid] > target) {
                                right = mid - 1;
                        }
                        else {
                                left = mid + 1;
                        }
                }
                return nums[left] == target ? left : -1;
        }
};