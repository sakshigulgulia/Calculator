//
//  main.cpp
//  Calculator
//
//  Created by Sakshi Gulgulia on 8/22/22.
//

#include <iostream>
#include "Calc.hpp"

int main() {
    int sentinal = 0; // user decides when to stop the program
    do{
        std::cout << "Enter the number of expressions to be stored:" << std::endl;
        int values;
        std::cin >> values;
        
        if (values < 1) {
            std::cout << "ERROR: Must be positive and greater than 0" << std::endl;
        }
        else {
            Calc calc1 = Calc(values); // calc1 is the object for class Calc
            for(size_t cnt = 0; cnt < values; cnt++) {
                double ans = 0;
                bool flag = true;
                while(flag) {
                    std::string userStr;
                    std::cout << "Enter expression (Enter 'STOP' to reset calculations): \n" << " = " << ans << " + ... " << std::endl;
                    std::cin >> userStr;
                    if (userStr == "STOP") {
                        calc1.storedExpressions[calc1.getStored()] = std::to_string(ans);
                        flag = false;
                        break;
                    }
                    std::cout << userStr << " = " << calc1.process(userStr, ans);
                    ans = calc1.process(userStr, ans);
                }
                calc1.setStored(calc1.getStored() + 1); // get and set stored becuase stored is private
            }
            calc1.print();
            std::cout << "Press 1 to continue with another calculator, any other value to quit" << std::endl;
            std::cin >> sentinal;
        }
    } while(sentinal == 1);
    return 0; 
}
