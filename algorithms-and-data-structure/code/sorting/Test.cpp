#include <iostream>
#include <string>
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
using namespace std;

void PrintVector(vector<int> &nums)
{
    if (nums.empty())
        return;
    cout << nums[0];
    for (int i = 1; i < nums.size(); i++)
        cout << " " << nums[i];
    cout << endl;
}
int main()
{
    int num_case;
    cin >> num_case;
    vector<vector<int>> testcases(num_case, vector<int>());
    for (int i = 0; i < num_case; i++)
    {
        int size;
        cin >> size;
        testcases[i].reserve(size);
        for (int j = 0; j < size; j++)
        {
            int num;
            cin >> num;
            testcases[i].push_back(num);
        }
    }
    vector<ISort *> sorters = {
        HeapSort::Instance(),
        QuickSort::Instance(),
        MergeSort::Instance(),
        InsertionSort::Instance(),
        SelectionSort::Instance(),
        BubbleSort::Instance()};
    for (const auto s : sorters)
    {
        for (const auto &nums : testcases)
        {
            vector<int> dump(nums);
            s->Sort(dump);
            PrintVector(dump);
        }
        cout << endl;
    }
}