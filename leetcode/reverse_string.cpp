class Solution {
public:
    void rShelper(vector<char>& s, int i, int j) {
        int temp;
        
        while (i < j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            
            ++i;
            --j;
        }
    }
    
    void reverseString(vector<char>& s) {
        rShelper(s, 0, s.size()-1);
    }
};
