#include <iostream>

#include "Complex.hpp"

using namespace std;

int main(){
    Complex c1(10,20);
    Complex c2(2,2);
    Complex c3=100;

    c3.printOn(cout);
    (c1+c2).printOn(cout << endl);
    cout << endl << c2.Module();

    double module=c2;
    cout << endl << module;

    return 0;
}
