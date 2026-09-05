class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int len = piles.size();
        int maxk = 0;

        for(int i = 0; i < len; i++){
            maxk = max(maxk, piles[i]);
        }
        int left = 1, right = maxk, mid = (left + right)/2;
        int mink = maxk;

        while(left <= right){
            int neededHours = 0;
            mid = (left + right)/2;
            for(int i = 0; i < len && neededHours <= h; i++){
                neededHours += (piles[i]/mid);
                if(piles[i] % mid) neededHours++;
            }
            if(neededHours <= h){
                right = mid-1;
                mink = mid;
            }else{
                left = mid+1;
            }
        }
        return mink;
    }
};
