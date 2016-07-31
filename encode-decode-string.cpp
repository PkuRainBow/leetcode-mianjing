class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for (auto a : strs) {
            result.append(to_string(a.size()).append("/").append(a));
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i  = 0;
        while (i < s.size()) {
            //get the / seperator position
            auto found = s.find("/", i);
            //get the len of the current string
            int len = stoi(a.substr(i, found));
            //push back the current string to the result
            result.push_back(s.substr(found + 1, len));
            //update the i to point to the next start position of the string
            i = found + len + 1;
        }
        return res;
    }
};

class Codec {
public:
    string encode(vector<string>& strs) {
        string result = "";
        for (auto a : strs) {
            //size + / + string
            result.append(to_string(a.size()).append("/").append(a));
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        while (!s.empty()) {
            int found = s.find("/");
            int len = stoi(s.substr(0, found));
            result.push_back(s.substr(found + 1, len));
            i = found + len + 1;
        }
        return result;
    }
}