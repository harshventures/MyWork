#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &nums,int start,int end)
{
    int pivot = nums[end];
    int i = start-1;
    
    for(int j = start;j<end-1;j++)
    {
        if(nums[j]>=pivot)
        {
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[end]);
    return i+1;
}

int find_Kth_Maximum(vector<int> &nums,int k,int start,int end)
{
    if(start<=end)
    {
        int pivot_index = partition(nums,start,end);

        if(pivot_index==k-1)
        {
            return nums[pivot_index];
        }

        else if(pivot_index > k-1)
        {
            return find_Kth_Maximum(nums,k,start,pivot_index-1);
        }

        else
        {
            return find_Kth_Maximum(nums,k,pivot_index+1,end);
        }
    }
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int k=5;
    cout<<k<<"th maximum : "<<find_Kth_Maximum(nums,k,0,nums.size()-1)<<endl;

    return 0;
}