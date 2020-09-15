#ifndef __ISORT_H__
#define __ISORT_H__

#include <vector>

class ISort
{
public:
    virtual void Sort(std::vector<int> &nums) = 0;
};

#endif // __ISORT_H__