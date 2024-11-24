#ifndef FAHRRAD_H
#define FAHRRAD_H
#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:
    Fahrrad(const std::string& name, double MaxGeschwindigkeit)
        : Fahrzeug(name, MaxGeschwindigkeit) {}

    ~Fahrrad() override {}

    void vSimulieren() override;
    void vAusgabe(std::ostream& s) const override;
    double dGeschwindigkeit() const override;
};
#endif
