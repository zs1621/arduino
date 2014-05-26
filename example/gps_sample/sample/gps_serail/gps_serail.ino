/********************* start of gps_serial.ino *************************/

/*
 *	created:	2013-08-02
 *	by:		lisper (leyapin@gmail.com)
 *	Version:	0.1
 *	test gps gsm on Leonardo &XBEE R3
 *
 */

//#ifndef DEBUG
#define DEBUG
//#endif



#include <SoftwareSerial.h>
SoftwareSerial Serial1(10, 11); // RX, TX

#include "gpsGsmSim908.h"

//
void setup () {
	gps_init ();	//init GPS pin

	Serial.begin (9600);	//serial0 connect computer
//	while (!Serial);

	Serial1.begin (9600);	//serial1 connect GPS
//	while (!Serial1);

	Serial.println ("start GPS! hehe");

//	start_gps ();	//open GPS
}

//
void loop () {
	//int stat = gps_get_gga ();	// read data from GPS, return 0 is ok

	
//	switch (stat) {
//	case 0:
//		Serial.println ("data checksum is ok");
//		break;
//	case 1:
//		Serial.println ("error! data checksum is fail");
//		break;
//	case 2:
//		Serial.println ("GPGGA ID is error!");
//		break;
//	case 3:
//		Serial.println ("data is error!");
//	}

//	Serial.println ("$GPGGA data:");
//	gps_gga_print ();	//for test
        char latitude[15];
        char longtitude[15];
        char url[50];
        memset(url, '\0', sizeof(url));
        memset(latitude, '\0', sizeof(latitude));
        memset(longtitude, '\0', sizeof(longtitude));
        strcpy(latitude, "42.121");
        strcpy(longtitude, "121.78");
        init_http_request ();
        strcpy(url, "htttp://aqimap.com/test?");        
        set_gprs_url(contact_url(url, longtitude, latitude));
//        gsm_end_send ();
//	if (gps_gga_is_fix () == 0) {	//if fix return 1            
//		Serial.println ("can't fix! please go outside!");
//                delay(1000); 
//        } else if ( gps_gga_is_fix () ) {
//                Serial.println ("ok! is fix!");
//        	Serial.println (gps_gga_lat_s ());
//                Serial.println (gps_gga_long_s ());
////                char latitude[15];
////                char longtitude[15];
////                char request_url[100];
//                char url[50] = "http://aqimap.com/test?";
////                memcpy(latitude, gps_gga_lat_s(), strlen(gps_gga_lat_s()));
////                memcpy(longtitude, gps_gga_long_s(), strlen(gps_gga_long_s()));
////                memcpy(request_url, contact_url(url, longtitude, latitude), strlen(contact_url(url, longtitude, latitude)));
//                init_http_request ();
//                set_gprs_url(contact_url(url, gps_gga_long_s(), gps_gga_lat_s()));
//                gsm_end_send ();
////                start_gps();
//        }         
	Serial.println ();
}

/********************* end of gps_serial.ino *************************/
