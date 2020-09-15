#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__
#include "ISort.h"
class BubbleSort : public ISort
{
private:
    BubbleSort(/* args */);

public:
    void Sort(std::vector<int> &nums);
    static BubbleSort *Instance();
};
BubbleSort::BubbleSort(/* args */)
{
}

void BubbleSort::Sort(std::vector<int> &nums)
{
    for (int i = nums.size() - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
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

BubbleSort *BubbleSort::Instance()
{
    static BubbleSort instance;
    return &instance;
}

#endif // __BUBBLESORT_H__