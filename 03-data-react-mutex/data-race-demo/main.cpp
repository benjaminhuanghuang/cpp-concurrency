/**
 * Two shoppers adding items to a shared notepad
 */

#include <thread>
#include <mutex>

unsigned int garlic_count = 0;
std::mutex pencil;


void shopper() {
    pencil.lock();
    for (int i=0; i<10000000; i++) {
        garlic_count++;
    }
    pencil.unlock();
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();

    // Note!, the garlic_count is not 20000000 without mutex
    printf("We should buy %u garlic.\n", garlic_count);
}