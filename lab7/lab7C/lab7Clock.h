#ifndef CLOCK
#define CLOCK
class Clock{
    public:
        Clock();
        Clock(const int seconds);
        Clock(const int hours, const int minutes, const int seconds);
        void set_hour(const int hours);
        void set_minute(const int minutes);
        void set_second(const int seconds);
        int get_hour() const;
        int get_minute() const;
        int get_second() const;
        void increment();
        void decrement();
        void add_seconds(int seconds);
    private:
        int hour, minute, second;
        int hms_to_sec();
        int* sec_to_hms(int n);
        
};



#endif