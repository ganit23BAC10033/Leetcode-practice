class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        stringstream ss(sentence);
        string temp;
        while (ss >> temp) {
            words.push_back(temp);
        }

        int m = searchWord.size();
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (words[i].size() >= m) {
                if (words[i].substr(0, m) == searchWord) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
};
