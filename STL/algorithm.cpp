#include "algo.h"
using namespace std;

// 仿函数
// class FunctionObjectType {
// public:
//     void operator() () {
//         statements
//     }
// };

template <class T>
class AddValue {
private:
    T theValue;

public:
    AddValue(const T& v) : theValue(v){

    }

    void operator() (T& elem) const {
        elem += theValue;
    } 
};

void print(int elem)
{
    cout << elem << ' ';
}

template <class T>
bool isEven(T elem)
{
    return elem % 2 == 0;
}

template <class T>
bool opposite(T elem1, T elem2)
{
    return -elem1 < -elem2;
}

int main()
{
    vector<int> coll;

    // for_each
    INSERT_ELEMENTS(coll,1,9);
    for_each (coll.begin(), coll.end(), print);
    cout << endl;

    for_each(coll.begin(), coll.end(), AddValue<int>(10));
    PRINT_ELEMENTS(coll);

    for_each(coll.begin(), coll.end(), AddValue<int>(*coll.begin()));
    PRINT_ELEMENTS(coll);

    // count  count_if
    cout << "coll has " << count(coll.begin(), coll.end(), 22) << " 22" << endl;
    
    cout << "coll has " << count_if(coll.begin(), coll.end(), isEven<int>) << " even number" << endl;

    // min_element max_element
    cout << "the max number in coll is " << *max_element(coll.begin(), coll.end()) << endl;
    cout << "the max opposite number in coll is " << *max_element(coll.begin(), coll.end(), opposite<int>) <<endl;

    cout << "the min number in coll is " << *min_element(coll.begin(), coll.end()) << endl;
    cout << "the min opposite number in coll is " << *min_element(coll.begin(), coll.end(), opposite<int>) <<endl;

    // find find_if
    if(find(coll.begin(), coll.end(), 30) != coll.end())
        cout << "coll found 30!" << endl;
    else
        cout << "coll not found 30!" << endl;
    if(find_if(coll.begin(), coll.end(), isEven<int>) != coll.end())
        cout << "coll 1st even number is " << *find_if(coll.begin(), coll.end(), isEven<int>) << endl;
    else
        cout << "coll has no even number!" << endl;
}