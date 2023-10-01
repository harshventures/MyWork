#include<iostream>
#include<vector>

using namespace std;

void findMaxMin(vector<int> &nums,int &max1,int &max2,int &min1,int &min2)
{
    if(nums[0]>nums[1])
    {
        max1=nums[0];
        max2=nums[1];
    }

    else
    {
        max1=nums[1];
        max2=nums[0];
    }

    if(nums[0]<nums[1])
    {
        min1=nums[0];
        min2=nums[1];
    }

    else
    {
        min1=nums[1];
        min2=nums[0];
    }

    for(int i=2;i<nums.size();i++)
    {
        if(nums[i]>max1)
        {
            max2=max1;
            max1=nums[i];
        }

        else if(nums[i]>max2)
        {
            max2=nums[i];
        }

        if(nums[i]<min1)
        {
            min2=min1;
            min1=nums[i];
        }

        else if(nums[i]<min2)
        {
            min2=nums[i];
        }
    }
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int max1,max2,min1,min2;

    findMaxMin(nums,max1,max2,min1,min2);

    cout<<"First maximum : "<<max1<<endl;
    cout<<"Second maximum : "<<max2<<endl;
    cout<<"First minimum : "<<min1<<endl;
    cout<<"Second minimum : "<<min2<<endl<<endl;

    return 0;
}