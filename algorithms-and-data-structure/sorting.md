---
description: Implementation of various sorting algorithms.
---

# Sorting

## 1. Merge Sort

```cpp
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
```

## 2. Quick Sort

```cpp
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
void QuickSort::Sort(std::vector<int> &nums)
{
    if (nums.size() < 2)
        return;
    Sort(nums, 0, nums.size() - 1);
}
```

## 3. Heap Sort

```cpp
void HeapSort::Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
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
```

## 4. Bubble Sort

```cpp
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
```

## 5. Insertion Sort

```cpp
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
```

## 6. Selection Sort

```cpp
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
```