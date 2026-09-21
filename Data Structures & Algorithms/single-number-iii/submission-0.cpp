class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        int mask = 1;

        for(auto a : nums){
            xorsum = xorsum ^ a;
        }
        while (!(xorsum & mask))
            mask = mask << 1;
        
        vector<int> res(2);
        for(auto n : nums){
            if (mask & n)
                res[0] = res[0] ^ n;
            else
                res[1] = res[1] ^ n;
        }
        return res;
    }
};