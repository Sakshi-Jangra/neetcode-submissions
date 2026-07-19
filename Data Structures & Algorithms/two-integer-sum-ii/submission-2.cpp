class Solution {
public:
// Brute Force: Combination of two numbers..
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        vector<int> result;
        
        while(left < right){
            int sum = numbers[left] + numbers[right];

            if(sum == target){
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            // Sum is less than target, need to incr value
            if(sum < target){
                left++;
            }
            // Sum is more than target, need to reduce value
            else{
                right--;
            }
        }
    }
};