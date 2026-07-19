class Solution {
public:

// Two pointer Approach
// Find area under the curve for left,right,height
// Move left or right - which ever is smaller
    int maxArea(vector<int>& heights) {
        int maxCap = -1, l = 0, r = heights.size() - 1;
        while(l<r){
            int capacity = min(heights[l], heights[r]) * (r-l);
            if(capacity > maxCap)   maxCap = capacity;
            if(heights[l]<heights[r])
                l++;
            else
                r--;
        }
        return maxCap;
    }
};
