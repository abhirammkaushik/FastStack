#include <cmath>
#include <stdexcept>
#include "FastStack.h"

const unsigned int INITIAL_SIZE = 8;
const unsigned int EXTENSION_POLICY = 2;


void FastStack::init_stacks(unsigned int start, unsigned int end) {
    for(unsigned int i = start; i < end; i++)
        ptr[i] = Stack((unsigned int) pow(EXTENSION_POLICY, i) * INITIAL_SIZE);
}

FastStack::FastStack() {
    _curr_stack_idx = 0;
    _stack_count = INITIAL_SIZE;
    ptr = new Stack[INITIAL_SIZE];
    init_stacks(0, _stack_count);
    cur = &ptr[0];
}

FastStack::~FastStack() {
    delete[] ptr;
    delete[] cur;
}

bool FastStack::empty() const {
    return _curr_stack_idx == 0 && cur->empty();
}

void FastStack::hop(bool fwd) {
    if (fwd)
        cur = &ptr[++_curr_stack_idx];
    else
        cur = &ptr[--_curr_stack_idx];
}

int FastStack::pop() {
    if (this->empty())
        throw std::runtime_error("pop from empty stack");
    if (cur->empty())
        hop(false);
    return cur->pop();
}

void FastStack::reserve(unsigned int new_stack_count) {
    Stack *new_ptr = new Stack[new_stack_count];
    for (int i = 0; i < _stack_count; ++i)
        new_ptr[i] = ptr[i];

    ptr = new_ptr;
    init_stacks(_stack_count, new_stack_count);
    _stack_count = new_stack_count;
}

void FastStack::push(int val) {
    if (cur->full()) {
        if (_curr_stack_idx == _stack_count - 1)
            reserve(_stack_count * EXTENSION_POLICY);
        hop(true);
    }
    cur->push(val);
}

int FastStack::top() const {
    if (this->empty())
        throw std::runtime_error("peeking empty stack");
    return cur->top();
}

unsigned FastStack::size() const{
    return INITIAL_SIZE * ((unsigned int) pow(EXTENSION_POLICY, _curr_stack_idx) - 1) + cur->size();
}