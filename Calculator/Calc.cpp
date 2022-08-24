//
//  Calc.cpp
//  Calculator
//
//  Created by Sakshi Gulgulia on 8/22/22.
//

#include <iostream>
#include <stddef.h>
#include <cmath>
#include "Calc.hpp"

Calc::Calc(int value):storedExpressions(new std::string[value]), stored(0) {
    
}

Calc::Calc(const Calc &rhs) {
    if(storedExpressions != nullptr) {
        storedExpressions = new std::string[rhs.stored];
    }
}

Calc::~Calc() {
    delete[] storedExpressions;
    storedExpressions = nullptr;
    stored = 0;
}

const Calc &Calc::operator = (const Calc &rhs) {
    if(this != &rhs) {
        Calc temp(rhs);
        std::swap(storedExpressions, temp.storedExpressions);
        std::swap(stored, temp.stored);
    }
    return *this;
}

double Calc::process(std::string userInt, double prevValue) {
    std::string cleansedString = "";
    for(size_t i=0; i < userInt.size(); i++) {
        if(userInt[i] == '=' || userInt[i] == ' ' || userInt[i] == '(' || userInt[i] == ')') {
        }
        else {
            cleansedString += userInt[i];
        }
    }
    double value = std::stod(cleansedString.substr(1, cleansedString.length()-1));
    if(cleansedString[0] == '^') {
        return pow(prevValue, value);
    }
    else if(cleansedString[0] == '*' || cleansedString[0] == '/') {
        if(cleansedString[0] == '*') {
            return prevValue*value;
        }
        else {
            if(value ==0){
                std::exit(0);
            }
            else {
                return prevValue/value;
            }
        }
    }
    else if(cleansedString[0] == '+' || cleansedString[0] == '-') {
        if(cleansedString[0] == '+') {
            return prevValue+value;
        }
        else {
            return prevValue-value;
        }
    }
    else {
        std::cout << "ERROR" << std::endl;
        return -1;
    }
    return -1;
}

void Calc::print() {
    std::cout << "You have " << stored << " expressions stored: ";
    for(size_t i = 0; i < stored; ++i){
        std::cout << "Expression " << i+1 << " result is: \n";
        std::cout << storedExpressions[i] << std::endl;
    }
}

void Calc::setStored(size_t newStored) { 
    stored = newStored;
}

size_t Calc::getStored() {
    return stored;
}

