class Solution {
public:


    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        stack<int> s;    // nextGreater
        vector<int> arr(n2);    // in the stack only keep the index of elements greater than the current element

        for(int i = n2-1; i >= 0; i--){
            while(!s.empty() && nums2[s.top()] <= nums2[i]){
                s.pop();
            }
            arr[i] = s.empty() ? -1 : nums2[s.top()];
            s.push(i);
        }
        // Map nums2 value -> next greater element
        unordered_map<int, int> mp;     // nums2 val <-> greaterElement idx acc to num2 stored in arr

        for(int i = 0; i < n2; i++) {
            mp[nums2[i]] = arr[i];
        }

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};