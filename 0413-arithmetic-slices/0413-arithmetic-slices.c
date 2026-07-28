int numberOfArithmeticSlices(int* nums, int numsSize) {
    if (numsSize<3){
        return 0;
    }
    
        int ts=0;
        int cs=0;
        for(int i=2;i<numsSize;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            {
                cs++;
                ts+=cs;

            }
            else{
              
                cs=0;

            }
        }
        return ts;
    
}