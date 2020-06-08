class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;
        unordered_set<string>visit;
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 0));
        visit.insert(beginWord);

        while (!q.empty()) {
            string s = q.front().first;
            int step = q.front().second;
            q.pop();
            if (s == endWord) return step + 1;

            for (int i = 0; i < wordList.size(); ++i) {
                
                int count = 0;
                int length = wordList[i].size();
                for (int j = 0; j < length; ++j) {
                    if (wordList[i][j] != s[j]) {
                        count++;
                        if (count > 1) break;
                    }
                }
                if (count == 1) {
                    if (visit.find(wordList[i]) == visit.end())  //还没加入 
                    {
                        q.push(make_pair(wordList[i], step + 1));
                        visit.insert(wordList[i]);
                    }
                    
                }
            }
        }
        return 0;
    }
};