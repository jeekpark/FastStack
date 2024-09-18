#include <iostream>
#include <cassert>
#include "FastStack.h"

void TestFastStack()
{
    // Test default constructor
    FastStack<int> stack;
    assert(stack.Empty());
    assert(stack.Size() == 0);

    // Test Push and Top
    stack.Push(10);
    assert(!stack.Empty());
    assert(stack.Size() == 1);
    assert(stack.Top() == 10);

    stack.Push(20);
    assert(stack.Top() == 20);
    assert(stack.Size() == 2);

    // Test Emplace
    stack.Emplace(30);
    assert(stack.Top() == 30);
    assert(stack.Size() == 3);

    // Test Pop
    stack.Pop();
    assert(stack.Top() == 20);
    assert(stack.Size() == 2);

    // Test Clear
    stack.Clear();
    assert(stack.Empty());
    assert(stack.Size() == 0);

    // Test constructor with vector input
    std::vector<int> vec = { 1, 2, 3 };
    FastStack<int> stackFromVec(vec);
    assert(stackFromVec.Size() == 3);
    assert(stackFromVec.Top() == 3);

    // Test move constructor
    FastStack<int> movedStack(std::move(stackFromVec));
    assert(movedStack.Size() == 3);
    assert(movedStack.Top() == 3);
    assert(stackFromVec.Size() == 0); // After move, original stack should be empty

    // Test comparison operators
    FastStack<int> stack1;
    FastStack<int> stack2;

    stack1.Push(1);
    stack1.Push(2);

    stack2.Push(1);
    stack2.Push(2);

    assert(stack1 == stack2);
    stack2.Push(3);
    assert(stack1 != stack2);
    assert(stack1 < stack2);
    assert(stack2 > stack1);

    // Test Swap function
    FastStack<int> stack3;
    stack3.Push(5);

    stack1.Swap(stack3);
    assert(stack1.Top() == 5);
    assert(stack3.Top() == 2);

    // Test Capacity and Reserve
    stack.Reserve(10);
    assert(stack.Capacity() >= 10);

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    TestFastStack();
    return 0;
}
