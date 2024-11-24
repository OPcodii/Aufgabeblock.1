#include "Fahrzeug.h"
#include <iomanip>
#include <iostream>

int Fahrzeug::p_iMaxID = 0;
double dGlobaleZeit = 0.0;

void Fahrzeug::vKopf() {
    std::cout << std::setw(10) << std::setiosflags(std::ios::left) << "ID";
    std::cout << std::setw(20) << std::setiosflags(std::ios::left) << "Name";
    std::cout << std::setw(20) << std::setiosflags(std::ios::left) << "MaxGeschwindigkeit";
    std::cout << std::setw(20) << std::setiosflags(std::ios::left) << "GesamtStrecke";
    std::cout << std::setw(20) << std::setiosflags(std::ios::left) << "Verbrauch (L)";
    std::cout << std::setw(20) << std::setiosflags(std::ios::left) << "Tankinhalt (L)";
    std::cout << std::endl;
    std::cout << std::string(110, '-') << std::endl;
}

void Fahrzeug::vAusgabe(std::ostream& o) const {
    o << std::setw(10) << std::setiosflags(std::ios::left) << p_iID;
    o << std::setw(20) << std::setiosflags(std::ios::left) << p_sName;
    o << std::setw(20) << std::setiosflags(std::ios::left) << p_dMaxGeschwindigkeit;
    o << std::setw(20) << std::setiosflags(std::ios::left) << p_dGesamtStrecke;
}

void Fahrzeug::vSimulieren() {
    if (p_dZeit >= dGlobaleZeit) {
        return;
    }

    double dVergangeneZeit = dGlobaleZeit - p_dZeit;
    p_dGesamtStrecke += dVergangeneZeit * dGeschwindigkeit();
    p_dZeit = dGlobaleZeit;
}

double Fahrzeug::dGeschwindigkeit() const {
    return p_dMaxGeschwindigkeit;
}
bool Fahrzeug::operator<(const Fahrzeug& other) const {
    return p_dGesamtStrecke < other.p_dGesamtStrecke;
}
