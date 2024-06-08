class Solution{
public:	
	vector<vector<int>> threeSum(vector<int>& nums){
		
		int n = nums.size();
		sort(nums.begin(), nums.end());

		vector<vector<int>> res;
		
		// two pointers rather than hash-map
		
		for(int i = 0;i<n;++i){
		
			// deduplicate

			if(i > 0 && nums[i] == nums[i - 1]) continue;

			// convergence between lo and hi

			int lo = i + 1, hi = n - 1;
			
			while(lo < hi){

				if(nums[i] + nums[lo] + nums[hi] > 0) hi--;
				else if(nums[i] + nums[lo] + nums[hi] < 0) lo++;
				else{
					res.push_back({nums[i], nums[lo], nums[hi]});
					while(lo + 1 < n && nums[lo] == nums[++lo]);
					while(hi - 1 > 0 && nums[hi] == nums[--hi]);
				}
			}
		}

		return res;
	}
};
				
