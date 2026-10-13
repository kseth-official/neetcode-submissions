class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();

        string res = "";

        int carry=0;

        int i = n-1;
        int j = m-1;

        while (i >=0 || j>=0) {
            int aa = i>=0 ? a[i] - '0' : 0;
            int bb = j>=0 ? b[j] - '0' : 0;
            res += to_string(aa ^ bb ^ carry);
            carry = (aa & bb) | (carry & (aa ^ bb));
            i--;
            j--;
        }
        if (carry == 1)
            res.push_back('1');

        reverse(res.begin(), res.end());

        return res;
    }
};