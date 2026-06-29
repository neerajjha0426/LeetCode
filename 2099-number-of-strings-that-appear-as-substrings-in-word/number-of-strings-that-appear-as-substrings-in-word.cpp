class Solution {
public:
    bool checkpattern(string word, string pattern) {

        for (int i = 0; i < word.size(); i++) {

            if (word[i] == pattern[0]) {

                int j = i;

                while (j < word.size() && (j - i) < pattern.size()) {

                    if (word[j] == pattern[j - i]) {
                        j++;
                    } else {
                        break;
                    }
                }

                if (j - i == pattern.size())
                    return true;
            }
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {

        int ans = 0;

        for (int i = 0; i < patterns.size(); i++) {
            if (checkpattern(word, patterns[i]))
                ans++;
        }

        return ans;
    }
};