#include "List.h"
#include <iostream>
#include <string>
#include <assert.h>

using std::string;
using std:: cout;

int main() {
    List<int> list;

    list.push_back(5);
    //list.push_back("it");
    list.push_front(4);

    assert(list.size() == 2);

    List<int> list2(list);

    //assert(list.begin() != list2.begin())


    return 0;
}