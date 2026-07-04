class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int n = s.size();
        unordered_map<char, int> freq;

        for(auto i : s){
            freq[i]++;
        }

        for(auto j : t){
            if(freq[j] > 0)
                freq[j]--;
            else
                return false;
        }

        for(auto &f:freq){
            if(f.second > 0)
                return false;
        }
        return true;
    }
};
