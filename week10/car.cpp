#include "vehicle.h"
#include "car.h"

car::car() {
	this->car_name = nullptr;
}

car::car(int _wheel_number, int _max_speed) {
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
	this->car_name = nullptr;
}

car::car(int _wheel_number, int _max_speed, char* _car_name) {
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
	this->car_name = _car_name;
}

car::car(int _wheel_number, int _max_speed, char* _car_name, bool _has_name) {
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
	this->car_name = _car_name;
	this->has_name = _has_name;
}


char* car::get_car_name() {
	return this->car_name;
}

const char* car::get_class_name() {
	return "car";
}

void car::set_car_name(char* _name) {
	this->car_name = _name;
}
