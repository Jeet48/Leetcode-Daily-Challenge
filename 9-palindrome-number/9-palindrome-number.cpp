class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string num = to_string(x);
        reverse(num.begin(),num.end());
        return (num==to_string(x))?true:false;
    }
};