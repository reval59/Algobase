#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "ISort.h"
class QuickSort : public ISort
{
private:
    QuickSort(/* args */);
    int Partition(std::vector<int> &nums, int begin, int end);
    void Sort(std::vector<int> &nums, int begin, int end);

public:
    static QuickSort *Instance();
    void Sort(std::vector<int> &nums);
};
QuickSort::QuickSort(/* args */)
{
}

int QuickSort::Partition(std::vector<int> &nums, int begin, int end)
{
    int pivot = end;
    int low = begin;
    for (int i = begin; i < end; i++)
    {
        if (nums[i] <= nums[pivot])
        {
            int temp = nums[low];
            nums[low++] = nums[i];
            nums[i] = temp;
        }
    }
    int temp = nums[low];
    nums[low] = nums[pivot];
    nums[pivot] = temp;
    pivot = low;
    return pivot;
}

void QuickSort::Sort(std::vector<int> &nums, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = Partition(nums, begin, end);
    Sort(nums, begin, mid - 1);
    Sort(nums, mid + 1, end);
}

QuickSort *QuickSort::Instance()
{
    static QuickSort instance;
    return &instance;
}

void QuickSort::Sort(std::vector<int> &nums)
{
    if (nums.size() < 2)
        return;
    Sort(nums, 0, nums.size() - 1);
}

#endif // __QUICKSORT_H__