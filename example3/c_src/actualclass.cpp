#include "actualclass.h"

ActualClass::ActualClass(double value) {
    this->_value = value;
}

double ActualClass::getValue() {
    return this->_value;
}

double ActualClass::add(double toAdd) {
    this->_value += toAdd;
    return this->_value;
}
