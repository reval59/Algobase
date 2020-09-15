#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include "ISort.h"
class MergeSort : public ISort
{
private:
    MergeSort();
    void Merge(std::vector<int> &nums, int begin, int end, int mid);
    void Sort(std::vector<int> &nums, int begin, int end);

public:
    void Sort(std::vector<int> &nums);
    static MergeSort *Instance();
};
MergeSort::MergeSort()
{
}

void MergeSort::Merge(std::vector<int> &nums, int begin, int end, int mid)
{
    std::vector<int> left(mid - begin + 1);
    std::vector<int> right(end - mid);

    for (int i = 0; i < left.size(); i++)
        left[i] = nums[begin + i];
    for (int i = 0; i < right.size(); i++)
        right[i] = nums[mid + 1 + i];

    int i = 0, j = 0, k = begin;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
    }

    while (i < left.size())
        nums[k++] = left[i++];
    while (j < right.size())
        nums[k++] = right[j++];
}

void MergeSort::Sort(std::vector<int> &nums, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    Sort(nums, begin, mid);
    Sort(nums, mid + 1, end);
    Merge(nums, begin, end, mid);
}
void MergeSort::Sort(std::vector<int> &nums)
{
    if (nums.size() < 2)
        return;
    Sort(nums, 0, nums.size() - 1);
}

MergeSort *MergeSort::Instance()
{
    static MergeSort instance;
    return &instance;
}

#endif // __MERGESORT_H__