#include "Debugger.h"
#include <string.h>
#include "Arduino.h"
/*
Default Constructor - initializes Serial with a baudrate of 9600
On the Android application side, I'll read the first byte to determine how many different types of variables the embedded side will send
The ID will of the type will be based on the order you sent the initialization stuff.

For example, int's sent first, so it has an ID of 0.
*/
Debugger::Debugger()
{//assuming your Bluetooth module is connected to the Arduino's RX/TX pins
	Serial.begin(9600);//9600 = default baudRate
	Serial.write((unsigned char)numTypes);
	Serial.write("int");
	Serial.write("double");
	Serial.write("byte");
	Serial.write("String");
}
/*
Constructor - initializes Serial with a baudrate of the input
On the Android application side, I'll read the first byte to determine how many different types of variables the embedded side will send
The ID will of the type will be based on the order you sent the initialization stuff.

For example, int's sent first, so it has an ID of 0.
*/
Debugger::Debugger(int baudRate)
{//assuming your Bluetooth module is connected to the Arduino's RX/TX pins
	Serial.begin(baudRate);
	Serial.write((unsigned char)numTypes);
	Serial.write("int");
	Serial.write("double");
	Serial.write("byte");
	Serial.write("String");
}
/*
Send (integers): sends bytes via Serial in the following format for the Android Application
1. number of bytes in variable name (its string length)
2. the variable name
3. the variable type ID (e.g. int is 0 in this scenario)
4. the actual value of the variable
*/
void Debugger::send(const char* varName, int varValue)
{
	//first byte = number of bytes in varName
	Serial.write((unsigned char) strlen(varName));
	Serial.write(varName);//rest is varName
	//sends ID of int
	Serial.write(typeIsInt);//note typeIsInt is declared in Debugger.h
	//sends value
	Serial.write(varValue);
}

/*
Deconstructor: ends serial
*/
Debugger::~Debugger()
{
	Serial.end();
}
/*To implement later*/
void Debugger::receiveUpdates()
{
	return;
}