#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <ctime>
#include <conio.h>

using namespace std;

void clockTimer(int Hours, int Minutes, int Seconds) {
    char timesUp;
    while(true) {
    cout << "\r"<< Hours << "Hours, " << Minutes << "Minutes, " << Seconds << "Seconds";
    cout << " (Press \'Q\' to Exit)";
    cout.flush();

    Seconds--;
    if (Seconds == 0) {
        Seconds = 60;
        Minutes--;
        if (Minutes == 0) {
            Minutes == 60;
            Hours--;
        }
    }

    if (kbhit()) {
        char key = getch();
        if (key == 'Q') {
           goto timesUp;
        }
    }

    this_thread::sleep_for(1s);
    }
    timesUp:
    cout << "\n\nEXIT!!\n\n";
}

void clockClock() {
    char exiT;
    while (true) {
        auto now = chrono::system_clock::now();
        std::time_t now_c = chrono::system_clock::to_time_t(now);
        struct tm *parts = localtime(&now_c);
        cout << "\r" << put_time(parts, "%b/%a/%Y ");
        cout << put_time(parts, "Hours:%I Minutes:%M Seconds:%S") <<" (Press \'Q\' to Exit)";
        cout.flush();

        if (kbhit()) {
            char key = getch();
            if (key == 'Q') {
                goto exiT;
                }
            }

        this_thread::sleep_for(1s);
    }
    exiT:
    cout << "\n\nEXIT!!\n\n";
}

void stopWatch() {
        char exitGoto;
        int stopHours = 0;
        int stopMinutes = 0;
        int stopSeconds = 0;
        while (true) {

        cout << "\r"<< stopHours << "Hours, " << stopMinutes << "Minutes, " << stopSeconds << "Seconds";
        cout << " ( Press \'L\' to Lap or press \'Q\' to Exit)";
        cout.flush();

        stopSeconds++;
        if (stopSeconds == 60) {
        stopSeconds = 0;
        stopMinutes++;
            if (stopMinutes == 60) {
                stopMinutes = 0;
                stopHours++;
                }
            }

        if (kbhit()) {
            char key = getch();
            if (key == 'L' || key == 'l') {
                cout << "\n";
            } else if (key == 'Q' || key == 'q') {
                goto exitGoto;
            }
        }

        this_thread::sleep_for(1s);
    }

    exitGoto:
    cout << "\n\nEXIT!!\n\n";
}

int main()
{

    int choices, choiceGoto;
    choiceGoto:
    cout << "\nWelcome to CLock\n\n";

    cout << "Choose what you want: \n";
    cout << "(0)Timer\n";
    cout << "(1)Clock\n";
    cout << "(2)StopWatch\n";
    cout << "(3)Exit\n";

    cout << "\nType Here: ";
    cin >> choices;

    if (choices == 0 ) {
        int hr, mins, secs;
        cout << "Enter Hours: ";
        cin >> hr;
        cout << "Enter Minutes: ";
        cin >> mins;
        cout << "Enter Seconds: ";
        cin >> secs;
        cout << "\n\n";

        clockTimer(hr, mins, secs);
        goto choiceGoto;
    } else if (choices == 1) {
        clockClock();
        goto choiceGoto;
    } else if (choices == 2) {
        stopWatch();
        goto choiceGoto;
    } else if (choices == 3) {
        cout << "\n\n Than You!!";
    } else {
        cout << "Invalid Inpu\n\n";
        goto choiceGoto;
    }




    return 0;
}
