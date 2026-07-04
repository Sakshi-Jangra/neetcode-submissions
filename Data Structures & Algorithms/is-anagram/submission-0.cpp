class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int n = s.size();
        vector<bool> marking(n, false);

        for(auto i:s){
            for(int j=0; j<n; j++){
                if(t[j] == i){
                    if(marking[j] == 0){
                        marking[j] = 1;
                        break;
                    }
                }
            }
        }

        for(auto m:marking){
            if(m == 0)
                return false;
        }
        return true;
    }
};
