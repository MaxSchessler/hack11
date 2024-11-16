/**
 * Author Max Schessler
 * Date 2024-11-12
 */


package unl.soc;

import java.util.Arrays;
import java.util.List;

public class AirportTester {
    public static void main(String[] args) {

        //Testing constructors - will use these objects for more testing
        Airport a1 = new Airport("KATL", "large_airport", "Hartsfield-Jackson Atlanta International Airport",
        33.6367, -84.4279, 1026, "Atlanta", "US");

        Airport a2 = new Airport("KJFK", "large_airport", "John F Kennedy International Airport",
                40.6398, -73.7789, 13, "New York", "US");

        Airport a3 = new Airport("KORD", "large_airport", "Chicago O'Hare International Airport",
                41.9786, -87.9048, 672, "Chicago", "US");

        List<Airport> stops = Arrays.asList(a1, a2, a3);

        //Testing toString method
        System.out.println("\nMy Airports: ");
        System.out.println(a1.toString());
        System.out.println(a2.toString());
        System.out.println(a3.toString());

        //Testing getAirDistance method
        System.out.println("\nAir Distances: ");
        System.out.printf("Air Distance from %s to %s: %f\n", a1.name, a2.name, a1.getAirDistance(a2));
        System.out.printf("Air Distance from %s to %s: %f\n", a1.name, a3.name, a1.getAirDistance(a3));
        System.out.printf("Air Distance from %s to %s: %f\n", a2.name, a3.name, a2.getAirDistance(a3));

        //Testing getTravelTime method
        System.out.println("\nTravel Times: ");
        double travelTime = Airport.getEstimatedTravelTime(stops, 500, 1);
        System.out.printf("Estimated Travel Time for flight with 500 kmp and 3 stops of 1 hour: %.2f hours\n", travelTime);
        travelTime = Airport.getEstimatedTravelTime(stops, 500, 2);
        System.out.printf("Estimated Travel Time for flight with 500 kmp and 3 stops of 2 hour: %.2f hours\n", travelTime);
        travelTime = Airport.getEstimatedTravelTime(stops, 1000, 1);
        System.out.printf("Estimated Travel Time for flight with 1000 kmp and 3 stops of 1 hour: %.2f hours\n", travelTime);

    }
}