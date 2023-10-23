#include "lab7Clock.h"
//ALL CONSTRUCTORS
//Default ctor
Clock::Clock():hour(0),minute(0),second(0){

}

//seconds ctor
Clock::Clock(const int seconds){
    if(seconds<0){
        hour=0;
        minute=0;
        second=0;
    }
    else{
        sec_to_hms(seconds);
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
    hour = hours;
}

void Clock::set_minute(const int minutes){
    minute = minutes;
}

void Clock::set_second(const int seconds){
    second = seconds;
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
void Clock::sec_to_hms(int n){
    hour = n/3600;
    n -= hour*3600;
    minute = n/60;
    n -= minute*60;
    second = n;
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
   if(hour == 0){
        hour = 23;
        if(minute == 0){
            minute = 59;
            if(second == 0){
                second = 59;
            }
            else{
                second--;
            }
        }
        else{
            minute--;
        } 
   }
   else{
        hour--;
   } 
}

void Clock::add_seconds(int seconds){
    
}