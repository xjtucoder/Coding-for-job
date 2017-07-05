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

    // search_n
    auto pos = search_n(coll.begin(), coll.end(), 4, 23, greater<int>());
    if(pos != coll.end())
        cout << "4 consecutive elements with value > 23 start with " << *pos << endl;
    else
        cout << "coll no have!" << endl;

    // find_first_of
    vector<int> searchcoll;
    INSERT_ELEMENTS(searchcoll, 21, 23);
    pos = find_first_of(coll.begin(), coll.end(), searchcoll.begin(), searchcoll.end());
    cout << "first in 21-23 is " << *pos << endl;

    // copy
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // fill_n
    fill_n(coll.end()-2, 2, 31);
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // replace 
    replace(coll.begin(), coll.end(), 25, 55);
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // unique
    unique(coll.begin(), coll.end());
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove
    remove(coll.begin(), coll.end(), 22);
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    coll.erase(remove_if(coll.begin(), coll.end(), bind2nd(greater<int>(), 30)), coll.end());
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // reverse
    vector<int> coll2;
    reverse_copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}