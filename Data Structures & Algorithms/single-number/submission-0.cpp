class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for(auto a : nums){
            xorsum = xorsum ^ a;
        }
        return xorsum;
    }
};