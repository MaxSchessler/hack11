/**
 * Author Max Schessler
 * Date 2024-11-15
 * 
 * This file holds my Airport Lib testing program.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "airport.h"

int main() {
    // Generate some airports on the heap 
    Airport *a1 = createAirport("A1", "International", "JFK", 40.6413, -73.7781, 13, "New York", "USA");
    Airport *a2 = createAirport("A2", "International", "LAX", 33.9416, -118.4085, 38, "Los Angeles", "USA");
    Airport *a3 = createAirport("A3", "International", "LHR", 51.4700, -0.4543, 25, "London", "UK");
    Airport *a4 = createAirport("A4", "International", "CDG", 49.0097, 2.5479, 118, "Paris", "France");
    Airport *a5 = createAirport("A5", "International", "SYD", -33.9461, 151.1772, 21, "Sydney", "Australia");

    Airport *stops = (Airport *) malloc (sizeof(Airport) * 5);
    stops[0] = *a1;
    stops[1] = *a2;
    stops[2] = *a3;
    stops[3] = *a4;
    stops[4] = *a5;


    int size = 5;
    double aveKmsPerHour = 800;
    double aveLayoverTimeHrs = 1;
    double time = getEstimatedTravelTime(stops, size, aveKmsPerHour, aveLayoverTimeHrs);
    printf("Estimated travel time: %f\n", time);

    return 0;
}