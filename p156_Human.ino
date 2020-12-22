/************************************************************
■参考
	■Arduino 電子工作 実践講座
		p156
************************************************************/
#define PLOTTER

/************************************************************
************************************************************/
const int PIR_PIN = 4;

/******************************
******************************/
void setup(){
	pinMode( PIR_PIN, INPUT ); // set : Digital Pin : for open collector.

	Serial.begin( 9600 );
}

/******************************
******************************/
void loop() {
	int analog_val;
	float input_volt;
	
	analog_val = analogRead(PIR_PIN); // 試験端子
	input_volt = float(analog_val) * 5.0 / 1023.0;
	
#ifdef PLOTTER
	Serial.print( millis() / 1000 % 2 * 10 );
	Serial.print(",");
#endif

	Serial.print(input_volt);
	Serial.print(",");
	
	if(digitalRead(PIR_PIN) == HIGH){ // open collector.
		Serial.println(5);	// nobody
	}else{
		Serial.println(0);	// somebody
	}
	
#ifdef PLOTTER
	delay(100);
#else
	delay(1000);
#endif
}
