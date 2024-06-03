#include <iostream>

struct AirBag {};
struct EUSafetyStandardAirBag : AirBag {};
struct USSafetyStandardAirBag : AirBag {};

struct TurnSignal {};
struct YellowTurnSignal : TurnSignal { };
struct RedTurnSignal : TurnSignal { };

// Abstract factory creating a family of car parts
class CarPartsFactory {
public:
	virtual AirBag* createAirBag() const = 0;
	virtual TurnSignal* createTurnSignal() const = 0;
	// ...

	virtual ~CarPartsFactory() = default;
};

class EuropeanCarPartsFactory : public CarPartsFactory {
public:
	AirBag* createAirBag() const override {
		return new EUSafetyStandardAirBag();
	}
	TurnSignal* createTurnSignal() const override {
		return new YellowTurnSignal();
	}
};

class USCarPartsFactory : public CarPartsFactory {
public:
	AirBag* createAirBag() const override {
		return new USSafetyStandardAirBag();
	}
	TurnSignal* createTurnSignal() const override {
		return new RedTurnSignal();
	}
};

// maybe with enum :)
CarPartsFactory* factoryOfFactories(bool isEU) {
	if (isEU) {
		return new EuropeanCarPartsFactory();
	}
	else {
		return new USCarPartsFactory();
	}
}

void createCar(CarPartsFactory* partsFactory) {
	AirBag* airbag = partsFactory->createAirBag();
	TurnSignal* turnSignal = partsFactory->createTurnSignal();
	// create much more stuff
}

int main() {
	CarPartsFactory* factory = factoryOfFactories(true);
	createCar(factory);

	delete factory;
}
