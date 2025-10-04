class Solution {
    public int maxArea(int[] height) {
        int mw=0;
        int left=0,right=height.length-1;

        while(left<right)
        {
            int w=right-left;
            int ht=Math.min(height[left],height[right]);
            int cw=w*ht;
            mw=Math.max(mw,cw);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return mw;
    }
}
