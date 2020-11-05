#include <string>
#include <fstream>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <ctime>
#include <stdlib.h>



class Building{

protected:
    int Number;
    int Floors;
   
public:
    Building() {}; // { std::cout << "Konstruktor typu Buidling \n"; };
    virtual ~Building() {}; // { std::cout << "virtualny destruktor typu Building \n"; };
    virtual void Print() {};

    int GetFloors() { return Floors; };
    virtual void SetSales(int s) {};        //tato procedura je vyuzita aj pre Factory
    virtual int GetEmp() { return 0; };     //tato funkcia tiez
    virtual void SetAp(int a) {};
};


class Street {

private:
    int NFamilyHouse;
    int NApartmentHouse;
    int NBusinessBuilding;
    int NFactory;
    int NBuildings;
    std::string NameStreet;
    std::string NameCity;
    Building** BuildingsPointer;

public:
   
    Street() {}; // { std::cout << "prazdny kostruktor typu Street\n"; };
    Street(std::string S, std::string C) { NameStreet = S; NameCity = C; };
    virtual ~Street();

    void GenerateStreet();
    void PrintStreet();
};

//###########################################################################################################

class FamilyHouse: public Building{
private:
    int AreaHouse;
    int AreaGarden;
public:
    FamilyHouse(int n, int f, int ah, int ag);
    FamilyHouse() {}; // {std::cout << "Prazdny kostruktor objektu typu FamilyHouse.\n"; };        //toto ani netreba
    ~FamilyHouse() {}; // { std::cout << "Destruktor objektu typu FamilyHouse.\n"; };
    void Print();
};

class ApartmentHouse : public Building {
private:
    int Ap;
public:
    ApartmentHouse(int n, int f, int ap);
    ApartmentHouse() {}; // { std::cout << "Prazdny kostruktor objektu typu ApartmentHouse.\n"; };     //toto ani netreba
    ~ApartmentHouse() {}; // { std::cout << "Destruktor objektu typu ApartmentHouse.\n"; };
    void Print();
    void SetAp(int a) { Ap = a; }; 
};

class BusinessBuilding : public Building {
private:
    int Employees;
    int Sales;
    int Sections;
public:
    BusinessBuilding(int n, int f, int e, int sa, int se);
    BusinessBuilding() {}; // { std::cout << "Prazdny kostruktor objektu typu BusinessBuilding.\n"; };         //toto ani netreba
    ~BusinessBuilding() {}; //  { std::cout << "Destruktor objektu typu BusinessBuilding.\n"; };
    void Print();

    int GetEmp() { return Employees; };
    void SetSales(int sa) { Sales = sa; };
};

class Factory : public Building {
private:
    
    int Employees;
    int Sales;
    int Area;
public:
    Factory(int n, int f, int e, int sa, int a);
    Factory() {}; // { std::cout << "Prazdny kostruktor objektu typu Factory.\n"; };       //toto ani netreba
    ~Factory() {}; //  { std::cout << "Destruktor objektu typu Factory.\n"; };
    void Print();  

    int GetEmp() { return Employees; };
    void SetSales(int sa) { Sales = sa; };
};


Street::~Street()
{
    int i;
    for (i = 0; i < NBuildings; i++) {
        delete BuildingsPointer[i];
    }

    delete[] BuildingsPointer;
    
    //std::cout << "Destruktor objektu typu STREET. \n";
}

