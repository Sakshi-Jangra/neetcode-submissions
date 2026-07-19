class Solution {
public:
    int getSum(int a, int b) {
        int xor_ = (a ^ b);
        int carry = (a & b) << 1;
        while(carry != 0){
            a = xor_;
            b = carry;
            xor_ = a ^ b;
            carry = (a & b) << 1;
        }
        return xor_;
    }
};