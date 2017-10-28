#include <iostream>
#include <string>
#include <cstdlib>
#include "../Queue.h"

void loadInitialShipments(Queue<std::string> &queue);
void start(Queue<std::string> &queue);
void showOrders(Queue<std::string> &queue);

int main() {
    Queue<std::string> shipmentsQueue;
    
    std::cout << "*** Order Manager Beta ***";
    std::cout << std::endl;
    
    std::cout << "Loading orders..." << std::endl;
    loadInitialShipments(shipmentsQueue);
    std::cout << "Orders loaded." << std::endl;
    std::cout << std::endl;
    
    start(shipmentsQueue);
    return 0;
}

void loadInitialShipments(Queue<std::string> &queue) {
    for (unsigned int i = 0; i < 10; i++) {
        std::string orderNumber = "A000" + std::to_string(i);
        std::cout << "Loading order no. " << orderNumber << std::endl;
        queue.enqueue(orderNumber);
    }
}

void start(Queue<std::string> &queue) {
    char c;
    
    std::cout << std::endl << "Ship order? (y/n): ";
    std::cin >> c;
    
    if (c == 'Y' || c == 'y') {
        std::string order = queue.dequeue();
        system("clear");
        std::cout << "Order dispatched: " << order << std::endl << std::endl;
        
        if (queue.count() > 0) {
            std::cout << "The next order is order no. " << queue.peek() << std::endl;
        } else {
            std::cout << "There are no orders left. Bye." << std::endl;
            return;
        }
        
        std::cout << "Orders left: " << std::endl;
        showOrders(queue);
        start(queue);
    } else {
        std::cout << "Thanks for using the Order Manager Beta." << std::endl;
    }
}

void showOrders(Queue<std::string> &queue) {
    
    for (int i = 0; i < queue.count(); i++) {
        std::string str = queue.dequeue();
        std::cout << str << "\t";
        queue.enqueue(str);
    }
    
    std::cout << std::endl;
}
