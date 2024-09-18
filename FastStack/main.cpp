#include <stack>
#include <deque>

int main()
{
    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.size();

    while (!stack.empty())
    {
        int value = stack.top();
        stack.pop();
    }

    return 0;
}