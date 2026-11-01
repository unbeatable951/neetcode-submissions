class Solution {
public:
    // Encode list of strings into one string
    string encode(vector<string>& strs) {

        string result = "";

        for(string s : strs) {

            result += to_string(s.size()) + "#" + s;

        }

        return result;
    }

    // Decode encoded string into original list
    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while(i < s.size()) {

            // Find the delimiter
            int j = i;

            while(s[j] != '#') {
                j++;
            }

            // Extract the length
            int len = stoi(s.substr(i, j - i));

            // Extract the original string
            string word = s.substr(j + 1, len);

            result.push_back(word);

            // Move to the next encoded string
            i = j + 1 + len;
        }

        return result;
    }
};
