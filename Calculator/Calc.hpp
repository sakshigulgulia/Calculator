//
//  Calc.hpp
//  Calculator
//
//  Created by Sakshi Gulgulia on 8/22/22.
//

#ifndef Calc_hpp
#define Calc_hpp

#include <stdio.h>
#include <string>

class Calc {
public:
    Calc(int value);
    Calc(const Calc &rhs);
    ~Calc();
    const Calc &operator = (const Calc &rhs);
    
    double process(std::string userInt, double prevValue);
    void print();
    std::string* storedExpressions;
    void setStored(size_t newStored);
    size_t getStored();
private:
    size_t stored;
};
    
#endif /* Calc_hpp */
