/*
 *  File Name: lab7Clock.cpp
 *  Assignment: Lab 7 Exercise C
 *  Lab section: 03
 *  Completed by: Samuel Laquerre
 *  Submission Date: October 24th,2023
 */


#include "lab7Clock.h"

//ALL CONSTRUCTORS
//Default ctor
Clock::Clock():hour(0),minute(0),second(0){

}

//seconds ctor
Clock::Clock(const int seconds){
    int good_sec = seconds;
    while(good_sec >= 86400){
        good_sec -= 86400;
    }
    if(seconds<0){
        hour=0;
        minute=0;
        second=0;
    }
    else{
        int* values = sec_to_hms(good_sec);
        hour = values[0];
        minute = values[1];
        second = values[2];
    }
}

//all values ctor
Clock::Clock(const int hours, const int minutes, const int seconds){
    if((seconds<0 || seconds>59)||(minutes<0 || minutes>59)||(hours<0 || hours>23)){
        hour=0;
        minute=0;
        second=0;
    }
    else{
        hour = hours;
        minute = minutes;
        second = seconds;
    }
}

//ALL SETTER FUNCTIONS
void Clock::set_hour(const int hours){
    if(hours<0 || hours>23){}
    else{
        hour = hours;
    }
}

void Clock::set_minute(const int minutes){
    if(minutes<0 || minutes>59){}
    else{
       minute = minutes; 
    }
}

void Clock::set_second(const int seconds){
    if(seconds<0 || seconds>59){}
    else{
      second = seconds;  
    }
}

//ALL GETTER FUNCTIONS
int Clock::get_hour() const{
    return hour;
}

int Clock::get_minute() const{
    return minute;
}

int Clock::get_second() const{
    return second;
}

//ALL HELPER FUNCTIONS
//Converts from clock values to seconds
int Clock::hms_to_sec(){
    int seconds = 0;
    seconds = (second)+(minute*60)+(hour*3600);
    return seconds;
}

//Sets the clock values
int* Clock::sec_to_hms(int n){
    int* hms = new int[3];
    hms[0] = n/3600;
    n -= hms[0]*3600;
    hms[1] = n/60;
    n -= hms[1]*60;
    hms[2] = n;
    return hms;
}

//ALL ADDITIONAL FUNCTIONS
//Increments 1 second to the clock
void Clock::increment(){
    if(second == 59){
        second = 0;
        if(minute == 59){
            minute = 0;
            if(hour == 23){
                hour = 0;
            }
            else{
                hour++;
            }
        }
        else{
            minute++;
        }
    }
    else{
        second++;
    }
}

//Decrements 1 second to the clock
void Clock::decrement(){
   if(second == 0){
        second = 59;
        if(minute == 0){
            minute = 59;
            if(hour == 0){
                hour = 23;
            }
            else{
                hour--;
            }
        }
        else{
            minute--;
        } 
   }
   else{
        second--;
   } 
}

//Adds a certain amount of seconds to the clock object
void Clock::add_seconds(int seconds){
    int* extra_time = sec_to_hms(seconds);
    second += extra_time[2];
    if(second > 59){
        minute++;
        second -= 60;
    }
    minute += extra_time[1];
    if(minute > 59){
        hour++;
        minute -= 60;
    }
    hour += extra_time[0];
    while(hour>23){
        hour -= 24;
    }
}