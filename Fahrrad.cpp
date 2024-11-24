#include "Fahrrad.h"
#include <algorithm>
#include <cmath>
void Fahrrad::vSimulieren() {
    Fahrzeug::vSimulieren();
}

void Fahrrad::vAusgabe(std::ostream& o) const {
    Fahrzeug::vAusgabe(o);
    o << std::endl;
}

double Fahrrad::dGeschwindigkeit() const {
    double dReduktion = 1.0 - (0.10 * (p_dGesamtStrecke / 20.0));
    double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * dReduktion;
    if (std::fabs(dAktuelleGeschwindigkeit - 12.0) < 0.0001 || dAktuelleGeschwindigkeit < 12.0) {
        return 12.0;
    }
    return dAktuelleGeschwindigkeit;
}
std::ostream& operator<<(std::ostream& o, const Fahrzeug& x){
	x.vAusgabe(o);
	return o;
};
Fahrzeug& Fahrzeug::operator=(const Fahrzeug& other) {
    if (this == &other) return *this;
    p_sName = other.p_sName;
    p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
    return *this;
}

