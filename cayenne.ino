#include <CayenneMQTTSerial.h>

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "fbd361d0-f659-11ed-9ab8-d511caccfe8c";
char password[] = "c1196fac992c5336cec20bee3931d92fb56b9889";
char clientID[] = "48065d20-fab3-11ed-9ab8-d511caccfe8c";

void setup()
{
	//Baud rate can be specified by calling Cayenne.begin(username, password, clientID, 9600);
	Cayenne.begin(username, password, clientID);
}

void loop() {
	Cayenne.loop();
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
	// Write data to Cayenne here. This example just sends the current uptime in milliseconds on virtual channel 0.
	Cayenne.virtualWrite(0, millis());
	// Some examples of other functions you can use to send data.
	//Cayenne.celsiusWrite(1, 22.0);
	//Cayenne.luxWrite(2, 700);
	//Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
