#include "Stack.h"


Stack::Stack() = default;

Stack::Stack(unsigned int size) {
    _top = 0;
    _capacity = size;
    _array = new int [size];
}

bool Stack::empty() const {
    return _top == 0;
}

bool Stack::full() const {
    return _top == _capacity;
}

int Stack::pop() {
    return _array[--_top];
}

void Stack::push(int value) {
    _array[_top++] = value;
}

unsigned int Stack::size() const {
    return _top;
}

int Stack::top() const {
    return _array[_top-1];
}
