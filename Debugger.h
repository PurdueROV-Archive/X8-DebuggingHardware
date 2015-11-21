#ifndef ROV_DEBUGGER
#define ROV_DEBUGGER
//ID's
#define numTypes 4
#define typeIsInt 0
#define typeIsDouble 1
#define typeIsByte 2
#define typeIsString 3

/*
To use this library:
1. initialize a Debugger object
2. send("your variable's name", your variable)

for example
int var = 1;
Debugger* debugger = new Debugger();
debugger.send("var", var);

*/

class Debugger
{
public:
	Debugger();//default constructor; initializes serial with a default value of 9600
	Debugger(int baudRate);//constructor; initializes serial with baud rate of whatever you put in
	//all these functions write to Serial. These are overloaded for different types of values you might send
	void send(const char* varName, int varValue);
	void send(const char* varName, double varValue);
	void send(const char* varName, char varValue);
	void send(const char* varName, char* varValue);
	~Debugger();
private:
	//function for receiving updates	
	void receiveUpdates();
};

#endif
