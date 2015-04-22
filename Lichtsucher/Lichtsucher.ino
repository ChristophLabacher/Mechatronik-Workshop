void setup(){
	// DREHER
	pinMode(9, OUTPUT);
	pinMode(8, OUTPUT);
	int dreherRight = 9;
	int dreherLeft = 8;
	int dreherInput = A4;
	
	// VERBINDUNG
	pinMode(7, OUTPUT);
	pinMode(6, OUTPUT);
	int verbindungDown = 7;
	int verbindungUp = 6;
	int verbindungInput = A3;
	
	// ARM
	pinMode(5, OUTPUT);
	pinMode(4, OUTPUT);
	int armUp = 5;
	int armDown = 4;
	int armInput = A2;
	
	// KIPPER
	pinMode(3, OUTPUT);
	pinMode(2, OUTPUT);
	int kipperUp = 3;
	int kipperDown = 2;
	int kipperInput = A1;

	// GREIFER
	pinMode(1, OUTPUT);
	pinMode(0, OUTPUT);
	int greiferOpen = 1;
	int greiferClose = 0;
	int greiferInput = A0;

	// Reset
	digitalWrite(9, LOW);
	digitalWrite(8, LOW);
	digitalWrite(7, LOW);
	digitalWrite(6, LOW);
	digitalWrite(5, LOW);
	digitalWrite(4, LOW);
	digitalWrite(3, LOW);
	digitalWrite(2, LOW);
	digitalWrite(1, LOW);
	digitalWrite(0, LOW);

	Serial.begin(9600);
	
	digitalWrite(kipperUp, HIGH);
	delay(500);
	digitalWrite(kipperUp, LOW);
}

void loop () {
}