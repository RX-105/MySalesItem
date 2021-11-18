#pragma once
#include <iostream>
#include <string>
class Sales_Item{
    public:
        std::string isbn() const { return bookNo; };
        Sales_Item& combine(const Sales_Item&);
        double avg_price() const;
        std::string getAll() const;

        std::string bookNo;
        unsigned int units_sold = 0;
        double revenue = 0.0;
};

Sales_Item& Sales_Item::combine(const Sales_Item& src) {
    this->units_sold += src.units_sold;
    this->revenue += src.revenue;
    return *this;
}

//
double Sales_Item::avg_price() const {
    if(this->units_sold)
        return this->revenue / this->units_sold;
    else
        return 0;
}

// Sales_Item类的成员函数，返回该类对象的属性
std::string Sales_Item::getAll() const {
    return "Units sold:"+std::to_string(this->units_sold)+
           "\nRevenue:"+std::to_string(this->revenue);
}

// 从in读取图书的ISBN、销量和售价，保存到一个Sales_Item对象中。
// @param in 读取数据的来源流
// @param data 需要读取数据的Sales_Item对象
// @return 返回一个istream对象，可以用于判断流状态
std::istream &read(std::istream &in,Sales_Item &data) {
    double price = 0.0;
    in >> data.bookNo >> data.units_sold >> price;
    data.revenue = data.units_sold * price;
    return in;
}

// 将一个Sales_Item对象的数据输出到out上。
// @param out 用于输出的流
// @param data 需要输出信息的Sales_Item对象
// @return 返回一个ostream对象，可以用于判断流状态
std::ostream &write(std::ostream &out,const Sales_Item &data) {
    out << data.isbn() << " " << data.units_sold << " "
        << data.revenue << " " << data.avg_price();
    return out;
}