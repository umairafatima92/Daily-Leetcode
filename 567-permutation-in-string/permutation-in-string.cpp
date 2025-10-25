class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        vector<int> freq1(26, 0), freq2(26, 0);
        
        // Count frequency of s1 and first window in s2
        for(int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        // Check first window
        if(freq1 == freq2) return true;
        
        // Slide the window over s2
        for(int i = s1.size(); i < s2.size(); i++) {
            // include new char
            freq2[s2[i] - 'a']++;
            // remove old char
            freq2[s2[i - s1.size()] - 'a']--;
            
            if(freq1 == freq2) return true;
        }
        
        return false;
    }
};
