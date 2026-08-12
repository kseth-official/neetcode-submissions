class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for(const auto& str: strs) {
            encoded += "##" + str + "--";
        }
        return encoded;
    }

    vector<string> decode(string s) {
        // we are assuming passed in string can be decoded
        // if (s.substr(0,6) != "#open#")
        //    return "";
        vector<string> decoded;
        auto continue_searching_from = 0;
        while (true) {
            size_t start = s.find("##", continue_searching_from);
            size_t end = s.find("--", continue_searching_from);

            if (start == string::npos) {
                break;
            }

            if (end == string::npos) {
                // string is not well-encoded
            }

            decoded.push_back(s.substr(start + 2, (end - (start + 2))));
            continue_searching_from = end + 2;
        }

        return decoded;
    }
};
