class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> u;

        for (const auto& email: emails) {
            string local = email.substr(0, email.find('@'));
            string dom = email.substr(email.find('@') + 1);
            string uptoPlus = local.substr(0, local.find('+'));

            string iDeleted = "";
            iDeleted.reserve(uptoPlus.size());
            for (int j=0;j<uptoPlus.size();j++) {
                if (uptoPlus[j] == '.') 
                    continue;
                iDeleted += uptoPlus[j];
            }

            u.insert(iDeleted + dom);
        }

        return u.size();
    }
};