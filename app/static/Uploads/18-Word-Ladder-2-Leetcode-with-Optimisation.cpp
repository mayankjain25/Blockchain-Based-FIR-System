class Solution {
public:
    void dfs(string word, unordered_map<string,int>&wordLadder, vector<string>currSequence, vector<vector<string>>&ans, string beginWord){

        if(word==beginWord){
            vector<string> vec = currSequence;
            reverse(vec.begin(),vec.end());

            ans.push_back(vec);
            return;
        }

        for(int i=0;i<word.size();i++){
            char original = word[i];

            string wordCopy = word;

            for(char ch = 'a';ch<='z';ch++){
                word[i] = ch;
                if(wordLadder[word]>0 and wordLadder[word]<wordLadder[wordCopy]){
                    currSequence.push_back(word);
                    dfs(word,wordLadder,currSequence,ans,beginWord);
                    currSequence.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>wordLadder;

        unordered_set<string>wordSet(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        wordSet.erase(beginWord);
        q.push({beginWord,1});

        wordLadder[beginWord] = 1;
        while(!q.empty()){
            string wd = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(int i=0;i<wd.size();i++){
                char original = wd[i];

                for(char ch = 'a';ch<='z';ch++){
                    wd[i] = ch;
                    if(wordSet.find(wd)!=wordSet.end()) {
                        q.push({wd,steps+1}); 
                        wordLadder[wd]= steps+1;
                        wordSet.erase(wd);
                    }
                }

                wd[i] = original;
            }
        }
        vector<vector<string>>ans;
        dfs(endWord,wordLadder,{endWord},ans, beginWord);

        return ans;
    }
};
