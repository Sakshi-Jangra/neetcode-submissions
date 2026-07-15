class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> anagramVector;

        // anagramMap (key: value arrays/vector )
        // key = "act" -> {"act", "cat", "tac"} (vector of string that are anagrams)

        for(auto s : strs){
            string key = s;
            sort(key.begin(), key.end());
            anagramMap[key].push_back(s);
        }

        for(auto &itr : anagramMap){
            anagramVector.push_back(itr.second);
        }
        return anagramVector;
    }
};
