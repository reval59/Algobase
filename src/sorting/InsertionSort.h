#ifndef __INSERTIONSORT_H__
#define __INSERTIONSORT_H__
#include "ISort.h"
class InsertionSort : public ISort
{
private:
    InsertionSort(/* args */);

public:
    static InsertionSort *Instance();
    void Sort(std::vector<int> &nums);
};
InsertionSort::InsertionSort(/* args */)
{
}

InsertionSort *InsertionSort::Instance()
{
    static InsertionSort instance;
    return &instance;
}

void InsertionSort::Sort(std::vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (nums[j - 1] > nums[j])
            {
                int temp = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

#endif // __INSERTIONSORT_H__