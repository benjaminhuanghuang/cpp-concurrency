/**
 * Barron finishes cooking while Olivia cleans
 * 
 * When my main thread is finished executing and there aren't any 
 * non-daemon threads left running, this process can terminate.
 */
#include <thread>
#include <chrono>

void kitchen_cleaner() {
    while (true) {
        printf("Olivia cleaned the kitchen.\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::thread olivia(kitchen_cleaner);

    // olivia.detach();    // make the thread running in the background and non-joinable
    
    for (int i=0; i<3; i++) {
        printf("Barron is cooking...\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
    printf("Barron is done!\n");
    // olivia.join();    // this line make the kitchen_cleaner keep running
} 