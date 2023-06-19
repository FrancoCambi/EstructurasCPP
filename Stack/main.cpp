#include"main.hpp"

int main(void) {


    Stack<int> stack = Stack<int>();


    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << stack.pop();
    std::cout << stack.peek();


    return 0;
}