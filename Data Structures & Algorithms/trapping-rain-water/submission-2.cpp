class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int l = 0, r = height.size()-1;
        int trappedWater = 0;
        int maxLeft = height[l], maxRight = height[r]; 

        while(l<r){
            // decide which edge to compute based on maxLeft / maxRight
            if(maxLeft < maxRight){
                l++;
                maxLeft = max(maxLeft, height[l]);
                trappedWater += (maxLeft - height[l]);
            }
            else{
                r--;
                maxRight = max(maxRight, height[r]);
                trappedWater += (maxRight - height[r]);
            }
        }
        return trappedWater;
    }
};
