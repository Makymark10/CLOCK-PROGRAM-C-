
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

int main()
{
    time_t current_time = time(NULL);
    struct tm timeinfo;
    gmtime_s(&timeinfo, &current_time);
    cout << asctime(&timeinfo);


}