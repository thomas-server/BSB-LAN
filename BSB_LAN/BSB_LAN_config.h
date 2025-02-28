/************************************************************************************/
/************************************************************************************/
/* Settings -   BEGIN                                                               */
/************************************************************************************/
/************************************************************************************/

// Upon first installation, rename this file from BSB_lan_config.h.default to BSB_lan_config.h and adjust settings accordingly
// Users who still use Arduino Mega2560 boards instead of Arduin Due: Please have a look at the very end of this configuration
// where certain modules are disabled by default due to limited flash memory.


/* Select language; so far German is the most complete, with English following.
 * Available languages are: Czech (CS), German (DE), Danish (DA), English (EN), Spanish (ES), Finnish (FI),
 * French (FR), Greek (EL), Hungarian (HU), Italian (IT), Dutch (NL), Polish (PL), Russian (RU), Swedish (SV),
 * Slovenian (SI) and Turkish (TR).
 * Incomplete languages will automatically be filled up with English translations first, and if no English translation
 * is available, fallback will take place to German.
*/
#define LANG EN

/*
Allow to initialize program configuration by reading settings from EEPROM
byte UseEEPROM = 0; // Configuration is read from this config file.
                    // Configuration can be stored in EEPROM but will not used while UseEEPROM is zero.
                    // Set zero for fallback startup in case EEPROM configuration is broken.
byte UseEEPROM = 1; // Configuration will be read from EEPROM. This is the default.
*/
byte UseEEPROM = 0;

/*
 *  Enter a MAC address, found either on the EthernetShield or use the one below.
 *  Change this if you have more than one BSB-LAN adapter in your LAN, so that there aren't any address conflicts.
 *  MAC address here only affects the LAN shield, it doesn't apply to the WiFi-ESP-solution.
*/
byte mac[6] = { 0x00, 0x80, 0x41, 0x19, 0x69, 0x90 };

/*
 * Initialize the Ethernet server library
 * with the IP address and port you want to use
 * (port 80 is default for HTTP):
*/

uint16_t HTTPPort = 80;
bool useDHCP = true;                 // Set to false if you want to use a fixed IP.
byte ip_addr[4] = {192,168,178,88};     // Please note the commas instead of dots!!!  Set useDHCP to true if you want DHCP.
byte gateway_addr[4] = {192,168,178,1}; // Gateway address. This is usually your router's IP address. Please note the commas instead of dots!!! Ignored if first value is 0.
byte dns_addr[4] = {192,168,178,1};     // DNS server. Please note the commas instead of dots!!! Ignored if first value is 0.
byte subnet_addr[4] = {255,255,255,0};  // Subnet address. Please use commas instead of dots!!! Ignored if first value is 0.

//#define WIFI                          // Activate this definement if you want to use WiFi. WiFi will not work if you do not remove the leading // ! Note: MAC address can't be set individually.
char wifi_ssid[32] = "SFR_B260"; // enter your WiFi network name (SSID) here
char wifi_pass[64] = "scorpion";// enter your WiFi password here
uint8_t bssid[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};  // enter specific BSSID address here to ensure connecting to a specific router. Leave all zeros in normal circumstances.
#define WIFI_SPI_SS_PIN 12              // defines SPI-SS pin for Arduino-ESP8266 connection

#define MDNS_SUPPORT                   // Advertises the hostname in the local network. Disable this if you don't want your device to be found under this name in your network.
char mDNS_hostname[32] = "BSB-LAN";

#define DEBUG         // Compile with verbose DEBUG module if defined
byte debug_mode = 1;  // Debug mode: 0 - disabled, 1 - send debug messages to serial interface, 2 - send debug messages to telnet client
byte verbose = 1;     // If set to 1, all messages on the bus are printed to debug interface
byte monitor = 0;     // Bus monitor mode. This is only necessary for in-depth debug sessions.
bool show_unknown = true; // true - show all parameters, false - hide unknown parameters from web display (parameters will still be queried and therefore take time!)
//#define DEVELOPER_DEBUG //Very verbose debug output. This option will dramatically slow down MCU performance. Useful for developers not for users.

