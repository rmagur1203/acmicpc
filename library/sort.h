#pragma once
#include <vector>

class Sort
{
    public:
    void mergeSort(int *data, int start, int end);
    private:
    static void merge(int *data, int start, int mid, int end);
};