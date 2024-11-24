#include <iostream>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <memory>
#include <vector>
#include <string>
#include <iomanip>
#include<cmath>

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
void vAufgabe2(){
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
dGlobaleZeit = 0.0;
double dSimulationDauer = 5.0 ;
double dZeitSchritt = 0.5;

while (dGlobaleZeit < dSimulationDauer) {
	dGlobaleZeit += dZeitSchritt;
	 Fahrzeug::vKopf();
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
double dletzteTankZeit= 0.0;
if (std::fabs(std::fmod(dGlobaleZeit, 3.0)) < 0.0001 && dGlobaleZeit - dletzteTankZeit >= 3.0) {
    for (auto& pkw : PKWs) {
    	 cout <<pkw->getName() <<" wird nach " << dGlobaleZeit << " Stunden getankt." << endl;
        pkw->dTanken();
    }
    dletzteTankZeit = dGlobaleZeit;
}

cout<<endl;
}
}

void vAusgabe3() {
    Fahrzeug f1("Car1", 100);
    Fahrzeug f2("Car2", 120);
    PKW p1("BMW", 150, 8.0);
    Fahrrad b1("BMX", 30);
cout<<"\n hier werden wir vAusgabe3 nutzen um Operatoren zu testen" << endl;
    cout<<"operator<<:" <<endl;
    Fahrzeug::vKopf();
    cout<<f1<<endl;
    cout<<f2<<endl;
    cout<<p1<<endl;
    cout<<b1<<endl;

    cout << "\n jetzt uberprufen wir der operator< : " <<endl <<endl;
    if (f1 < f2) {
        std::cout << f1.getName() << " is weniger als " << f2.getName() << " gefahren" << std::endl;
    } else {
        std::cout << f1.getName() << " ist mehr oder gleich " << f2.getName() << " gefahren" << std::endl;
    }

    cout<< "\n jetzt uberprufen wir der =operator:" <<endl;
    cout<< "bevor wir der Operator nutzen, f1 : " << f1 << std::endl;
    f1 = f2;
    std::cout << "danach , f1: " << f1 << std::endl;
    cout<<endl;
}


int main () {
	vAufgabe2();
	vAusgabe3();
	return 0 ;
}
