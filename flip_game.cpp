/*
You are playing the following Flip Game with your friend: Given a string that contains
 only these two characters: + and -, you and your friend take turns to flip two consecutive
 "++" into "--". The game ends when a person can no longer make a move and therefore the
 other person will be the winner.
Write a function to compute all possible states of the string after one valid move.
For example, given s = "++++", after one move, it may become one of the following states:
[
  "--++",
  "+--+",
  "++--"
]
If there is no valid move, return an empty list [].
 */


class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> moves;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') { 
                s[i] = s[i + 1] = '-';
                moves.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return moves;
    }
};

/*
You are playing the following Flip Game with your friend: Given a string that contains
 only these two characters: + and -, you and your friend take turns to flip two
 consecutive "++" into "--". The game ends when a person can no longer make a move and
 therefore the other person will be the winner.
Write a function to determine if the starting player can guarantee a win.
For example, given s = "++++", return true. The starting player can guarantee a win
 by flipping the middle "++" to become "+--+".
Follow up:
Derive your algorithm's runtime complexity.
 */

class Solution {
public:
    bool canWin(string s) {
        if (s.size() == 0) {
            return false;
        }
        for (size_t i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-'; s[i + 1] = '-';
                if (!canWin(s)) { return true; }
                s[i] = '+'; s[i + 1] = '+';
            }
        }
        return false;
    }
};

/*** state memorization solution **/
class Solution3 {
public:
    bool canWin(string s) {
        if (!lookup_.count(s)) {
            const int n = s.length();
            bool is_win = false; 
            for (int i = 0; !is_win && i < n - 1; ++i) {
                if (s[i] == '+') {
                    for (; !is_win && i < n - 1 && s[i + 1] == '+'; ++i) {
                        s[i] = s[i + 1] = '-';
                        is_win = !canWin(s); 
                        s[i] = s[i + 1] = '+';
                        lookup_[s] = is_win;
                    }
                }
            }
        }
        return lookup_[s];  
    }
private:
    unordered_map<string, bool> lookup_;
};