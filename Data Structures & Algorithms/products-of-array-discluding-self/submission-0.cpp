class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i=0; i<n; i++){
            result[i] = 1;
            for(int j=0; j<n; j++){
                if(i != j)
                    result[i] *= nums[j];
            }
        }
        return result;
    }
};
