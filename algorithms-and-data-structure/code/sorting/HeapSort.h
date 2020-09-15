#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__
#include "ISort.h"
class HeapSort : public ISort
{
private:
    HeapSort(/* args */);
    void Swap(int &a, int &b);
    void Heapify(std::vector<int> &nums, int end, int current);

public:
    static HeapSort *Instance();
    void Sort(std::vector<int> &nums);
};
HeapSort::HeapSort(/* args */)
{
}

void HeapSort::Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

HeapSort *HeapSort::Instance()
{
    static HeapSort instance;
    return &instance;
}

void HeapSort::Heapify(std::vector<int> &nums, int end, int current)
{
    int left = current * 2 + 1;
    if (left > end)
        return;
    int right = current * 2 + 2;
    if (right > end)
        right = left;

    int argmax = (nums[left] > nums[right]) ? left : right;
    argmax = (nums[argmax] < nums[current]) ? current : argmax;

    if (argmax != current)
    {
        Swap(nums[argmax], nums[current]);
        Heapify(nums, end, argmax);
    }
}

void HeapSort::Sort(std::vector<int> &nums)
{
    for (int i = nums.size() / 2; i >= 0; i--)
    {
        Heapify(nums, nums.size() - 1, i);
    }
    for (int i = nums.size() - 1; i > 0; i--)
    {
        Swap(nums[0], nums[i]);
        Heapify(nums, i - 1, 0);
    }
}
#endif // __HEAPSORT_H__