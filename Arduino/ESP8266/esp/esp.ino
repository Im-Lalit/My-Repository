//my web site, replace with yours
#define DST_IP "192.168.88.35"

//Define the pin for the on board LE
int led = 13 ;

//Initialize Device
void setup ()
{
//Enable the Onboard LED to act as a
pinMode( led, OUTPUT );
//Set the speed for communicating wit
Serial . begin ( 9600);
//Send a series of flashes to show u
blinkcode ();
//Reset the ESP8266
Serial . println ( "AT+RST" );
//Wait for the WiFi module to bootup
delay ( 800);
//Switch the chip to "client" mode
Serial . println ( "AT+CWMODE=1" );
//Connect to our Wireless network NOT
//network and PASSWORD to the key use
Serial . println ( "AT+CWJAP=\"SSID\",\"P");
//Once again blink some lights becaus
blinkcode ();
}
void loop()
{
//Open a connection to the web server
String cmd = "AT+CIPSTART=\"TCP\",\"";
cmd += DST_IP ;
cmd += "\",80" ;
Serial . println ( cmd);
//wait a little while for 'Linked'
delay ( 300);
//This is our HTTP GET Request change
cmd = "GET /status.html HTTP/1.0\r\n";
cmd += "Host: 192.168.88.35\r\n\r\n";
//The ESP8266 needs to know the size
Serial . print ( "AT+CIPSEND=" );
Serial . println ( cmd. length ());
//Look for the > prompt from the esp8
if ( Serial . find( ">"))
{
//Send our http GET request
Serial . println ( cmd);
}
else
{
//Something didn't work...
Serial . println ( "AT+CIPCLOSE" );
}
//Check the returned header & web pag
if ( Serial . find( "YES12321" ))
{
//If the string was found we know th
//light to show the server is ONLINE
digitalWrite( led , HIGH);
}
else
{
//If the string was not found then w
//we should turn of the light.
digitalWrite( led , LOW);
}
//Wait a second for everything to set
delay ( 1000);
//Be great people and close our conne
Serial . println ( "AT+CIPCLOSE" );
//Introduce a delay timer before we
delay ( 5000 );
}
void blinkcode ()
{
//Simply loop a few times flashing th
int i ;
for ( i = 1 ; i <= 10 ; i ++ ){
delay ( 100 );
digitalWrite( led , HIGH);
delay ( 100 );
digitalWrite( led , LOW);
}
}
