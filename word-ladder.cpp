class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_map<string, int> m;
        queue<string> q;
        m[beginWord] = 1;
        q.push(beginWord);
        while (!q.empty()) {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); i++) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    newWord[i] = ch;
                    if (newWord == endWord) return m[word]+1;
                    if (wordList.find(newWord) != wordList.end() && m.find(newWord) == m.end()) {
                        q.push(newWord);
                        m[newWord] = m[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};


// find all the possible changing paths

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList){ 
        unordered_set<string> current, next;
        unordered_set<string> visited;
        /*** the key-part-structure : record-the-father-relation-ship-to-reconstruct-all-possible-path ***/
        unordered_map<string, vector<string>> father;
        vector<vector<string>> result;
        
        current.insert(beginWord);
        while(!current.empty()){
            for(const auto& state : current)
                visited.insert(state);
            for(const auto& state : current){
                if(state_is_target(state, endWord)){
                    vector<string> path;
                    gen_path(father, path, beginWord, state, result);
                }
                const auto new_states = state_extend(state, endWord, wordList, visited);
                for(const auto& new_state : new_states){
                    next.insert(new_state);
                    father[new_state].push_back(state);
                }
            }
            current.clear();
            swap(current, next);
        }
        return result;
    }
    
    /*** construct the word-change-path-inversely ***/
    void gen_path(unordered_map<string, vector<string>> &father, 
             vector<string> &path, const string& start, const string& word,
             vector<vector<string>> &result){
        path.push_back(word);
        if(word==start){
            result.push_back(path);
            /*** why not reverse path directly ? ***/
            reverse(result.back().begin(), result.back().end());
        } else {
            for(const auto &f : father[word]){
                gen_path(father, path, start, f, result);
            }
        }
        path.pop_back();
    }
    
    unordered_set<string> state_extend(const string &s, string endWord, unordered_set<string> &wordList, unordered_set<string>& visited){
        unordered_set<string> result;
        for(size_t i=0; i<s.size(); i++){
            string new_word(s);
            for(char c='a'; c<='z'; c++){
                if(c==new_word[i])  continue;
                swap(c, new_word[i]);
                if((wordList.find(new_word)!=wordList.end() || new_word==endWord) && 
                       visited.find(new_word)==visited.end()){
                    result.insert(new_word);           
                }
                swap(c, new_word[i]);
            }
        }
        return result;
    }
    
    bool state_is_target(const string &s, string end) {
        return s==end;
    }
};