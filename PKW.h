#ifndef PKW_H
#define PKW_H
#include "Fahrzeug.h"
#include <limits>

class PKW : public Fahrzeug {
private:
    double p_dVerbrauch;
    double p_dTankvolumen;
    double p_dTankinhalt;

public:
    PKW(const std::string& name, double MaxGeschwindigkeit, double dVerbrauch, double dTankvolumen = 55.00)
        : Fahrzeug(name, MaxGeschwindigkeit),
          p_dVerbrauch(dVerbrauch),
          p_dTankvolumen(dTankvolumen),
          p_dTankinhalt(dTankvolumen / 2) {}

    virtual ~PKW();

    void vSimulieren() override;
    void vAusgabe(std::ostream& o) const override;
    double dTanken(double dMenge = std::numeric_limits<double>::infinity());
    double dGeschwindigkeit() const override;
};
#endif
