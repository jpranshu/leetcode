int Max(int n1,int n2,int n3){
    return (n1 > n2) ? (n1 > n3 ? n1 : n3) : (n2 > n3 ? n2 : n3);
}
int maxCrossing(int *nums,int l,int m,int h){
    int lsum=-11111111;
    int rsum=-11111111;
    int sum=0;
    for(int i=m;i>=l;i--){
        sum+=nums[i];
        if(sum>lsum)
            lsum=sum;
    }
    sum=0;
    for(int i=m;i<=h;i++){
        sum+=nums[i];
        if(sum>rsum)
            rsum=sum;
    }
    return Max(lsum+rsum-nums[m],lsum,rsum);
}
int maxSub(int *nums,int l,int h){
    if(l>=h){
        return nums[l];
    }
    int m=(l+h)/2;
    return Max(maxSub(nums,l,m-1),maxSub(nums,m+1,h),maxCrossing(nums,l,m,h));
}

int maxSubArray(int* nums, int numsSize){
    return maxSub(nums,0,numsSize-1);
}