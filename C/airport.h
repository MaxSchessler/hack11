/**
 * Author Max Schessler
 * Date 2024-11-15
 * 
 * This file holds my Airport Lib Functions.
 */
typedef struct {
  char *gpsId;
  char *type;
  char *name;
  double latitude; 
  double longitude;
  int elevationFeet;
  char *city;
  char *countryAbbrv;
} Airport;

/**
 * A factory function to create a new Airport with the given
 * attributes.  This function should make *deep* copies of each
 * of the relevant fields and return a pointer to the newly
 * created Airport structure.
 */
Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv);

/**
 * This function initializes an existing allocated
 * Airport structure with the given attributes. This
 * function should make *deep* copies of each of the
 * relevant fields.
 */
void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv);

/**
 * Constructs a new string representation of the given
 * Airport structure.
 */
char* airportToString(const Airport* a);

/**
 * Computes the air distance, in kilometers, between
 * the two Airports using their latitude/longitude
 */
double getAirDistance(const Airport* origin, const Airport* destination);

/**
 * Computes the estimated travel time (in hours) for a flight
 * that involves the given stops (an array of Airport structures
 * of the given size) using the average flight speed
 * (kilometers per hour).  Thus there are size - 1 "legs" of the
 * trip.
 *
 * The first stop is the origin and the last stop is the destination.
 * Each stop in between is a layover each incurring a wait time
 * of aveLayoverTimeHrs
 */
double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs);


/**
 * This function computes the great-circle distance between the origin and 
 * destination airports using their geographical coordinates (latitude and longitude).
 *
 * @param origin Pointer to the Airport structure representing the origin airport.
 * @param destination Pointer to the Airport structure representing the destination airport.
 * @return The air distance between the two airports in kilometers.
 */
double getAirDistance(const Airport* origin, const Airport* destination);

/**
 * Frees the memory allocated for the given Airport structure.
 *
 * @param airport A pointer to the Airport structure to be freed.
 */
void freeAirport(Airport *airport);

/**
 * This function takes an angle in degrees and converts it to radians.
 *
 * @param degree The angle in degrees to be converted.
 * @return The angle in radians.
 */
double degreesToRadians(double degree);