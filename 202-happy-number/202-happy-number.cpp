class Solution {
public:
    bool isHappy(int n) {
       int t = 0;
        while(t != 1){
            t = 0;
            while(n > 0){
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
            if(t == 89) return false;
        }
        return true;
    }
    
};