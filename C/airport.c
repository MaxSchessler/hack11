/**
 * Author Max Schessler
 * Date 2024-11-15
 * 
 * This file holds my Airport Lib Functions.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "airport.h"

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv) {

    if (gpsId == NULL) {
        fprintf(stderr, "ERROR invalid input (gpsID)\n");
        return NULL;
    }

    if (type == NULL) {
        fprintf(stderr, "ERROR invalid input (type) \n");
        return NULL;
    }

    if (name == NULL) {
        fprintf(stderr, "ERROR invalid input (name) \n");
        return NULL;
    }

    if (city == NULL) {
        fprintf(stderr, "ERROR invalid input (city) \n");
        return NULL;
    }

    if (countryAbbrv == NULL) {
        fprintf(stderr, "ERROR invalid input (countryAbbrv) \n");
        return NULL;
    }

    // validate latitude and longitude 
    if (latitude < -90 || latitude > 90) 
    {
        printf("Latitude value must be between -90 and 90 degrees.\n");
        return NULL;
    }
    if (longitude < -180 || longitude > 180) 
    {
        printf("Longitude value must be between -180 and 180 degrees.\n");
        return NULL;
    }

    Airport *airport = (Airport *) malloc(sizeof(Airport));

    initAirport(airport, gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv);

    return airport;
}


void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv)
{
    if (airport == NULL) {
        fprintf(stderr, "ERROR invalid input (airport) \n");
        return;
    }

    if (gpsId == NULL) {
        fprintf(stderr, "ERROR invalid input (gpsID)\n");
        return;
    }

    if (type == NULL) {
        fprintf(stderr, "ERROR invalid input (type) \n");
        return;
    }

    if (name == NULL) {
        fprintf(stderr, "ERROR invalid input (name) \n");
        return;
    }

    if (city == NULL) {
        fprintf(stderr, "ERROR invalid input (city) \n");
        return;
    }

    if (countryAbbrv == NULL) {
        fprintf(stderr, "ERROR invalid input (countryAbbrv) \n");
        return;
    }

    // validate latitude and longitude 
    if (latitude < -90 || latitude > 90) 
    {
        printf("Latitude value must be between -90 and 90 degrees.\n");
        return;
    }
    if (longitude < -180 || longitude > 180) 
    {
        printf("Longitude value must be between -180 and 180 degrees.\n");
        return;
    }

    airport->gpsId = (char *) malloc(sizeof(char *) * strlen(gpsId));
    strcpy(airport->gpsId, gpsId);

    airport->type = (char *) malloc(sizeof(char *) * strlen(type));
    strcpy(airport->type, type);

    airport->name = (char *) malloc(sizeof(char *) * strlen(name));
    strcpy(airport->name, name);

    airport->city = (char *) malloc(sizeof(char *) * strlen(city));
    strcpy(airport->city, city);

    airport->countryAbbrv = (char *) malloc(sizeof(char *) * strlen(countryAbbrv));
    strcpy(airport->countryAbbrv, countryAbbrv);

    airport->latitude = latitude;
    airport->longitude = longitude;
    airport->elevationFeet = elevationFeet;
}


char* airportToString(const Airport* a) {
    if (a == NULL) {
        fprintf(stderr, "ERROR invalid input\n");
        return NULL;
    }

    const int bufflen = 256;

    char* result = (char*) malloc(bufflen * sizeof(char));
    snprintf(
        result,
        bufflen,
        "%s %s %s %.2f %.2f %d %s %s",
        a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv
    );
    
    return result;
}

double getEstimatedTravelTime(const Airport* stops, int size, double aveKmsPerHour, double aveLayoverTimeHrs)
{
    // Data validation 
    if (size <= 0) {
        fprintf(stderr, "ERROR: Invalid size\n");
        return -1;
    }
    if (stops == NULL) {
        fprintf(stderr, "ERROR: Stops array is NULL\n");
        return -1;
    }
    if (aveKmsPerHour <= 0) {
        fprintf(stderr, "ERROR: Invalid average speed (must be > 0)\n");
        return -1;
    }
    if (aveLayoverTimeHrs < 0) {
        fprintf(stderr, "ERROR: Invalid layover time (must be >= 0)\n");
        return -1;
    }

   
    double travelTime = 0;
    double airDistance;
    // iterate from first to second to last stop has no layover time
    for (int i = 0; i < size - 1; i++) {
        // get air distance form current stop to next stop, if error return -1
        airDistance = getAirDistance(&stops[i], &stops[i + 1]);
        if (airDistance < 0) {
            return -1;
        }
        // compute the travel time by dividing distance / speed 
        travelTime += airDistance / aveKmsPerHour;
        // if the current stop is not the second to last stop add the layover time
        // second to last because the last stop is the destination and not included in the loop
        if (i < size - 2) {
            travelTime += aveLayoverTimeHrs;
        }
    }

    return travelTime;
}

double degreesToRadians(double degree) {
    return degree * M_PI / 180;
}


double getAirDistance(const Airport* origin, const Airport* destination)
{
    if (origin == NULL || destination == NULL) {
        fprintf(stderr, "ERROR, invalid inputs\n");
        return -1;
    }
    
    double lat1 = origin->latitude;
    double lon1 = origin->longitude;
    double lat2 = destination->latitude;
    double lon2 = destination->longitude;

    if (lat1 < -90 || lat1 > 90) 
    {
        printf("Origin Latitude value must be between -90 and 90 degrees.\n");
        return -1;
    }
    if (lon1 < -180 || lon1 > 180) 
    {
        printf("Origin Longitude value must be between -180 and 180 degrees.\n");
        return -1;
    }
    if (lat2 < -90 || lat2 > 90) 
    {
        printf("Destination Latitude value must be between -90 and 90 degrees.\n");
        return -1;
    }
    if (lon2 < -180 || lon2 > 180) 
    {
        printf("Destination Longitude value must be between -180 and 180 degrees.\n");
        return -1;
    }

    // Convert degrees to radians
    lat1 = degreesToRadians(lat1);
    lon1 = degreesToRadians(lon1);
    lat2 = degreesToRadians(lat2);
    lon2 = degreesToRadians(lon2);

    // calculate the distance using the haversine formula
    const double RADIUS = 6371;
    return acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon1-lon2)) * RADIUS;
}

void freeAirport(Airport *airport) {
    if (airport != NULL) {
        free(airport->gpsId);
        free(airport->type);
        free(airport->name);
        free(airport->city);
        free(airport->countryAbbrv);
        free(airport);
    }
}