#include "Parede.h"
void squad(int x, int y, int w, int h, double scaleX, double scaleY, const std::array<unsigned int, 3> valor);
Parede::Parede() {
    //ctor
}

Parede::~Parede() {
    //dtor
}

Parede::Parede(double x, double y, double scaleX, double scaleY, int colidable) {
    this->x = x;
    this->y = y;
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    col.start(x, y, 10.0 * scaleX, 10.0 * scaleY);
    this->colidable = colidable;
}

void Parede::draw() {
    squad(this->x, this->y, 10, 10, this->scaleX, this->scaleY, {64, 77, 57});
}
