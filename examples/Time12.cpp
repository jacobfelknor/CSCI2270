#include <iostream>
#include <string>

using namespace std;
#include "Time12.h"

Time12::Time12( int h, int m, string me ){ // constructor definition, is special kind of public method

	if ( h >= 0 && h <= 12 )
		hour = h;
	else
		cout << "bad choice " << endl;

	if( m >=0 && m <=60 )
		minute = m;
	else
		cout << "wrong choice for minute " << endl;

	mer = me;
}

void Time12::printTime(){
	cout << hour << ":" << minute << mer << endl;
}


void Time12::setHour( int h ){ // mutator
	if ( h >= 0 && h <= 12 )
		hour = h;
	else
		cout << "bad choice " << endl;
}

void Time12::setMinute( int m ){
	if( m >=0 && m <=60 )
		minute = m;
	else
		cout << "wrong choice for minute " << endl;

}

// accessor methods
int Time12::getHour() {
	return hour;
}

// accessor methods
int Time12::getMinute() {
	return minute;
}