void Street::GenerateStreet()
{
    int i;
    NFamilyHouse = rand() % 50 + 1;         //vygeneruje pocty budov
    NApartmentHouse = rand() % 20 + 1;
    NBusinessBuilding = rand() % 10 + 1;
    NFactory = rand() % 5 + 1;          
    NBuildings = NFamilyHouse + NApartmentHouse + NBusinessBuilding + NFactory;     //scita vsetky budovy dokopy

    BuildingsPointer = new Building * [NBuildings];     //naplnuje smernik a generuje data
    for (i = 0; i < NFamilyHouse; i++) {
        BuildingsPointer[i] = new FamilyHouse(i + 100, rand() % 2 + 1, rand() % 100 + 50, rand() % 200 + 30);
    }

    for (i; i < NFamilyHouse + NApartmentHouse; i++) {
        BuildingsPointer[i] = new ApartmentHouse(i + 200, (rand() % 7 + 5), 1);        //to 1 v pocte bytov je placeholder
        BuildingsPointer[i]->SetAp(BuildingsPointer[i]->GetFloors() * (rand() % 4 + 1));       //vynasobi pocet poschodi s generovanym cislom
    }

    for (i; i < NFamilyHouse + NApartmentHouse + NBusinessBuilding; i++) {
        BuildingsPointer[i] = new BusinessBuilding(i + 300, rand() % 10 + 11, rand() % 60 + 1, 0, rand() % 10 + 1);        //0 je placeholder, ostatne vygeneruje
        BuildingsPointer[i]->SetSales(BuildingsPointer[i]->GetEmp() * (rand() % 100 + 10));
    }

    for (i; i < NBuildings; i++) {
        BuildingsPointer[i] = new Factory(i + 400, rand() % 2 + 1, rand() % 300 + 1, 0, rand() % 2000 + 200);      //nula je znova placeholder
        BuildingsPointer[i]->SetSales(BuildingsPointer[i]->GetEmp() * (rand() % 50 + 10));
    }
}

void Street::PrintStreet()
{
    int i;
    std::cout << "Ulica " << NameStreet << " v meste " << NameCity << ": \n";
    std::cout << "Ulicu tvori " << NBuildings << " budov, z toho: \n";
    std::cout << NFamilyHouse << " rodinnych domov, " << NApartmentHouse << " bytovych domov, " << NBusinessBuilding << " kancelarskych budov a " << NFactory << " fabrik. \n \n";



    for (i = 0; i < NBuildings; i++) {
        BuildingsPointer[i]->Print();
    }
}


FamilyHouse::FamilyHouse(int n, int f, int ah, int ag)
{
    Number = n;
    Floors = f;
    AreaHouse = ah;
    AreaGarden = ag;
    //std::cout << "Konstruktor triedy FamilyHouse. \n";
}

void FamilyHouse::Print()
{
    std::cout << "Rodinny dom cislo " << Number << " s " << Floors << " poschodiami, rozholou domu " << AreaHouse << "m^2 a rozlohou zahrady " << AreaGarden << "m^2. \n";
}

ApartmentHouse::ApartmentHouse(int n, int f, int ap)
{
    Number = n;
    Floors = f;
    Ap = ap;
    //std::cout << "Konstruktor triedy ApartmentHouse \n";
}

void ApartmentHouse::Print()
{
    std::cout << "Bytovy dom cislo " << Number << " s " << Floors << " poschodiami a " << Ap << " bytmi. \n";
}

BusinessBuilding::BusinessBuilding(int n, int f, int e, int sa, int se)
{
    Number = n;
    Floors = f;
    Employees = e;
    Sales = sa;
    Sections = se;
    //std::cout << "Konstruktor triedy BusinessBuilding \n";
}

void BusinessBuilding::Print()
{
    std::cout << "Kancelarska budova cislo " << Number << " s " << Floors << " poschodiami, " << Employees << " zamestnancami, priemernym dennym obratom " << Sales << " Eur a " << Sections << " oddeleniami. \n";
}

Factory::Factory(int n, int f, int e, int sa, int a)
{
    Number = n;
    Floors = f;
    Employees = e;
    Sales = sa;
    Area = a;
    //std::cout << "Konstruktor triedy Factory \n";
}

void Factory::Print()
{
    std::cout << "Fabrika cislo " << Number << " s " << Floors << " poschodiami, " << Employees << " zamestnancami, priemernym dennym obratom " << Sales << " Eur a rozlohou vyrobnej haly " << Area << "m^2. \n";
}



//######################################################################################################

int main()
{
    srand((unsigned)time(0));
    Street kosicka("Kosicka", "Bratislava");

    kosicka.GenerateStreet();
    kosicka.PrintStreet();

    return 0;
}

//######################################################################################################