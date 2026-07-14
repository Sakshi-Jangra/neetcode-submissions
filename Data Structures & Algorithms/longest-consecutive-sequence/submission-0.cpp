class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Initialize hash using nums array. All elements part of nums array will be in this hash/set.
        unordered_set<int> hash(nums.begin(), nums.end()); 
        int max_length=0;

        for(auto curr : hash){
            // find(element) returns end(): if element doesn't exist, returns True if exists
            // if "nums[i] -1" one less value than current doesn't exist, , then it is a start of the consecutive group
            if(hash.find(curr-1) == hash.end()){
                int len = 1;
                int consec = curr;
                while(hash.find(consec+1) != hash.end()){
                    len++;
                    consec++;
                }
                max_length = max(len,max_length);
            }
        }
        return max_length;
    }
};
