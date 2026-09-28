class NumArray {
public:
    vector<int> m_n;
    NumArray(vector<int>& nums) {
        m_n = nums;
    }
    
    int sumRange(int left, int right) {
        int result=0;
        for (int i=left;i<=right;i++) {
            result+=m_n[i];
        }   
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */