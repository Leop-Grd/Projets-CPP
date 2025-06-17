#include <iostream>

#include "Pen.hpp"

using namespace std;

int main(){
    Pen p1;
    Pen p2(10,20);

    p2.down();
    p2.move(100,20);

    cout << "pen p2 ->[" << p2.getState() << ',' << p2.getX() << ',' << p2.getY() << ']' << endl;

    
    p2.up();
    cout << "pen p2 ->[" << p2.getState() << ',' << p2.getX() << ',' << p2.getY() << ']' << endl;
    
    return 0;
}