class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n == 2) return min(height[0], height[1]);
	
	int left = 0;
	int right = n - 1;

	int maxSize = 0;
	int currentSize = 0;

	while(left < right){
		currentSize = (right - left) * min(height[right], height[left]);
		maxSize = maxSize > currentSize? maxSize : currentSize;
		
		if(height[left] < height[right]) left++;
		else right--;		
	}
	
	return maxSize;
    }
};
