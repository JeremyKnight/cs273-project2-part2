#include "List.h"
#include <iostream>
#include <string>
#include <assert.h>

using std::string;
using std::cout;

// used to iterate and print out the list given
// input: list: the list to print out
template <typename Type>
void traverse(List<Type> list) {
    for(iterator<Type> itr = list.begin(); itr != list.end(); itr++) {
            cout << *itr << ",";
    }
    cout << std::endl;
}

int main() {
    List<int> list;

    list.push_back(4);
    list.push_back(5);
    list.push_front(3);

    //ensures size is correct
    assert(list.size() == 3);

    List<int> list2(list);

    cout << "list3 and list2 equals each other" << std::endl;
    traverse(list2);

    List<int> list3 = list2;
    traverse(list3);

    list3.pop_back();
    cout << "test pop_back. list3: " << std::endl;
    traverse(list3);
    list2.pop_front();
    cout << "test pop_front. list2: " << std::endl;
    traverse(list2);

    for(iterator<int> itr = list2.begin(); itr != list2.end(); itr++) {
        if(*itr == 4) {
            list2.insert(itr, 3);
        }
    }

    cout<< "test insert. list2:" << std::endl;
    traverse(list2);
    list2.push_back(6);
    list2.push_front(2);

    iterator<int> temp = list3.begin();
    for(iterator<int> itr = list3.begin(); itr != list3.end(); itr++) {
      
        if(*itr == 4) {
            temp = itr;

        }
    }
    list3.erase(temp);

    cout << "test back erasing. list3" << std::endl;
    traverse(list3);

    iterator<int> temp2 = list2.begin();
    iterator<int> temp3 = list2.begin();

    for(iterator<int> itr = list2.begin(); itr != list2.end(); itr++) {
        if(*itr == 2) {
            temp2 = itr;
        } else if(*itr == 4) {
            temp3 = itr;
        }
    }
    cout << "tests front and middle erasing. list2: " << std::endl;
    traverse(list2);

    list2.erase(temp2);
    list2.erase(temp3);

    cout << "list2: " << std::endl;
    traverse(list2);

    return 0;
}