/* SECURITY OPTIONS
 * There are several options to control and protect access to your heating system. However, keep
 * in mind, that even activating all three options are no guarantee that a versatile intruder with
 * access to your (W)LAN won't be able to gain access. In any case, no encryption of data streams
 * is provided from the Arduino itself. Use VPN or a SSL proxy if that is a must for you and connect
 * the Arduino wired to the VPN server or SSL proxy. On the other hand, someone with this amount
 * of criminal activity will probably have it easier just to access your heating system face-to-face ;)
*/

/*
 * if PASSKEY length is non-zero, the URL has to contain the defined passkey as first element
 * e.g.
 * char PASSKEY[64] = "1234";
 * http://192.168.178.88/1234/                - to view the main website (don't forget the trailing slash!)
 * http://192.168.178.88/1234/K               - to list all categories
 * http://192.168.178.88/1234/8700/8740/8741  - to list parameters 8700, 8740 and 8741 in one request
*/
char PASSKEY[64] = "";

/* activate IP-address-based access.
You can set any ip address as trusted.
Not used if first byte is 0
*/
byte trusted_ip_addr[4] = {0,0,0,0};
byte trusted_ip_addr2[4] = {0,0,0,0};

/* Activate HTTP-Auth authentication to provide username/password based access. No encryption!
 * Credentials have to be entered in the form
 * User:Password
 */
//char USER_PASS[64] = "User:Password";
char USER_PASS[64] = "";      // HTTP-Auth will be disabled if USER_PASS string length is zero


// Compile module with one wire bus support.
#define ONE_WIRE_BUS
byte One_Wire_Pin = 0;         // Define the pin for one wire temperature sensors. 0 - disable oneWire bus

// Compile module with DHT temperature/humidity sensors support
#define DHT_BUS
// Define the pins for DHT temperature/humidity sensors (Up to 10)
uint8_t DHT_Pins[10] = {0};

// Compile module with BME280 temperature/humidity/pressure sensors support on I2C bus.
// Up to two sensors with 0x76 and 0x77 addresses.
#define BME280
byte BME_Sensors = 0; //Define number of BME280 sensors

// Compile module for calculation 24h averages for selected programs
#define AVERAGES
// Create 24h averages from these parameters and save data into averages.txt on SD-card.
parameter avg_parameters[40] = {
// parameter, destination (as in dest_address below, -1 means "default (dest_address) address")
  {8700, -1},                         // Außentemperatur
  {8326, -1}                          // Brenner-Modulation
};

/* Compile module for logging.
File logging requires a FAT32 formatted micro SD card inserted into the Ethernet shield's card slot.
Does: log bus telegrams to file
      log selected values to file
      store to SD and load selected 24h averages
      send selected values as UDP broadcast
      push selected values to an MQTT broker*/
#define LOGGER

#define UDP_LOG_PORT 6502 // fixed here, not configurable via web interface

// Use SD card adapter on ESP32-based boards instead of internal flash-based storage
//#define ESP32_USE_SD

// Log "raw" bus telegrams. Data saved in journal.txt on SD-card.
// Telegrams logged upon boot:
// int logTelegram = LOGTELEGRAM_OFF; // nothing to log,
// int logTelegram = LOGTELEGRAM_ON;  // log all telegrams,
// int logTelegram = LOGTELEGRAM_ON + LOGTELEGRAM_UNKNOWN_ONLY;           // log unknown telegrams,
// int logTelegram = LOGTELEGRAM_ON + LOGTELEGRAM_BROADCAST_ONLY;         // log broadcast telegrams,
// int logTelegram = LOGTELEGRAM_ON + LOGTELEGRAM_UNKNOWNBROADCAST_ONLY;  // log unknown broadcast telegrams only;
int logTelegram = LOGTELEGRAM_OFF;

