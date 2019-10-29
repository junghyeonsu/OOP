//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
	shared_mut::shared_mut() {
		_mgr = new mgr();
	}

	shared_mut::shared_mut(Object* _obj) {
		_mgr = new mgr(_obj);
	}

	shared_mut::~shared_mut() {
		release();
	}

	shared_mut::shared_mut(const shared_mut& a) {
		_mgr = a._mgr;
		increase();
	}

	void shared_mut::release() {

		if (this->_mgr->count == 0)
		{
			this->_mgr->count = this->_mgr->count-1;
			this->_mgr = new mgr();
		}
		if (this->_mgr->count != 0)
		{
			delete this->_mgr;
			this->_mgr = new mgr();
		}
		this->_mgr = new mgr();

	}
	Object* shared_mut::get() const {
		if (_mgr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return _mgr->ptr;
		}
	}

	int shared_mut::count() {
		return this->_mgr->count;
	}

	void shared_mut::increase() {
		this->_mgr->count = this->_mgr->count+1;
	}

	shared_mut shared_mut::operator+(const shared_mut &shared) {
		
		int one = this->_mgr->ptr->get();
		int two = shared._mgr->ptr->get();
		int three = one + two;
		return shared_mut(new Object(three));
	}

	shared_mut shared_mut::operator-(const shared_mut &shared) {
		shared_mut a = *this;
		int one = a._mgr->ptr->get();
		int two = shared._mgr->ptr->get();
		int three = one - two;
		shared_mut b  =  shared_mut(new Object(three));
		return b; 
	}

	shared_mut shared_mut::operator*(const shared_mut &shared) {
		shared_mut a = *this;
		int one = a._mgr->ptr->get();
		int two = shared._mgr->ptr->get();
		int three = one * two;
		shared_mut b  =  shared_mut(new Object(three));
        return b; 
	}

	shared_mut shared_mut::operator/(const shared_mut& shared) {
		shared_mut a = *this;
		int one = a._mgr->ptr->get();
		int two = shared._mgr->ptr->get();
		int three = one / two;
		shared_mut b  =  shared_mut(new Object(three));
       return b; 

	}

	Object* shared_mut::operator->() {
		return this->_mgr->ptr;
	}

	shared_mut &shared_mut::operator=(const shared_mut & a) {

		this->_mgr = a._mgr;

		return *this;
	}



} // end of namespace ptr

