// Let’s write a class that implements a simple stack from scratch

// The class should be named Stack, and should contain:
// * A private fixed array of integers of length 10.
// * A private integer to keep track of the size of the stack.
// * A public member function named reset() that sets the size to 0.
// * A public member function named push() that pushes a value on 
// the stack. push() should return false if the array is already full, 
// and true otherwise.
// * A public member function named pop() that pops a value off the 
// stack and returns it. If there are no values on the stack, the code 
// should exit via an assert.
// * A public member function named print() that prints all the values in the stack.

#include <array>
#include <cassert>
#include <iostream>

class Stack {
private:
    int stack[10] {};
    int size{ 0 };

public:
    void reset();
    bool push(int);
    int pop();
    void print();
};

void Stack::reset()
{
    size = 0;
}

bool Stack::push(int element)
{
    if(size == 10)
        return false;
    stack[size] = element;
    size += 1;
    return true;
}

int Stack::pop()
{
    assert(size != 0 && "Cannot pop out of stack");
    return (stack[size--]);
}

void Stack::print()
{
    std::cout << "( ";
    for(int i = 0; i < size; i++)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << " )\n";
}

int main()
{
	Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
    stack.pop();
	stack.print();
 
	return 0;
}


