#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> nums = {1,1,2,2,3,3,4,4,5,5};

    int new_size=1; // keep track of the new size of the array

    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]!=nums[new_size-1])
        {
            nums[new_size]=nums[i];
            new_size++;
        }
    }

    cout<<"Array Without Duplicates : "<<endl;

    for(int i=0;i<new_size;i++)
    {
        cout<<nums[i]<<" ";
    }

    cout<<endl;

    return 0;
}