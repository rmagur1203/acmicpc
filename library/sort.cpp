#include "sort.h"
 
void Sort::merge(int *data, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    std::vector<int> sorted;
    
    while(i <= mid && j <= end)    {
        if(data[i] <= data[j]){
            sorted.push_back(data[i]);
            i++;
        }else{
            sorted[k] = data[j];
            j++;
        }
    }
    if(i > mid){
        for(int t = j; t<=end; t++){
            sorted.push_back(data[t]);
        }
    }else{
        for(int t = i; t<=mid; t++){
            sorted.push_back(data[t]);
        }
    }
    
    std::copy(sorted.begin(), sorted.end(), data + start);
} 
 
void Sort::mergeSort(int *data, int start, int end){
    if(start < end){
        int mid = (start+end)/2;
        mergeSort(data, start, mid); // 좌측 정렬 
        mergeSort(data, mid+1, end); // 우측 정렬 
        merge(data, start, mid, end);
    }
}​