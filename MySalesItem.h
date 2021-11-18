#pragma once
#include <iostream>
#include <string>
class Sales_Item{
    friend std::istream &read(std::istream&,Sales_Item&);
    friend std::ostream &write(std::ostream&,const Sales_Item&);
    public:
        Sales_Item() = default;
        Sales_Item(std::string isbn) : bookNo(isbn) {}
        Sales_Item(std::string isbn,unsigned sold,double revenue) :
                  bookNo(isbn), units_sold(sold), revenue(revenue) {}
        std::string isbn() const { return bookNo; };
        Sales_Item& combine(const Sales_Item&);
        double avg_price() const;
        std::string getAll() const;
    private:
        std::string bookNo;
        unsigned int units_sold = 0;
        double revenue = 0.0;
};

// Sales_Item的成员函数，将调用对象的属性和参数对象的属性合并
// @param src 需要合并的数据来源
Sales_Item& Sales_Item::combine(const Sales_Item& src) {
    this->units_sold += src.units_sold;
    this->revenue += src.revenue;
    return *this;
}

// 返回该对象的平均价格
// @return 如果销量不为零，则计算并返回平均价格；否则返回0
double Sales_Item::avg_price() const {
    if(this->units_sold)
        return this->revenue / this->units_sold;
    else
        return 0;
}

// Sales_Item类的成员函数，返回该类对象的属性
// @return 返回包含类对象属性的string
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