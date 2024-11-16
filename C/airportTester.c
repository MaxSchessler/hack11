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

    // testing createAirport
    Airport *a1 = createAirport("KATL", "large_airport", "Hartsfield-Jackson Atlanta International Airport", 33.6367, -84.4279, 1026, "Atlanta", "US");
    Airport *a2 = createAirport("KJFK", "large_airport", "John F Kennedy International Airport", 40.6398, -73.7789, 13, "New York", "US");
    Airport *a3 = createAirport("KORD", "large_airport", "Chicago O'Hare International Airport", 41.9786, -87.9048, 672, "Chicago", "US");

    freeAirport(a1);
    freeAirport(a2);
    freeAirport(a3);

    // testing initAirport
    a1 = (Airport *) malloc(sizeof(Airport));
    a2 = (Airport *) malloc(sizeof(Airport));
    a3 = (Airport *) malloc(sizeof(Airport));
    initAirport(a1, "KATL", "large_airport", "Hartsfield-Jackson Atlanta International Airport", 33.6367, -84.4279, 1026, "Atlanta", "US");
    initAirport(a2, "KJFK", "large_airport", "John F Kennedy International Airport", 40.6398, -73.7789, 13, "New York", "US");
    initAirport(a3, "KORD", "large_airport", "Chicago O'Hare International Airport", 41.9786, -87.9048, 672, "Chicago", "US");


    // testing airportToString
    char *a1Str = airportToString(a1);
    char *a2Str = airportToString(a2);
    char *a3Str = airportToString(a3);
    printf("%s\n", a1Str);
    printf("%s\n", a2Str);
    printf("%s\n", a3Str);

    free(a1Str);
    free(a2Str);
    free(a3Str);

    // testing getAirDistance
    double dist1 = getAirDistance(a1, a2);
    double dist2 = getAirDistance(a2, a3);
    double dist3 = getAirDistance(a1, a3);
    printf("Distance between KATL and KJFK: %f\n", dist1);
    printf("Distance between KJFK and KORD: %f\n", dist2);
    printf("Distance between KATL and KORD: %f\n", dist3);

    Airport *stops = (Airport *) malloc (sizeof(Airport) * 3);
    stops[0] = *a1;
    stops[1] = *a2;
    stops[2] = *a3;

    double estimate = getEstimatedTravelTime(stops, 3, 300, 1);
    printf("Estimate: getEstimatedTravelTime(stops, 3, 300, 1): %.2f\n", estimate);
    estimate = getEstimatedTravelTime(stops, 3, 300, 3);
    printf("Estimate: getEstimatedTravelTime(stops, 3, 300, 3): %.2f\n", estimate);
    estimate = getEstimatedTravelTime(stops, 3, 600, 1);
    printf("Estimate: getEstimatedTravelTime(stops, 3, 600, 1): %.2f\n", estimate);

    freeAirport(a1);
    freeAirport(a2);
    freeAirport(a3);
    free(stops);

    return 0;
}