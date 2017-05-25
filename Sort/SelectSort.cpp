//选择排序, 不稳定
//时间复杂度，平均O(n2),最坏O(n2)
//空间复杂度，O(1)
#include<iostream>
using namespace std;

void SelectSort(int array[], int length)
{
    if (array == nullptr || length==0)
        return;
    for (int i = 0; i < length-1;++i)
    {
        int min = i;
        for (int j = i + 1; j < length; ++j)
        {
            if (array[min]>array[j])
                min = j;
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
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
    SelectSort(array, length);
    cout << "After select sort, the array is [ ";
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
