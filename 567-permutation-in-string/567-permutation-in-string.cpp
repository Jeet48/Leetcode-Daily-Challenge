class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
    int n1 = s1.length(); // extracting length of string s1
        int n2 = s2.length(); // extracting length of string s2
        
        if(n1 > n2) // if length of s1 is greater than length of s2 
            return false; // then simply return false, because it is impossible
        
        // unordered map for storing frequency of every character of s1
        unordered_map<char,int> mp; 
        
        // traverse from the string s1
        for(int i = 0; i < s1.length(); i++)
        {
            mp[s1[i]]++; // store frequency of every character
        }
        
        int i = 0, j = 0; // variable for sliding window
        
        // it tells us the number of distinct letters present in s1
        int count = mp.size(); 
        
        
        int k = s1.length(); // size of the string s1 is our window size
        
        // start moving in string s2
        while(j < n2)
        {
            if(mp.find(s2[j]) != mp.end()) // if this particular charcter of s2 is present in map
            {
                mp[s2[j]]--; // then decrease its frequency in map
                
                // if any point the frequency of any character becomes zero, 
                // then we will decrease count 
                // saying that frequency of one distinct letter of s1 becomes zero
                if(mp[s2[j]] == 0) 
                {
                    count--;
                }
            }
            
            if(j - i + 1 < k) // if window size is less than required window,
            {
                j++;
            }
            else if(j - i + 1 == k) // if window size is hits the required window,
            {
                if(count == 0) // then we check whether count is zero or not
                {
                //if yes we will return true saying that we are able to find out
                // one possible permutation of s1 in string s2
                    return true;
                }
                
                // if not, we will add the frequency of letter when we slide it
                if(mp.find(s2[i]) != mp.end())
                {
                    mp[s2[i]]++;
                    
                    // if it's frequency becomes 1, then increment count also
                    // saying that, one more distinct letter is added
                    if(mp[s2[i]] == 1)
                    {
                        count++;
                    }
                }
                
                // slide the window
                i++;
                j++;
            }
        }
        
        // after checking all the windows in s2, if we still uable to find any permuation, we will return false saying that no permutation of s1 exist in s2
        return false;
    }
};