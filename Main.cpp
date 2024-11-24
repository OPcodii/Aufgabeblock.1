#include <iostream>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <memory>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

/*void vAufgabe1() {
	Fahrzeug f1("BMW" , 150);
    Fahrzeug f2("Benz", 120);
    cout<<"Fahrzeug Objekte wurden erstellt" << endl ;

    Fahrzeug* Car1 = new Fahrzeug("Honda" , 120 );
    Fahrzeug* Car2= new Fahrzeug("Toyota" , 100);

    cout<< " 2 new cars have been created " << Car1->getName()<< Car2->getName() << endl ;

    delete Car1;
    delete Car2;
    cout << "the 2 cars have been deleted" <<endl ;

    auto Fahrzeug1 = make_unique<Fahrzeug> ( "Nissan" , 120);
    auto Fahrzeug2 = make_shared<Fahrzeug>("Skoda" , 180);
    auto Fahrzeug3 = Fahrzeug2;
    cout<<"the number of shared pointers for Fahrzeug2 before reset is : "
    		<<Fahrzeug2.use_count() << endl ;
    Fahrzeug2.reset() ;
    cout<< " the number of shared pointers for Fahrzeug2 after reset : "
    		<< Fahrzeug2.use_count() << endl ;
    cout<< " now we are going to make a victor and add to it a unique ptr using push.back func" << endl ;
    vector<unique_ptr <Fahrzeug>> Cars ;
    Cars.push_back(move(Fahrzeug1));
    cout<<"now the vector will have the unique ptr at the end position "<< endl ;
    for (const auto& fahrzeug : Cars){
    	cout<<"Fahrzeug : " <<fahrzeug->getName()<< endl ;
    }
    Cars.clear();
    cout<<"now the Cars vector should be empty after using the func clear() "<< endl ;
}*/
/*void vAufgabe1a(){
	vector<unique_ptr<Fahrzeug>> Fahrzeuge ;
	for ( int i = 0 ; i < 3 ; i ++ ){
		string name;
		double MaxGeschwindigkeit;
		cout<<"geben Sie bitte ein Fahrzeug Name " << (i+1) << " :" ;
		cin>>name ;
		cout<<endl ;
		cout<<"geben Sie nun bitte die max Geschwindigkeit " << (i+1) << " : " ;
		cin>>MaxGeschwindigkeit ;
		cout<<endl ;

		Fahrzeuge.push_back(move(make_unique<Fahrzeug>(name , MaxGeschwindigkeit))) ;
	}
	 Fahrzeug::vKopf();
	 dGlobaleZeit = 0.0;
	double dSimulationDauer = 5.0 ;
	double dZeitSchritt = 0.5;

	while (dGlobaleZeit < dSimulationDauer) {
	        dGlobaleZeit += dZeitSchritt;

	        for (auto& fahrzeug : Fahrzeuge) {
	        	  fahrzeug->vSimulieren();
	        	  fahrzeug->vAusgabe();
	        }
	        cout<<endl;
}
}*/
/*void vAufgabe2(){
	int iPKWZahl , iFahrradZahl ;
	cout<< "wieviel PKWs wollen Sie erstellen ?  " ;
	cin >> iPKWZahl ;
	cout << " wieviel Fahrrader wollen Sie erstellen ? " ;
	cin >> iFahrradZahl ;
	vector<unique_ptr<PKW>> PKWs ;
	vector<unique_ptr<Fahrrad>> Fahrrads ;
	for(int i = 0 ; i < iPKWZahl; i++){
		string name ;
		double MaxGeschwindigkeit , dVerbrauch;
		cout<<"was soll die PKW heissen ? ";
		cin>> name ;
		cout<<endl;
		cout<<" was soll die max Geschwindigkeit des PKWs sein ? ";
		cin>> MaxGeschwindigkeit;
		cout<<endl;
		cout<<"verbrauch ? (L / 100km ) " ;
		cin>>dVerbrauch;
		cout<<endl;
		PKWs.push_back(move(make_unique<PKW>(name , MaxGeschwindigkeit ,dVerbrauch)));

	}
	for(int i = 0 ; i < iFahrradZahl ; i++){
	string name ;
	 double MaxGeschwindigkeit;
	cout<<"was soll die Fahrrad heissen ? ";
	cin>> name ;
	cout<<endl;
	cout<<" was soll die max Geschwindigkeit des Fahrrads sein ? ";
	cin>> MaxGeschwindigkeit;
	cout<<endl;
	Fahrrads.push_back(move(make_unique<Fahrrad>(name , MaxGeschwindigkeit)));
	}
	 Fahrzeug::vKopf();
dGlobaleZeit = 0.0;
double dSimulationDauer = 5.0 ;
double dZeitSchritt = 0.5;

while (dGlobaleZeit < dSimulationDauer) {
	dGlobaleZeit += dZeitSchritt;

if (static_cast<int>(dGlobaleZeit) % 3 == 0) {
	 cout << "PKW wird nach" << dGlobaleZeit << "stunden getankt " << endl;
	   for (auto& pkw : PKWs) {
	        pkw->dTanken();
	    }
for (auto& pkw : PKWs) {
 pkw->vSimulieren();
 pkw->vAusgabe(cout);
 pkw->dGeschwindigkeit();
		        }
for (auto& fahrrad : Fahrrads) {
 fahrrad->vSimulieren();
 fahrrad->vAusgabe(cout);
 fahrrad->dGeschwindigkeit();
		        }
cout<<endl;
}
}
}*/
void vAusgabe3() {
    Fahrzeug f1("Car1", 100);
    Fahrzeug f2("Car2", 120);
    PKW p1("BMW", 150, 8.0);
    Fahrrad b1("Bike", 30);

    std::cout << "Testing operator<<:" << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << p1 << std::endl;
    std::cout << b1 << std::endl;

    std::cout << "\nTesting operator<:" << std::endl;
    if (f1 < f2) {
        std::cout << f1.getName() << " has traveled less distance than " << f2.getName() << "." << std::endl;
    } else {
        std::cout << f1.getName() << " has traveled more or equal distance than " << f2.getName() << "." << std::endl;
    }

    std::cout << "\nTesting assignment operator:" << std::endl;
    std::cout << "Before assignment, f1: " << f1 << std::endl;
    f1 = f2;
    std::cout << "After assignment, f1: " << f1 << std::endl;
}


int main () {
	//vAufgabe2();
	vAusgabe3();
	return 0 ;
}
