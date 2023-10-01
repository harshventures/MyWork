#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,1,2,3,4,5};
    int max_length = 0,start_index = -1;

    for(int i=0;i<nums.size();i++)
    {
        int length=1; // start counting from current element
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]>nums[j-1])
            {
                length++;
            }

            else
            {
                break;
            }
        }

        if(length>max_length)
        {
            max_length=length;
            start_index=i;
        }
    }

    cout<<"Longest Monotonically increasing sequence:"<<endl;

    for(int i=start_index;i<start_index+max_length;i++)
    {
        cout<<nums[i]<<" ";
    }

    cout<<endl;
    cout<<"Start Index : "<<start_index<<endl;
    
    return 0;
}