#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;


int main() {
        auto now = std::chrono::system_clock::now();

        std::cout << "printTime() millis since Unix Epoch (00:00:00 UTC on 1 January 1970) " << now.time_since_epoch().count() << endl;

        auto stime = std::chrono::system_clock::to_time_t(now);

        // pass the address of stime to the localtime function ???
        auto ltime = std::localtime(&stime);

        std::this_thread::sleep_for(std::chrono::milliseconds(4000));

        std::cout << "printTime() local time = " << std::put_time(ltime, "%c") << endl;
    return 0;
}