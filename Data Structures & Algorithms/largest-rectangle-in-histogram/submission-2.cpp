class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> left(n, 0);     // index of left smaller nearest
        vector<int> right(n, 0);    // index of right smaller nearest
        stack<int> s;       // always store index of elements smaller than current height in stack

        // right smaller
        for(int i = n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            // until this, either stack will be empty or found smaller element
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(!s.empty()){ s.pop();}    // need an empty stack
        
        // left smaller
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            // until this, either stack will be empty or found smaller element
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] -1));
        }
        return maxArea;
    }
};