#include"LimitValue.hpp"




int main() {

    LimitValue<double> num(0, 100, 43.1);
    num += 23.4;
    std::cout << num.val() ;
}