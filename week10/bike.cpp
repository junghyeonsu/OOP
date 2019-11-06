#include "vehicle.h"
#include "bike.h"

bike::bike() {
	this->bike_name = nullptr;
}

bike::bike(int _wheel_number, int _max_speed) {
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
	this->bike_name = nullptr;
}

bike::bike(int _wheel_number, int _max_speed, char* _bike_name) {
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
	this->bike_name = _bike_name;
}

bike::bike(int _wheel_number, int _max_speed, char* _bike_name, int _bike_number) {
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
	this->bike_name = _bike_name;
	this->bike_number = _bike_number;
}

bike::bike(int _wheel_number, int _max_speed, char* _bike_name, int _bike_number, bool _has_name) {
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
	this->bike_name = _bike_name;
	this->bike_number = _bike_number;
	this->has_name = _has_name;
}

int bike::get_bike_number() {
	return this->bike_number;
}

char* bike::get_bike_name() {
	return this->bike_name;
}

const char* bike::get_class_name() {
	return "bike";
}

void bike::set_bike_name(char* _name) {
	this->bike_name = _name;
}

void bike::set_bike_number(int _number) {
	this->bike_number = _number;
}
