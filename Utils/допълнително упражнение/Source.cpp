#include<iostream>
#include"chatSystem.h"

int main() {
	chatSystem data;

	data.addUser({ "Ivan", "1234", "iv@abv.bg" });
	data.addUser({ "Qvor", "4321", "qv@abv.bg" });

	data.sendMessage("last example", "Ivan", "Qvor");
	data.viewMessages("Qvor", "Ivan");
}