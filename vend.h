#pragma once
#include <string>
#include <iostream>

class Snack {
private:
	std::string _name;
public:
	Snack(const std::string& name);
	~Snack();
};

class SnackSlot {
private:
	size_t _size{ 0 };
	size_t _item{ 0 };
	Snack** _array{ nullptr };
public:
	SnackSlot(size_t size);
	~SnackSlot();
	void addSnack(Snack* snack);
	size_t getEmptySlots();
};

class VendingMachine {
private:
	size_t _vsize{ 0 };
	size_t _vitem{ 0 };
	size_t _vempty{ 0 };
	SnackSlot** _varray{ nullptr };
public:
	VendingMachine(size_t size);
	~VendingMachine();
	void addSlot(SnackSlot* slot) 
	{
		_varray[_vitem] = slot;
		_vitem++;
		std::cout << "Slot added" << std::endl;
	};
	size_t getEmptySlotsCount();
};