#include"main.hpp"

int main(void) {

    Queue<int> q = Queue<int>();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << q.dequeue() << std::endl;

    std::cout << q.dequeue() << std::endl;

    std::cout << q.peek() << std::endl;

    return 0;
}