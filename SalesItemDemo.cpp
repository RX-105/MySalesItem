#include <iostream>
#include "MySalesItem.h"
using namespace::std;

int main(){
    Sales_Item item1("978-7-121-15535-2",1,128.0),item2("978-7-121-15535-2",10,1280.0);
    // item1.units_sold = 10;
    // item1.revenue = 25.0;
    // item2.units_sold = 5;
    // item2.revenue = 10;
    item1.combine(item2);
    cout << item1.getAll() << endl;
}