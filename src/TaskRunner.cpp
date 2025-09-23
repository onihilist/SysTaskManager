//
// Created by onihilist on 23/09/2025.
//

#include <iostream>
#include <thread>

void run(std::thread t) {
    t.join();
    std::cout << "Thread " << t.get_id() << " is running..." << std::endl;
    t.detach();
};