// Logging data from parameters
// Interval and list of parameters can be redefined through /L command during runtime
// Data will be written to "datalog.txt"
unsigned long log_interval = 3600;  // Logging interval (to SD card, UDP and MQTT broker) in seconds
parameter log_parameters[40] = {
// parameter, destination (as in dest_address below, -1 means "default (dest_address) address")
  {8700, -1},                   // Außentemperatur
  {8743, -1},                  // Vorlauftemperatur
  {8314, -1},                  // Rücklauftemperatur
//  {20000, -1},                 // Spezialparameter: Brenner-Laufzeit Stufe 1
//  {20001, -1},                 // Spezialparameter: Brenner-Takte Stufe 1
//  {20002, -1},                 // Spezialparameter: Brenner-Laufzeit Stufe 2
//  {20003, -1},                 // Spezialparameter: Brenner-Takte Stufe 2
//  {20004, -1},                 // Spezialparameter: TWW-Laufzeit
//  {20005, -1},                 // Spezialparameter: TWW-Takte
//  {20050, -1},                 // Spezialparameter 20050-20099: 24h-Durchschnittswerte
//  {20100, -1},                 // Spezialparameter 20100-20299: DHT22-Sensoren 1-50
//  {20300, -1},                 // Spezialparameter 20300-20499: DS18B20-Sensoren 1-100
//  {20500, -1}                  // Spezialparameter 20500-20699: MAX!-Sensoren 1-50
};

// Compile MQTT extension: activate sending log_parameters to MQTT broker every log_interval seconds
#define MQTT
byte mqtt_mode = 1; // MQTT: 1 - send messages in plain text format, 2 - send messages in JSON format, 3 - send messages in rich JSON format. Use this if you want a json package of your logging information printed to the mqtt topic
// JSON payload will be of the structure: {"MQTTDeviceID": {"status":{"log_param1":"value1"}}}
// rich JSON payload will be of the structure: {"MQTTDeviceID": {"id": "parmeter number from log values", "name": "parameter name from logvalues", "value": "query result", "desc": "enum value description", "unit": "unit of measurement", "error", error code}}
byte mqtt_broker_ip_addr[4] = {192,168,178,20}; // MQTT broker ip address. Please use commas instead of dots!!!
char MQTTUsername[65] = "User";                 // Set username for MQTT broker here or set empty string if no username/password is used.
char MQTTPassword[65] = "Pass";                 // Set password for MQTT broker here or set empty string if no password is used.
char MQTTTopicPrefix[65] = "BSB-LAN"; 	        // Optional: Choose the "topic" for MQTT messages here. In case of empty string, default topic name will be used

// Optional: Define a device name to use as header in json payload. In case of empty string, "BSB-LAN" will be used.
// This value is also used as a client ID towards the MQTT broker, change it if you have more than one BSB-LAN on your broker.
char MQTTDeviceID[32] = "BSB-LAN";

// Logging mode: 0 - disabled, 1 - write values to SD card, 2 - write 24h averages to SD card, 4 - send values to MQTT, 8 -  send values to UDP. Can be any sum of these values.
byte LoggingMode = 0; //CF_LOGMODE_SD_CARD | CF_LOGMODE_24AVG | CF_LOGMODE_MQTT | CF_LOGMODE_UDP


// Compile IPWE extension
#define IPWE
bool enable_ipwe = false;  // true - activate IPWE extension (http://xxx.xxx.xxx.xxx/ipwe.cgi)
// Parameters to be displayed in IPWE extension
parameter ipwe_parameters[40] = {
// parameter, destination (as in dest_address below, -1 means "default (dest_address) address")
  {8700, -1},                  // Außentemperatur
  {8743, -1},                  // Vorlauftemperatur
  {8314, -1},                  // Rücklauftemperatur
//  {8750, -1},                  // Gebläsedrehzahl
//  {8830, -1},                  // Warmwassertemperatur
//  {8740, -1},                  // Raumtemperatur Ist
//  {8741, -1},                  // Raumtemperatur Soll
//  {8326, -1},                  // Brenner-Modulation
//  {8337, -1},                  // Startzähler Brenner
//  {8703, -1},                  // Aussentemperatur gedämpft
//  {8704, -1}                   // Aussentemperatur gemischt
};

