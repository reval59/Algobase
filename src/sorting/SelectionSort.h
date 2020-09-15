#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__
#include "ISort.h"
class SelectionSort : public ISort
{
private:
    SelectionSort(/* args */);
    void Sort(std::vector<int> &nums);

public:
    static SelectionSort *Instance();
};
SelectionSort::SelectionSort(/* args */)
{
}

void SelectionSort::Sort(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int argmin = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[argmin] > nums[j])
                argmin = j;
        }
        int temp = nums[argmin];
        nums[argmin] = nums[i];
        nums[i] = temp;
    }
}

SelectionSort *SelectionSort::Instance()
{
    static SelectionSort instance;
    return &instance;
}

#endif // __SELECTIONSORT_H__