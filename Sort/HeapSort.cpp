//堆排序，时间复杂度，平均O(nlogn), 最坏O(nlogn)，不稳定
#include<iostream>
using namespace std;

void MakeHeap(int array[], int length)
{
    for (int i = length/2 -1; i >= 0; --i)
    {
        //左子节点是大于父节点且在子节点中最大
        if (2 * i + 2 < length)
        {
            if (array[2 * i + 1] > array[i] && array[2 * i + 1] > array[2 * i + 2])
            {
                int temp = array[i];
                array[i] = array[2 * i + 1];
                array[2 * i + 1] = temp;
            }
            //右子节点是大于父节点且在子节点中最大
            else if (array[2 * i + 2] > array[i] && array[2 * i + 2] > array[2 * i + 1])
            {
                int temp = array[i];
                array[i] = array[2 * i + 2];
                array[2 * i + 2] = temp;
            }
        }
        else if (array[2 * i + 1] > array[i])
        {
            int temp = array[i];
            array[i] = array[2 * i + 1];
            array[2 * i + 1] = temp;
        }
    }
    int tmp = array[0];
    array[0] = array[length - 1];
    array[length - 1] = tmp;
}

void HeapSort(int array[], int length)
{
    if (array == nullptr || length == 0)
        return;
    for (int i = length; i >=1; --i)
    {
        MakeHeap(array, i);
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
    HeapSort(array, length);
    cout << "After Heap sort, the array is [ ";
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