// If you prefer to use the log file plotting (/DG) used in BSB-LAN 2.1.3, disable the following #define.
// Otherwise a newer implementation will be used that does require (automated) loading of an additional
// Javascript library off the internet (currently 204 KB), but offers the following improvements:
// - better legibility for value numbers with plot lines close to each other (mouseover on plot)
// - user can interactively highlight plot lines for improved overview (mouseover on legend entries)
// - user can interactively disable plot lines for improved overview and vertical scaling (click on legend entries)
// - added zoom (mousewheel/pinch on plot) and pan capability (drag zoomed-in plot)
// - selective plotting of data from big logs
#define USE_ADVANCED_PLOT_LOG_FILE
#define DEFAULT_DAYS_TO_PLOT "3" // must be a positive integer value in double quotes!
// Log file plotting uses two JavaScript libraries, which are usually loaded from the web.
// Should you prefer to use local copies instead, put the files from the data subdirectory onto your
// bsb-lan unit's SD card (*), and provide their path names here. For browsers that support gzip
// compression (what browser doesn't?), it is sufficient to copy the *.gz file versions to your
// bsb-lan unit, but omit the ".gz" from the path names you put into the following lines!
// (*) In case you're using an ESP32's internal memory instead of an SD card, use
// https://github.com/lorol/arduino-esp32littlefs-plugin to upload the files.
// For local use of these libraries to work, "#define WEBSERVER" is also required!
//#define D3_LIBRARY_PATH "/d3.js"
//#define C3_LIBRARY_PATH "/c3.js"

// Compile CUNO/CUNX/modified MAX!Cube extension.
#define MAX_CUL
bool enable_max_cul = false;                // enable or disable connection to CUNO/CUNX/modified MAX!Cube;
byte max_cul_ip_addr[4] = {192,168,178,5};     // IP of CUNO/CUNX/modified MAX!Cube. Please use commas instead of dots!!!
char max_device_list[20][11] = {               // list of MAX! wall/heating thermostats that should be polled
  "KEQ0502326",                                // use MAX! serial numbers here which have to have exactly 10 characters
  "KEQ0505080"
};


// defines the number of retries for the query command
#define QUERY_RETRIES  3

// Setting bus pins and bus type

byte bus_pins[2] = {0,0}; //First value - RX pin, second value - TX pin. 0,0 - auto select (19,18 for Due, 16,17 for NodeMCU, 36,17 for Olimex EVB, 36,5 for Olimex POE and 68,69 for Mega).
uint8_t bus_type = 0;  // set bus system at boot: 0 = BSB, 1 = LPB, 2 = PPS
// BSB:
// - 'own_address' sets own address, defaults to 0x42 (LAN in serial monitor)
// - 'dest_address' sets destination address, defaults to 0 for heating system.
// LPB:
// - 'own_address and 'dest_address' set own and destination address (high nibble = segment, low nibble = device minus 1)
// - defaults to 0x42 for own address and 0x00 for destination address, i.e. segment 4, device 3 for Arduino/BSB-LAN and segment 0, device 1 for heating system
byte own_address = 0x42;
byte dest_address = 0x00;
// PPS:
// - set 'pps_write' to "1" to enable writing to heater - only use this if there is no other room controller (such as QAA50/QAA70) active.
bool pps_write = 0;
byte QAA_TYPE = 0x53;  // 0x53 = QAA70, 0x52 = QAA50, 0x5A = QAA10, 0x37 = QAA95, 0x66 = BMU, 0xEA = MCBA/REA70/DC225

