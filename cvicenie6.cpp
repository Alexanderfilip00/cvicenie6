#include <string>
#include <fstream>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <ctime>
#include <stdlib.h>

class Street {

protected:
    int Number;
    int Floors;

    int NFamilyHouse; 
    int NApartmentHouse;
    int NBusinessBuilding;
    int NFactory;

    std::string NameStreet;
    std::string NameCity;
    void SetStreetName(std::string SN) { NameStreet = SN; };
    void SetCityName(std::string CN) { NameCity = CN; };
 
public:
    Street() {};
    Street(std::string S, std::string C) { NameStreet = S; NameCity = C; };
    virtual ~Street();
    virtual void Print() {};
    void GenerateStreet();
    void PrintStreet();
    
    //metody k FamilyHouse
    void GenerateFH();
    void PrintFH();
    Street** FHPointer;

    //metody k ApartmentHouse
    void GenerateAH();
    void PrintAH();
    Street** AHPointer;
    virtual void SetAp(int a) {};

    //metody k BusinessBuilding
    void GenerateBB();
    void PrintBB();
    Street** BBPointer;
    virtual void SetSales(int s) {};        //tato procedura je vyuzita aj pre Factory
    virtual int GetEmp() { return 0; };     //tato funkcia tiez

    //metody k Factory
    void GenerateFA();
    void PrintFA();
    Street** FAPointer;
};



class FamilyHouse: public Street{
private:
    int AreaHouse;
    int AreaGarden;
public:
    FamilyHouse(int n, int f, int ah, int ag);
    FamilyHouse() {std::cout << "Prazdny kostruktor objektu typu FamilyHouse.\n"; };        //toto ani netreba
    ~FamilyHouse() {};  // { std::cout << "Destruktor objektu typu FamilyHouse.\n"; };
    void Print();
};

class ApartmentHouse : public Street {
private:
    int Ap;
public:
    ApartmentHouse(int n, int f, int ap);
    ApartmentHouse() { std::cout << "Prazdny kostruktor objektu typu ApartmentHouse.\n"; };     //toto ani netreba
    ~ApartmentHouse() {};  //{ std::cout << "Destruktor objektu typu ApartmentHouse.\n"; };
    void Print();
    void SetAp(int a) { Ap = a; }; 
};

class BusinessBuilding : public Street {
private:
    int Employees;
    int Sales;
    int Sections;
public:
    BusinessBuilding(int n, int f, int e, int sa, int se);
    BusinessBuilding() { std::cout << "Prazdny kostruktor objektu typu BusinessBuilding.\n"; };         //toto ani netreba
    ~BusinessBuilding() {};  // { std::cout << "Destruktor objektu typu BusinessBuilding.\n"; };
    void Print();

    int GetEmp() { return Employees; };
    void SetSales(int sa) { Sales = sa; };
};

class Factory : public Street {
private:
    
    int Employees;
    int Sales;
    int Area;
public:
    Factory(int n, int f, int e, int sa, int a);
    Factory() { std::cout << "Prazdny kostruktor objektu typu Factory.\n"; };       //toto ani netreba
    ~Factory() {};  // { std::cout << "Destruktor objektu typu Factory.\n"; };
    void Print();  

    int GetEmp() { return Employees; };
    void SetSales(int sa) { Sales = sa; };
};


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


Street::~Street()
{
    int i;
    for (i = 0; i < NFamilyHouse; i++) {
        delete FHPointer[i];
    }

    for (i = 0; i < NApartmentHouse; i++) {
        delete AHPointer[i];
    }

    for (i = 0; i < NBusinessBuilding; i++) {
        delete BBPointer[i];
    }

    for (i = 0; i < NFactory; i++) {
        delete FAPointer[i];
    }

    delete[] FHPointer;
    delete[] AHPointer;
    delete[] BBPointer;
    delete[] FAPointer;
    
    //std::cout << "Destruktor objektu typu STREET. \n";
}

void Street::GenerateStreet()
{
    GenerateFH();
    GenerateAH();
    GenerateBB();
    GenerateFA();
}

void Street::PrintStreet()
{
    std::cout << "Ulica " << NameStreet << " v meste " << NameCity << ": \n";
    std::cout << std::endl;
    PrintFH();
    std::cout << std::endl;
    PrintAH();
    std::cout << std::endl;
    PrintBB();
    std::cout << std::endl;
    PrintFA();
}

void Street::GenerateFH()
{
    NFamilyHouse = rand() % 50 + 1; 
    FHPointer = new Street * [NFamilyHouse];
    int i;

    for (i = 0; i < NFamilyHouse; i++) {
        FHPointer[i] = new FamilyHouse(i+100, rand() % 2 + 1, rand() % 100 + 50, rand() % 200 + 30);
    }
}

void Street::PrintFH()
{
    int i;
    for (i = 0; i < NFamilyHouse; i++) {
        FHPointer[i]->Print();
    }
}

void Street::GenerateAH()
{
    NApartmentHouse = rand() % 20 + 1;      //vygeeneruje pocet panelakov
    AHPointer = new Street * [NApartmentHouse];
    int i;

    for (i = 0; i < NApartmentHouse; i++) {
        AHPointer[i] = new ApartmentHouse(i + 200, (rand() % 7 + 5), 1);        //to 1 v pocte bytov je placeholder
        AHPointer[i]->SetAp(AHPointer[i]->Floors * (rand() % 4 + 1));       //vynasobi pocet poschodi s generovanym cislom
    }

}

void Street::PrintAH()
{
    int i;
    for (i = 0; i < NApartmentHouse; i++) {
        AHPointer[i]->Print();
    }
}

void Street::GenerateBB()
{
    NBusinessBuilding = rand() % 10 + 1;      //vygeeneruje pocet business budov
    BBPointer = new Street * [NBusinessBuilding];
    int i;

    for (i = 0; i < NBusinessBuilding; i++) {
        BBPointer[i] = new BusinessBuilding(i + 300, rand() % 10 + 11, rand() % 60 + 1, 0, rand() % 10 + 1);        //0 je placeholder, ostatne vygeneruje
        BBPointer[i]->SetSales(BBPointer[i]->GetEmp() * (rand() % 100 + 10));
    }
}

void Street::PrintBB()
{
    int i;
    for (i = 0; i < NBusinessBuilding; i++) {
        BBPointer[i]->Print();
    }
}

void Street::GenerateFA()
{
    NFactory = rand() % 5 + 1;  //vygeneruje pocet tovarni
    FAPointer = new Street * [NFactory];
    int i;

    for (i = 0; i < NFactory; i++) {
        FAPointer[i] = new Factory(i + 400, rand() % 2 + 1, rand() % 300 + 1, 0, rand() % 2000 + 200);      //nula je znova placeholder
        FAPointer[i]->SetSales(FAPointer[i]->GetEmp() * (rand() % 50 + 10));
    }
}

void Street::PrintFA()
{
    int i;
    for (i = 0; i < NFactory; i++) {
        FAPointer[i]->Print();
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
