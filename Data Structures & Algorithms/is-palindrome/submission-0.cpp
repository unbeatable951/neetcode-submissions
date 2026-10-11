class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        int n = s.size();
        for(char ch:s)
        {
            if(isalnum(ch))
            {
                clean+=tolower(ch);
            }
        }

        int i=0;
        int j = clean.size()-1;
        while(i<j)
        {
            if(clean[i]!=clean[j])
            {
               return false;
            }
            i++;
            j--;
        }
        return true; 
    }
};
