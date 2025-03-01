class SegmentTree{
    private:
    vector<int> seg;
    public:
    SegmentTree(){}
    SegmentTree(vector<int>& nums){
        int n = nums.size();
        seg.resize(4 * n);
        buildTree(nums, 0, 0, n - 1);
    }
    void buildTree(vector<int>& nums, int pos, int l, int r){
        if(l == r){
            seg[pos] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(nums, 2*pos + 1, l, mid);
        buildTree(nums, 2*pos + 2, mid + 1, r);
        seg[pos] = seg[2*pos + 1] + seg[2*pos + 2];
    }

    void updateTree(int pos, int l, int r, int idx, int val){
        if(idx < l || idx > r){
            return;
        }
        if(l == r){
            if(l == idx){
                seg[pos] = val;
            }
            return;
        }
        int mid = (l + r) / 2;
        updateTree(pos*2 + 1, l, mid, idx, val);
        updateTree(pos*2 + 2, mid + 1, r, idx, val);
        seg[pos] = seg[pos*2 + 1] + seg[pos*2 + 2];
    }

    int query(int qleft, int qright, int l, int r, int pos){
        if(qleft <= l && qright >= r){
            return seg[pos];
        }
        if(qleft > r || qright < l){
            return 0;
        }
        int mid = (l + r) / 2;
        return query(qleft, qright, l, mid, 2*pos + 1) + query(qleft, qright, mid + 1, r, 2*pos + 2);
    }
};


class NumArray {
private:
    SegmentTree st;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st = SegmentTree(nums);
    }
    
    void update(int index, int val) {
        st.updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return st.query(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */