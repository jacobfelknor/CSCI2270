class Time12
{
private:
	int hour;
	int minute;
	string mer;

public:
	//constructors:
	Time12( int h, int m, string me );
	Time12( ){};

	//display function
	void printTime();

	// mutator functions:
	void setHour( int h ); 
	void setMinute( int m );
	// accessor functions
	int getHour();
	int getMinute();

};