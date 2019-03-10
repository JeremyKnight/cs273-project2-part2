#include "List.h"
#include <iostream>
#include <string>
#include <assert.h>

using std::string;
using std::cout;

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

    assert(list.size() == 3);

    List<int> list2(list);

    traverse(list2);

    List<int> list3 = list2;
    traverse(list3);

    list3.pop_back();
    cout << "list3: " << std::endl;
    traverse(list3);
    list2.pop_front();
    cout << "list2: " << std::endl;
    traverse(list2);

    for(iterator<int> itr = list2.begin(); itr != list2.end(); itr++) {
        if(*itr == 4) {
            list2.insert(itr, 3);
        }
    }

    cout<< "list2:" << std::endl;
    traverse(list2);
    list2.push_back(6);
    list2.push_front(2);

    //check break stuff
    for(iterator<int> itr = list3.begin(); itr != list3.end(); itr++) {
        
        if(*itr == 4) {
            cout << "got here" << std::endl;
            list3.erase(itr);
            break;
        }
    }
    cout << "list3" << std::endl;
    traverse(list3);

    //check break stuff later
    for(iterator<int> itr = list2.begin(); itr != list2.end(); itr++) {
        if(*itr == 2) {
            list2.erase(itr);
        } else if(*itr == 4) {
            list2.erase(itr);
            break;
        }
    }
    cout << "list2: " << std::endl;
    traverse(list2);
    

    //assert(list.begin() != list2.begin())


    return 0;
}