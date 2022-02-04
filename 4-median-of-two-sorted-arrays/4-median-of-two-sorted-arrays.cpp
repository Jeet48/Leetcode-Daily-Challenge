class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
     vector<int> r; int p1 = 0, p2 = 0;
        while(p1 < n1.size() && p2 < n2.size()) {
            r.push_back((n1[p1] < n2[p2]) ? n1[p1++] : n2[p2++]);
        }
        while(p1 < n1.size()) r.push_back(n1[p1++]);
        while(p2 < n2.size()) r.push_back(n2[p2++]);
        int sz = r.size();
        return sz&1 ? (double)r[sz/2] : ((double)r[sz/2 - 1] + (double)r[sz/2])/2;   
    }
};