
//快速排序，时间复杂度 平均O(n2)，最坏O(n2)
#include<iostream>
using namespace std;

void QuickSort(int array[], int low, int high)
{
    if (array == nullptr || low>=high)
        return;
    int first = low, last=high;
    int key = array[first];

    while (first < last)
    {
        while (first < last && array[last] >= key)
            last--;
        array[first] = array[last];
        while (first < last && array[first] <= key)
            first++;
        array[last] = array[first];
    }
    array[first] = key;
    QuickSort(array, low, first - 1);
    QuickSort(array, first + 1, high);
}

void Test(int array[], int length)
{
    if (array == nullptr || length == 0)
    {
        cout << "Invalid array !" << endl;
        return;
    }
    cout << "The original array is [ ";
    for (int i = 0; i < length; ++i)
    {
        if (i == length - 1)
            cout << array[i] << " ]" << endl;
        else
            cout << array[i] << ", ";
    }
    QuickSort(array, 0, length-1);
    cout << "After quick sort, the array is [ ";
    for (int i = 0; i < length; ++i)
    {
        if (i == length - 1)
            cout << array[i] << " ]" << endl;
        else
            cout << array[i] << ", ";
    }
}
int main()
{
    const int length = 10;
    int array1[] = { 3, 5, 1, 2, 4, 6, 7, 3, 9, 8 };
    Test(array1, length);

    int array2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    Test(array2, length);

    int array3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    Test(array3, length);

    int * array4 = nullptr;
    Test(array4, length);

    return 0;
}
