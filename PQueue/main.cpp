#include"main.hpp"

int main(void) {

    PQueue<int> pq = PQueue<int>();

    pq.enqueue(1, 1);
    pq.enqueue(2, 3);
    pq.enqueue(3, 2);

    std::cout << pq.dequeue() << " ";
    std::cout << pq.dequeue() << " ";
    std::cout << pq.dequeue() << " ";

    return 0;
}