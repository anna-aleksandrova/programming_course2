#include <iostream>
#include <cstring>
#include <cmath>

class Currency {
    std::string name;
    unsigned int value, cents;
    public:
        Currency(std::string name_, unsigned int value_, unsigned int cents_);
        Currency(Currency const& c);
        static Currency input();
        void show();
        Currency add(Currency const& c);
        Currency subtract(Currency const& c);
        friend void c_converter(Currency c, std::string new_name, unsigned int new_value);
};

Currency::Currency(std::string name_, unsigned int value_, unsigned int cents_) {
    name = name_;
    value = value_;
    if (cents_ >= 100) {
        cents = cents_ % 100;
        value += cents_ / 100;
    }
    else {
        cents = cents_;
    }
}

Currency::Currency(Currency const& c) {
    name = c.name;
    value = c.value;
    cents = c.cents;
}

Currency Currency::input() {
    std::string name;
    int value;
    unsigned int cents;
    std::cout << "Enter a name of the currency: ";
    std::cin >> name;
    std::cout << "Value: ";
    std::cin >> value;
    std::cout << "Cents: ";
    std::cin >> cents;
    return Currency(name, value, cents);
}

void Currency::show() {
    std::cout << "Name: " << name << "; value: " << value << "; cents: " << cents << std::endl;
}

Currency Currency::add(Currency const& c) {
    if (name == c.name) {
        return Currency(name, value + c.value, cents + c.cents);
    }
    else {
        return *this;
    }
}

Currency Currency::subtract(Currency const& c) {
    if (name == c.name) {
        if (cents < c.cents) {
            return Currency(name, value-1-c.value, 100+cents-c.cents);
        }
        else {
            return Currency(name, value-c.value, cents-c.cents);
        }
    }
    return *this;
}

// it's assumed that we have <new_value> to <c.value> rate
void c_converter(Currency c, std::string new_name, unsigned int new_value) {
    std::cout << "The currency before convertion:\n";
    c.show();
    Currency c_new(new_name, c.value * new_value, c.cents * new_value);
    std::cout << "The currency after convertion:\n";
    c_new.show();
}

class Product {
    std::string product_name;
    double value;
    std::string currency_name;
    std::string unit_of_measure;
    public:
        Product(std::string p_name, double value_, std::string c_name, std::string un_m);
        Product(Product const& p);
        static Product input();
        void show();
        Product add(Product const& c);
        Product subtract(Product const& c);
        friend void p_converter(Product p, std::string new_cname, unsigned int new_cvalue);
};

Product::Product(std::string p_name, double value_, std::string c_name, std::string un_m) {
    product_name = p_name;
    value = value_;
    currency_name = c_name;
    unit_of_measure = un_m;
}

Product::Product(Product const& p) {
    product_name = p.product_name;
    value = p.value;
    currency_name = p.currency_name;
    unit_of_measure = p.unit_of_measure;
}

Product Product::input() {
    std::string product_name, currency_name, unit_of_measure;
    double value;
    std::cout << "Enter a name of the product: ";
    std::cin >> product_name;
    std::cout << "Value: ";
    std::cin >> value;
    std::cout << "Currency: ";
    std::cin >> currency_name;
    std::cout << "Unit of measure: ";
    std::cin >> unit_of_measure;
    return Product(product_name, value, currency_name, unit_of_measure);
}

void Product::show() {
    std::cout << "Name: " << product_name << "; value: " << value << "; currency: " << currency_name << "; unit of measure: " << unit_of_measure << std::endl;
}

Product Product::add(Product const& c) {
    if (product_name == c.product_name && currency_name == c.currency_name && unit_of_measure == c.unit_of_measure) {
        return Product(product_name, value + c.value, currency_name, unit_of_measure);
    }
    else {
        return *this;
    }
}

Product Product::subtract(Product const& c) {
    if (product_name == c.product_name && currency_name == c.currency_name && unit_of_measure == c.unit_of_measure) {
        return Product(product_name, value + c.value, currency_name, unit_of_measure);
    }
    else {
        return *this;
    }
}

// it's assumed that we have <new_value> to <c.value> rate
void p_converter(Product p, std::string new_name, unsigned int new_value) {
    std::cout << "The product before currency convertion:\n";
    p.show();
    Product p_new(p.product_name, p.value * new_value, new_name, p.unit_of_measure);
    std::cout << "The product after currency convertion:\n";
    p_new.show();
}

int main() {
    std::string name1("USD");
    std::string name2("EUR");
    Currency c1(name1, 100, 100);
    Currency c2(name1, 100, 99);
    Currency c3 = c1.subtract(c2);
    c3.show();

    std::cout << std::endl;
    c_converter(c1, name1, 0.024);

    std::cout << std::endl;
    std::string product("Apple");
    Product p(product, 7, name1, std::string ("kg"));
    p_converter(p, name2, 0.95);
}
