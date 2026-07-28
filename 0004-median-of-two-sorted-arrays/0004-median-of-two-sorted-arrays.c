int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int m = nums1Size + nums2Size;
    double med = 0.0;
    int p = 0;
    int nums3[m];
    
    for (int i = 0; i < nums1Size; i++) {
        nums3[p] = nums1[i];
        p++;
    }
    
    
    
    for (int i = 0; i < nums2Size; i++) {
        nums3[p] = nums2[i];
        p++;
    }
    qsort(nums3, p, sizeof(int), compare);
    for (int i = 0; i <p; i++) {
        
       printf("%d ",nums3[i]);
    }
    
    if (p % 2 == 0) {
        med = (nums3[p / 2 - 1] + nums3[p / 2]) / 2.0;
    } else {
        med = nums3[p / 2];
    }
    
    return med;
}