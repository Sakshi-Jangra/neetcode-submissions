class Solution {
public:

// Two pointer Approach
// Find area under the curve for left,right,height
// Move left or right - which ever is smaller
    int maxArea(vector<int>& heights) {
        int maxCap = 0;
        int l = 0;
        int r = heights.size() - 1;
        while(l<r){
            int h = min(heights[l], heights[r]);
            maxCap = max(maxCap, h * (r-l));
            if(heights[l]<heights[r])
                l++;
            else
                r--;
        }
        return maxCap;
    }
};
