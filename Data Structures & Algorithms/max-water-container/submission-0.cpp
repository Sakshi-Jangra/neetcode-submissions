class Solution {
public:

// Brute Force Approach
// Find area under the curve for i,j,h
    int maxArea(vector<int>& heights) {
        int maxCap = -1, len = heights.size();
        for(int i = 0; i < len-1; i++){
            for(int j = i+1; j < len; j++){
                int capacity = min(heights[i], heights[j]) * (j-i);
                maxCap = (capacity > maxCap) ? capacity : maxCap;
            }
        }
        return maxCap;
    }
};