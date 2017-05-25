//归并排序, 稳定
//时间复杂度，平均O(nlogn),最坏O(nlogn)
//空间复杂度，O(n)
#include<iostream>
using namespace std;

void Merge(int array[], int tempArr[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    while (i != mid + 1 && j != end + 1)
    {
        if (array[i] > array[j])
            tempArr[k++] = array[j++];
        else
            tempArr[k++] = array[i++];
    }
    while (i != mid + 1)
        tempArr[k++] = array[i++];
    while (j != end + 1)
        tempArr[k++] = array[j++];
    for (i = start; i <= end; i++)
        array[i] = tempArr[i];
}
void MergeSort(int array[], int tempArr[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        MergeSort(array, tempArr, start, mid);
        MergeSort(array, tempArr, mid + 1, end);
        Merge(array, tempArr, start, mid, end);
    }
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
    int temp[10];
    MergeSort(array, temp, 0, length-1);
    cout << "After merge sort, the array is [ ";
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
