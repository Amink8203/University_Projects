#include "Trip.hpp"

Trip::Trip(int id, int start, int end, int dis) 
: driver_id(id), start_trip(start), end_trip(end), distance(dis) {};

int Trip::get_start_trip() { return start_trip; };
int Trip::get_end_trip() { return end_trip; };
int Trip::get_distance() { return distance; };
int Trip::get_driver_id() { return driver_id; };