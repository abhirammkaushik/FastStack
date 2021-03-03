#ifndef FASTSTACK_FASTSTACK_H
#define FASTSTACK_FASTSTACK_H

#include "Stack.h"

class FastStack {
private:
    unsigned int _curr_stack_idx;
    unsigned int _stack_count;
    Stack *ptr;
    Stack *cur;
    void hop(bool fwd);
    void init_stacks(unsigned int start, unsigned int end);
    void reserve(unsigned int new_stack_count);
public:
    FastStack();
    ~FastStack();
    bool empty() const;
    int pop();
    void push(int x);
    unsigned int size() const;
    int top() const;
};

#endif //FASTSTACK_FASTSTACK_H
