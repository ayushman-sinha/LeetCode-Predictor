class NumArray {
public:
    vector<int>arr,segment;
    NumArray(vector<int>& nums) {
        arr=nums;
        segment.resize(nums.size()*4);
        segment[0]=buildTree(0,0,nums.size()-1);
    }
    int buildTree(int index,int start,int end){
        if(start==end) return arr[start];
        int mid=(start+end)/2;
        segment[2*index+1]=buildTree(2*index+1,start,mid);
        segment[2*index+2]=buildTree(2*index+2,mid+1,end);
        return segment[index]=segment[2*index+1]+segment[2*index+2];
    }
    int calc(int left, int right,int index,int start,int end){
        if(right<start||left>end) return 0;
        if(left<=start&&right>=end) return segment[index];
        int mid=(start+end)/2;
        
        return calc(left,right,2*index+1,start,mid)+calc(left,right,2*index+2,mid+1,end);
    }
    int sumRange(int left, int right) {
       
       return calc(left,right,0,0,arr.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */