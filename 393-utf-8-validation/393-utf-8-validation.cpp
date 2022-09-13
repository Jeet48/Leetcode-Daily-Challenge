class Solution {
public:
    
    bool validUtf8(vector<int>& data) {
        // used to track the remaining number of segments
        int remaining = 0;
        // iterate each data and perform the following logic
        for (auto& x : data) {
            
            if (remaining == 0) {
                if ((x >> 5) == 0b110) {

                    remaining = 1;
                } else if ((x >> 4) == 0b1110) {
                   
                     remaining = 2;
                } else if ((x >> 3) == 0b11110) {
                    
                    remaining = 3;
                } else if ((x >> 7) != 0) {
                     
                    return false;
                }
            } else {
               
                if ((x >> 6) != 0b10) return false;
                // otherwise, this segement is ok so we decrease `remaining` by 1
                else remaining--;
            }
        }
        // at the end, remaining will be 0 if data can represent the octet sequence 
        return remaining == 0;
    }
};