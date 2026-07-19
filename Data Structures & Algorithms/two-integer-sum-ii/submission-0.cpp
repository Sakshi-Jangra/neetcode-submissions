class Solution {
public:
// Brute Force: Combination of two numbers..
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        vector<int> result;
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                if(numbers[i] + numbers[j] == target){
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
                if(numbers[i] + numbers[j] > target)
                    break;
            }
        }
    }
};
