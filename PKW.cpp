#include "PKW.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

PKW::~PKW() {}

double PKW::dTanken(double dMenge) {
    double dTankMenge = std::min(dMenge, p_dTankvolumen - p_dTankinhalt);
    p_dTankinhalt += dTankMenge;
    std::cout << "Der Tankinhalt beträgt jetzt: " << p_dTankinhalt << " Liter." << std::endl;
    return dTankMenge;
}

void PKW::vSimulieren() {
    Fahrzeug::vSimulieren();

    if (p_dTankinhalt <= 0) {
        std::cout << getName() << " ist aufgrund eines leeren Tanks aufgehalten." << std::endl;
        return;
    }

    double dVerbrauch = (p_dGesamtStrecke / 100.0) * p_dVerbrauch;

    if (p_dTankinhalt >= dVerbrauch) {
        p_dTankinhalt -= dVerbrauch;
    } else {
        std::cout << getName() << " hat nicht genug im Tank, um weiterzufahren." << std::endl;
    }
}

void PKW::vAusgabe(std::ostream& o) const {
    Fahrzeug::vAusgabe(o);
    o << std::setw(20) << std::setiosflags(std::ios::left)
              << (p_dGesamtStrecke / 100.0) * p_dVerbrauch;
    o << std::setw(20) << std::setiosflags(std::ios::left) << p_dTankinhalt;
    o << std::endl; // Ensure row separation
}

double PKW::dGeschwindigkeit() const {
    return p_dMaxGeschwindigkeit;
}
