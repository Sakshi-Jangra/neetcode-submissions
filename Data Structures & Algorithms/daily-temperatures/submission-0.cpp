class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tempStack;
        int n = temperatures.size();
        vector<int> waitDays(n,0);

        for(int i = n-1; i >= 0; i--){
            while(!tempStack.empty() && temperatures[tempStack.top()] <= temperatures[i]){
                tempStack.pop();
            }
            if(!tempStack.empty()){
                waitDays[i] = tempStack.top() - i;
            }
            tempStack.push(i);
        }
        return waitDays;
    }
};
