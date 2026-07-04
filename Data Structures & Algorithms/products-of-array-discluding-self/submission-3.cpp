class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int suffix;

        // Left product
        result[0] = 1;
        for(int i=1; i<n; i++){
            result[i] = result[i-1] * nums[i-1];
        }

        // right product
        suffix = 1;
        for(int j=n-1; j>=0; j--){
            result[j] *= suffix;
            suffix *= nums[j];
        }
        return result;
    }
};
