class Solution {
   public:
    string encode(vector<string>& strs) {
        string res;

        for (const string& s : strs) {
            res += (to_string(s.length()) + "*" + s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int length = 0;

        // iterate over the encoded string
        while (i < s.length()) {
            int j = i;
            // find delimeter
            while (s[j] != '*') {
                j++;
            }
            // length of string after delimeter
            length = stoi(s.substr(i, j - i));

            // pushback each decoded sub-string to res vector
            res.push_back(s.substr(j + 1, length));

            i = j + length + 1;
        }
        return res;
    }
};
