#include "vehicle.h"

vehicle::vehicle() {
	this->has_name = false;
}

vehicle::vehicle(int _wheel_number, int _max_speed) {
	this->has_name = false;
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
}

vehicle::vehicle(int _wheel_number, int _max_speed, bool _has_name) {
	this->has_name = _has_name;
	this->wheel_number = _wheel_number;
	this->max_speed = _max_speed;
}

int vehicle::get_wheel_number() {
	return this->wheel_number;
}

int vehicle::get_max_speed() {
	return this->max_speed;
}

bool vehicle::get_has_name() {
	return this->has_name;
}

const char* vehicle::get_class_name() {
	return "vehicle";
}

void vehicle::set_wheel_number(int _wheel_number) {
	this->wheel_number = _wheel_number;
}
void vehicle::set_max_speed(int _max_speed) {
	this->max_speed = _max_speed;
}
void vehicle::set_has_name(bool _has_name) {
	this->has_name = _has_name;
}
