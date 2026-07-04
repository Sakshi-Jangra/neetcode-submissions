class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(auto i: nums)
            freq[i]++;

        priority_queue<pair<int, int>> heap;

        for(auto &f:freq)
            heap.push( { f.second, f.first } ); // Sort O(n LogN)
        
        vector<int> ans;

        while(k--){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;

    }
};
