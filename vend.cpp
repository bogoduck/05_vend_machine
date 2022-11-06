#include <string>
#include <iostream>
#include "vend.h"

Snack::Snack(const std::string& name)
{
	this->_name = name;
	std::cout << "Snack: " << _name << " created" << std::endl;
};

Snack::~Snack() {
	std::cout << "Snack: " << _name << " deleted" << std::endl;
};

SnackSlot::SnackSlot(size_t size)
{
	_size = size;
	std::cout << "New slot of " << _size << " (size) created" << std::endl;
	_array = new Snack * [_size];
	for (size_t i{0}; i < _size; ++i) {
		_array[i] = nullptr;
	};
};

SnackSlot::~SnackSlot()
{
	std::cout << "Slot deleted" << std::endl;
	delete[] _array;
};


void SnackSlot::addSnack(Snack* snack)
{
	this->_array[_item] = snack;
	this->_item++;
	std::cout << "Snack added" << std::endl;
};

size_t SnackSlot::getEmptySlots()
{
	int result{ 0 };
	for (int i{ 0 }; i < this->_size; i++){
		if (this->_array[i] == nullptr) 
			result++;
	}
	return result;
}

	

VendingMachine::VendingMachine(size_t size)
{
	_vsize = size;
	std::cout << "New VM of " << _vsize << " (size) created" << std::endl;
	_varray = new SnackSlot * [_vsize];
	for (size_t i{ 0 }; i < _vsize; ++i) {
		_varray[i] = nullptr;
	};
};

VendingMachine::~VendingMachine()
{
	std::cout << "VM deleted" << std::endl;
	delete[] _varray;
};

size_t VendingMachine::getEmptySlotsCount() {
	size_t result{ 0 };
	for (int i{ 0 }; i < this->_vsize; i++) {
		if (this->_varray[i] != nullptr) {
			result += this->_varray[i]->getEmptySlots();
		}
	}
	return result;
};

