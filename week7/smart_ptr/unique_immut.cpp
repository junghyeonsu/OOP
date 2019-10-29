//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}



void unique_immut::release() {
	if (_mgr->ptr != nullptr) {
		_mgr->~mgr();
	}(_mgr->count)++; // 왜?
}

Object* unique_immut::get() const {
	if (_mgr->ptr == nullptr) {
		return nullptr;
	}
	else {
		return _mgr->ptr;
	}
}

unique_immut unique_immut::operator+(unique_immut& unique) {
	
	int one = unique._mgr->ptr->get();
	int two = this->_mgr->ptr->get();
	int three = one + two;
	this->release();
	unique.release();
	return unique_immut(new Object(three));
}

unique_immut unique_immut::operator-(unique_immut& unique) {
	unique_immut i = *this;
	int one = unique._mgr->ptr->get();
	int two = i._mgr->ptr->get();
	int three = two - one;
	i.release();
	unique.release();
	return unique_immut(new Object(three));
}

unique_immut unique_immut::operator*(unique_immut& unique) {
	unique_immut i = *this;
	int one = unique._mgr->ptr->get();
	int two = i._mgr->ptr->get();
	int three = one * two;
	i.release();
	unique.release();
	return unique_immut(new Object(three));
}

unique_immut unique_immut::operator/(unique_immut& unique) {
	unique_immut i = *this;
	int one = unique._mgr->ptr->get();
	int two = i._mgr->ptr->get();
	int three = two/one;
	i.release();
	unique.release();
	return unique_immut(new Object(three));
}

Object* unique_immut::operator->() {
	return _mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut& unique) {
	if (unique._mgr == this->_mgr) {
		return *this;
	}
	else {
		this->release();
		*this = unique;
		return *this;
	}
}

} // end of namespace ptr

