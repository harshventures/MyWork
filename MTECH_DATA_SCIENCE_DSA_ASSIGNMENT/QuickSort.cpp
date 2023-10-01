#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &nums,int start,int end)
{
    int pivot = nums[end];
    int i = start-1;

    for(int j=start;j<=end-1;j++)
    {
        if(nums[j]<pivot)
        {
            i++;
            swap(nums[i],nums[j]);
        }
    }

    swap(nums[i+1],nums[end]);
    return i+1;
}

void quickSort(vector<int> &nums,int start,int end)
{
    if(start<end)
    {
        int pivot_index=partition(nums,start,end);
        quickSort(nums,start,pivot_index-1);
        quickSort(nums,pivot_index+1,end);
    }
}

int main()
{
    vector<int> nums={5,3,2,1,4};
    cout<<"Original array : ";
    
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    quickSort(nums,0,nums.size()-1);

    cout<<"Sorted Array : ";

    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;
    
    return 0;
}