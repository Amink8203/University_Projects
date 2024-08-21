#ifndef _TRIP_HPP
#define _TRIP_HPP

class Trip
{
private:
    int driver_id;
    int start_trip;
    int end_trip;
    int distance;

public:
    Trip(int id, int start, int end, int dis);
    int get_start_trip();
    int get_end_trip();
    int get_distance();
    int get_driver_id();
};

#endif