/* Set the device family and device variant of your heating system. Only change this if you _really_ know what you are doing!
 * Set fixed_device_family and fixed_device_variant to your device family and variant (parameters 6225 and 6226) here
 * if heating system is not running when Arduino is powered on.
*/
uint16_t fixed_device_family = 0;
uint16_t fixed_device_variant = 0;

// defines default flag for parameters
// use "#define DEFAULT_FLAG FL_SW_CTL_RONLY" to control read/write functionality via configuration in web interface.
// use "#define DEFAULT_FLAG 0" to make (almost) all parameters writeable
// use #define DEFAULT_FLAG FL_RONLY to run the program always in read-only mode.
#define DEFAULT_FLAG FL_SW_CTL_RONLY

// include commands from BSB_lan_custom.h to be executed at the end of each main loop
//#define CUSTOM_COMMANDS

/*
 * Check for new versions when accessing BSB-LAN's main page.
 * Doing so will poll the most recent version number from the BSB-LAN server.
 * In this process, it is unavoidable that your IP address will be transferred to the server, obviously.
 * We nevertheless mention this here because this constitutes as 'personal data' and this feature is therefore disabled by default.
 * Activating this feature means you are consenting to transmitting your IP address to the BSB-LAN server where it will be stored
 * for up to two weeks in the server's log files to allow for technical as well as abuse analaysis.
 * No other data (such as anything related to your heating system) is transmitted in this process, as you can see in the source code.
*/
#define VERSION_CHECK
bool enable_version_check = false;

#define ENABLE_ESP32_OTA
boolean enable_ota_update = false;

// Reduce clock speed of ESP32 from 240 MHz to 80MHz, saving ca. 20% energy.
// Works well when connecting via LAN, but since it reduces WiFi range and log file display times when using WiFi, it is disabled by default.
boolean esp32_save_energy = false;

// "External" web server. Read files from SD-card. Only static content: html, js, css, jpg, etc.
//#define WEBSERVER

// Configuration will be stored in EEPROM
#define CONFIG_IN_EEPROM

// Compile web-based configuration and EEPROM config store module extension.
#define WEBCONFIG

// Compile JSON-based configuration and EEPROM config store module extension.
#define JSONCONFIG

#define RGT_EMULATOR
parameter rgte_sensorid[3][5] = {{{0, -1}, {0, -1}, {0, -1}, {0, -1}, {0, -1}}, {{0, -1}, {0, -1}, {0, -1}, {0, -1}, {0, -1}}, {{0, -1}, {0, -1}, {0, -1}, {0, -1}, {0, -1}}}; //Temperature sensor program IDs for RGT1/PPS - RGT3. If zero then RGT will not be emulated. If more than one program set per RGT then average will be calculated and used.

//Enable presence buttons and TWW/DHW push on selected pins.
// Pins on Mega can be (Digital) 2, 3, 18, 19, 20, 21
// On Due any Digital pins can be selected excluding 12, 16-21, 31, 33, 53.
// Make sure you aren't using pins which are already in use for sensors (default: 2, 3, 7) or change them accordingly.
#define BUTTONS
uint8_t button_on_pin[4] = {0, 0, 0, 0}; //Order: TWW push, presence ROOM1, presence ROOM2, presence ROOM3

// Variables for future use:
// Compile room unit replacement extension
#define ROOM_UNIT
byte UdpIP[4] = {0,0,0,0}; // (destination IP address for sending UDP packets to, the room unit replacement of FHEM user @fabulous uses that)
uint16_t UdpDelay = 15;    // (interval in seconds to send UDP packets)

// Compile off-site logger extension
#define OFF_SITE_LOGGER
byte destinationServer[128] = "";   // URL string to periodically send values to an off-site logger
uint16_t destinationPort = 80;      // port number for abovementioned server
uint32_t destinationDelay = 84600;  // interval in seconds to send values

#define CONFIG_VERSION 32

/************************************************************************************/
/************************************************************************************/
/* Settings -   END                                                                 */
/************************************************************************************/
/************************************************************************************/
