#ifndef FAHRZEUG_H
#define FAHRZEUG_H
#include <iostream>
#include <string>

extern double dGlobaleZeit;

class Fahrzeug {
private:
    std::string p_sName;
    const int p_iID;
    static int p_iMaxID;
    Fahrzeug(const Fahrzeug&) = delete;

protected:
    double p_dMaxGeschwindigkeit;
    double p_dGesamtStrecke;
    double p_dGesamtZeit;
    double p_dZeit;

public:
    Fahrzeug(const std::string& name)
        : p_sName(name),
          p_iID(++p_iMaxID),
          p_dMaxGeschwindigkeit(),
          p_dGesamtStrecke(),
          p_dGesamtZeit(),
          p_dZeit() {
        std::cout << p_sName << " ist erstellt, ID " << p_iID << std::endl;
    }

    Fahrzeug()
        : p_sName(""),
          p_iID(++p_iMaxID),
          p_dMaxGeschwindigkeit(),
          p_dGesamtStrecke(),
          p_dGesamtZeit(),
          p_dZeit() {
        std::cout << p_sName << " ist erstellt, ID " << p_iID << std::endl;
    }

    Fahrzeug(const std::string& name, double MaxGeschwindigkeit)
        : p_sName(name),
          p_iID(++p_iMaxID),
          p_dMaxGeschwindigkeit(MaxGeschwindigkeit > 0 ? MaxGeschwindigkeit : 0),
          p_dGesamtStrecke(),
          p_dGesamtZeit(),
          p_dZeit() {
        std::cout << p_sName << " ist erstellt, ID " << p_iID << std::endl;
    }

    virtual ~Fahrzeug() {
        std::cout << p_sName << " ist gelöscht, ID " << p_iID << std::endl;
    }

    std::string getName() const { return p_sName; }
    int getID() const { return p_iID; }

    static void vKopf();
    virtual void vAusgabe(std::ostream& o) const;
    virtual void vSimulieren();
    virtual double dGeschwindigkeit() const;
    bool operator<(const Fahrzeug& other) const;
    Fahrzeug& operator=(const Fahrzeug&);

};
std::ostream& operator<<(std::ostream& o, const Fahrzeug& x);
#endif
