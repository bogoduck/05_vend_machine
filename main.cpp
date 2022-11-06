#include <iostream>
#include "vend.h"

using namespace std;

int main() {
	Snack *bounty = new Snack("Bounty");
	Snack *snickers = new Snack("Snickers");
	SnackSlot* slot = new SnackSlot(10);
	SnackSlot* slot2 = new SnackSlot(15);
	slot->addSnack(bounty); 
	slot->addSnack(snickers);
	VendingMachine* machine = new VendingMachine(5);
	machine->addSlot(slot);
	machine->addSlot(slot2);// Помещаем слот обратно в аппарат
	//cout << slot->getEmptySlots() << endl;

	cout << machine->getEmptySlotsCount() << " Slots in VM left " << endl; // Должно выводить количество пустых слотов для снеков
	delete machine;
	delete slot;
	delete snickers;
	delete bounty;


	return 0;
}