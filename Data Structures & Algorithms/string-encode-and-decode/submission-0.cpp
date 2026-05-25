class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        if(strs.empty()) return encoded;
        for(auto& s : strs){
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<string> decoded;
        int i = 0;
        while(i < s.length()){
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            decoded.push_back(s.substr(i, length));
            i += length;
        }
        return decoded;
    }
};
