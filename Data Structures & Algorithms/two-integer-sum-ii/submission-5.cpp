class Solution {
public:
// Two pointers approach
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        
        while(left < right){
            int sum = numbers[left] + numbers[right];

            if(sum == target){
                return {left+1, right+1};
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