#ifndef FASTSTACK_STACK_H
#define FASTSTACK_STACK_H

class Stack {
private:
    unsigned int _top;
    unsigned int _capacity;
    int *_array;
public:
    Stack();
    Stack(unsigned int size);
    bool empty() const;
    bool full() const;
    int pop();
    void push(int value);
    unsigned int size() const;
    int top() const;
};

#endif //FASTSTACK_STACK_H
