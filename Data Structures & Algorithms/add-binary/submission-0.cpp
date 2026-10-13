class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            return addBinary(b,a);
        int n=a.size();
        int m=b.size();

        string res = "";
        int carry=0;
        int i = n-1;
        int j = m-1;
        while (i >=0) {
            int aa = a[i] - '0';
            int bb;
            if (j >= 0)
                bb = b[j] - '0';
            else 
                bb = 0;
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