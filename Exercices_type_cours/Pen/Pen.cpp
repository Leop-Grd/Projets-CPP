#include "Pen.hpp"

Pen::Pen() : m_x(0), m_y(0), m_state(true)
{
}

Pen::Pen(int x, int y): m_x(x), m_y(y), m_state(true)
{
}

Pen::~Pen()
{
}

void Pen::down(){
    m_state=true;
}

void Pen::up(){
    m_state=false;
}

bool Pen::getState() const {
    return m_state;
}

int Pen::getX() const {
    return m_x;
}

int Pen::getY() const {
    return m_y;
}

void Pen::move(int x, int y){
    m_x += x;
    m_y += y;
}


