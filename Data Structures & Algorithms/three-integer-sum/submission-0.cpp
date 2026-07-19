class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());     // O(NLogN)

        for(int a = 0; a < len && nums[a] <= 0; a++){                       // O(N)
            if(a > 0 && nums[a] == nums[a-1])   // Avoid duplication of 'a'
                continue;

            // two pointer
            int left = a+1;
            int right = len-1;

            while(left < right){
                int sum = nums[left] + nums[right] + nums[a];
                if(sum > 0){  // found the positive b + c pair, which adding to a (negative number), gives 0 result
                    right--;
                }
                else if(sum < 0)
                    left++;
                else{
                    result.push_back( { nums[a], nums[left], nums[right] } );
                    
                    
                    // we need to move left & right, as 'a' is constant, if we don't move left & right both. then it can generate duplicate solution.
                    left++; right--;        
                    // For index a - there can be multiple b & c in the array, so need to continue within this
                    while(nums[left] == nums[left-1] && left<right){
                        left++;             // Avoid duplication of 'LEFT'
                    }
                }
            }
        }
        return result;
    }
};
