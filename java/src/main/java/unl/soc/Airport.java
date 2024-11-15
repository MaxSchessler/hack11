/**
 * Author Max Schessler
 * Date 2024-11-12
 */

package unl.soc;

import java.util.List;

/**
 * The Airport class represents an airport with various attributes such as GPS ID, name, location, type, elevation, city, and country.
 * It provides methods to compute the air distance between two airports and to estimate travel time for a flight with multiple stops.
 * 
 * Attributes:
 * - gspId: The GPS ID of the airport.
 * - type: The type of the airport.
 * - name: The name of the airport.
 * - latitude: The latitude of the airport.
 * - longitude: The longitude of the airport.
 * - elevationFeet: The elevation of the airport in feet.
 * - city: The city where the airport is located.
 * - country: The country where the airport is located.
 * 
 */


public class Airport {

	public String gspId;
	public String type;
	public String name;
	public double latitude;
	public double longitude;
	public double elevationFeet;
	public String city;
	public String country;

	
	public Airport(String gpsId, String name, double latitude, double longitude, 
	String type, int elevationFeet,String city, String country) {
		
		this.gspId = gpsId;
		this.name = name;
		this.latitude = latitude;
		this.longitude = longitude;
		this.type = type;
		this.elevationFeet = elevationFeet;
		this.city = city;
		this.country = country;
	}

	/**
	 * Computes the air distance, in kilometers, from <code>this<code>
	 * airport to the given <code>destination</code> using their latitude/longitude
	 * and the
	 * <a href="https://en.wikipedia.org/wiki/Spherical_law_of_cosines">Spherical
	 * Law of Cosines</a>.
	 */
	public double getAirDistance(Airport destination) {
		double lat1 = this.latitude;
		double lon1 = this.longitude;
		double lat2 = destination.latitude;
		double lon2 = destination.longitude;
		final double RADIUS = 6371.01; // Earth's radius in kilometers

		if (lat1 < -90 || lat1 > 90) 
        {
            System.out.println("Origin Latitude value must be between -90 and 90 degrees.\n");
            return -1;
        }
        if (lon1 < -180 || lon1 > 180) 
        {
            System.out.println("Origin Longitude value must be between -180 and 180 degrees.\n");
            return -1;
        }
        if (lat2 < -90 || lat2 > 90) 
        {
            System.out.println("Destination Latitude value must be between -90 and 90 degrees.\n");
            return -1;
        }
        if (lon2 < -180 || lon2 > 180) 
        {
            System.out.println("Destination Longitude value must be between -180 and 180 degrees.\n");
            return -1;
		}

		// Convert degrees to radians
		lat1 = Math.toRadians(lat1);
		lon1 = Math.toRadians(lon1);
		lat2 = Math.toRadians(lat2);
		lon2 = Math.toRadians(lon2);
	
        // Return the airdistance using the Spherical Law of Cosines
        return Math.acos(( Math.sin(lat1) * Math.sin(lat2)) + (Math.cos(lat1) * Math.cos(lat2) * Math.cos(lon2-lon1))) * RADIUS;
	}

	/**
	 * Computes the estimated travel time (in hours) for a flight that involves the
	 * given stops using the average flight speed (kilometers per hour) and average
	 * layover time (in hours)
	 */
	public static double getEstimatedTravelTime(List<Airport> stops, double aveKmsPerHour, double aveLayoverTimeHrs) {
		double travelTime = aveLayoverTimeHrs;
    	double travelTimeFromLastStop;
    	double distance; 

		// Calculate the travel time between each stop
		for (int i = 0; i < stops.size() - 1; i++) {
			distance = stops.get(i).getAirDistance(stops.get(i + 1));
			travelTimeFromLastStop = distance / aveKmsPerHour;
			travelTime += travelTimeFromLastStop + aveLayoverTimeHrs;
		}

		return travelTime;
	}

	@Override
	public String toString() {
		return "Airport [gspId=" + gspId + ", type=" + type + ", name=" + name + ", latitude=" + latitude + ", longitude="
				+ longitude + ", elevationFeet=" + elevationFeet + ", city=" + city + ", country=" + country + "]";
	}

}
