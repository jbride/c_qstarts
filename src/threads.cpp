#include <iostream>
#include <chrono>
#include <iomanip>
#include <thread>
#include <random>

using namespace std;

inline void printTime(int loops, int delayMillis) {

    for(int x = 0; x<loops; x++){
        auto now = std::chrono::system_clock::now();

        std::cout << std::this_thread::get_id() << "\t" << x << "\t: printTime() millis since Unix Epoch (00:00:00 UTC on 1 January 1970) " << now.time_since_epoch().count() << endl;

        auto stime = std::chrono::system_clock::to_time_t(now);

        // pass the address of stime to the localtime function ???
        //auto ltime = std::localtime(&stime);

        //std::cout << std::this_thread::get_id() << " : printTime() local time = " << std::put_time(ltime, "%c") << endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
    }
}

void printString(int loops, int delayMillis, string stringArg) {

    for(int x = 0; x<loops; x++){
        std::cout << std::this_thread::get_id() << "\t" << x << "\t: printString() " << stringArg << endl;
        std::mt19937_64 eng{std::random_device{}()};  // or seed however you want
        std::uniform_int_distribution<> dist{0, delayMillis};
        std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});
    }

}

int main() {
    std:: cout << std::this_thread::get_id() << "\t\t : starting" << endl << endl;
    std::thread tTime(printTime, 20, 500);
    // detch() :  thread will continue its execution until it finishes w/out being managed by the std::thread object, which will no longer own any thread
    // NOTE:  this thread will get automatically killed if not completed by the time the main thread terminates
    tTime.detach();

    std::thread tString(printString, 10, 200, "azra");
    // join() : block main thread until tString thread is finished
    tString.join();

    std::cout << std::this_thread::get_id() << " : main() about to sleep" << endl;
    std::chrono::seconds sleepTime = 2s;
    std::this_thread::sleep_for(sleepTime);

    return 0;
}
