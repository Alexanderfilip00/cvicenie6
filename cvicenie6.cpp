#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <stdlib.h>



class FamilyHouse{
private:
    int Number;
    int Floors;
    int AreaHouse;
    int AreaGarden;
protected:
    FamilyHouse() {}; //  { std::cout << "Prazdny kostruktor objektu typu FamilyHouse.\n"; };
    ~FamilyHouse() {}; //  { std::cout << "Destruktor objektu typu FamilyHouse.\n"; };
    void Print();
    
    void SetNumber(int n) { Number = n; };
    void SetFloors(int f) { Floors = f; };
    void SetAreaHouse(int ah) { AreaHouse = ah; };
    void SetAreaGarden(int ag) { AreaGarden = ag; };
};

class ApartmentHouse{
private:
    int Number;
    int Floors;
    int Ap;
protected:
    ApartmentHouse() {}; //  { std::cout << "Prazdny kostruktor objektu typu ApartmentHouse.\n"; };
    ~ApartmentHouse() {}; //  { std::cout << "Destruktor objektu typu ApartmentHouse.\n"; };
    void Print();

    void SetNumber(int n) { Number = n; };
    void SetFloors(int f) { Floors = f; };
    int GetFloors() { return Floors; };
    void SetAp(int a) { Ap = a; };
};

class BusinessBuilding{
private:
    int Number;
    int Floors;
    int Employees;
    int Sales;
    int Sections;
protected:
    BusinessBuilding() {}; // { std::cout << "Prazdny kostruktor objektu typu BusinessBuilding.\n"; };
    ~BusinessBuilding() {}; //  { std::cout << "Destruktor objektu typu BusinessBuilding.\n"; };
    void Print();

    void SetNumber(int n) { Number = n; };
    void SetFloors(int f) { Floors = f; };
    void SetEmployees(int e) { Employees = e; };
    int GetEmployees() { return Employees; };
    void SetSales(int sa) { Sales = sa; };
    void SetSections(int se) { Sections = se; };
};

class Factory{
private:
    int Number;
    int Floors;
    int Employees;
    int Sales;
    int Area;
protected:
    Factory() {}; //{ std::cout << "Prazdny kostruktor objektu typu Factory.\n"; };
    ~Factory() {}; // { std::cout << "Destruktor objektu typu Factory.\n"; };
    void Print();  

    void SetNumber(int n) { Number = n; };
    void SetFloors(int f) { Floors = f; };
    void SetEmployees(int e) { Employees = e; };
    int GetEmployees() { return Employees; };
    void SetSales(int sa) { Sales = sa; };
    void SetArea(int a) { Area = a; };

};

class Street : public FamilyHouse, public ApartmentHouse, public BusinessBuilding, public Factory {
private:
    FamilyHouse* FamHouses;
    ApartmentHouse* AparHouses;
    BusinessBuilding* BusiBuilds;
    Factory* Facts;

    int NFamHouses;
    int NAparHouses;
    int NBusiBuilds;
    int NFacts;
    std::string NameStreet;
    std::string NameCity;

    void GenerateFH();
    void PrintFH();
    void GenerateAH();
    void PrintAH();
    void GenerateBB();
    void PrintBB();
    void GenerateFA();
    void PrintFA();

public:
    Street(std::string S, std::string C) { NameStreet = S; NameCity = C; };
    ~Street();
    void GenerateStreet();
    void PrintStreet();
    

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
    delete[] FamHouses;
    delete[] AparHouses;
    delete[] BusiBuilds;
    delete[] Facts;
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


void Street::GenerateAH()
{
    int i;
    NAparHouses = rand() % 20 + 1;
    AparHouses = new ApartmentHouse[NAparHouses];
    for (i = 0; i < NAparHouses; i++) {
        AparHouses[i].SetNumber(i + 200);
        AparHouses[i].SetFloors(rand() % 7 + 5);
        AparHouses[i].SetAp( AparHouses[i].GetFloors() * (rand() % 4 + 2) );        //vygeneruje pocet bytov na jednom poschodi a vynasobi ho poctom poschodi
    }
}

void Street::PrintAH()
{
    int i;
    for (i = 0; i < NAparHouses; i++) {
        AparHouses[i].Print();
    }
}

void Street::GenerateBB()
{
    int i;
    NBusiBuilds = rand() % 10 + 1;
    BusiBuilds = new BusinessBuilding[NBusiBuilds];
    for (i = 0; i < NBusiBuilds; i++) {
        BusiBuilds[i].SetNumber(i + 300);
        BusiBuilds[i].SetFloors(rand() % 10 + 11);
        BusiBuilds[i].SetEmployees(rand() % 60 + 1);
        BusiBuilds[i].SetSales(BusiBuilds[i].GetEmployees() * (rand() % 100 + 10) );     //vygeneruje obrat za 1 zamestnanca a vynasobi poctom zamestnancov
        BusiBuilds[i].SetSections(rand() % 10 + 1);
    }
}

void Street::PrintBB()
{
    int i;
    for (i = 0; i < NBusiBuilds; i++) {
        BusiBuilds[i].Print();
    }
}

void Street::GenerateFA()
{
    int i;
    NFacts = rand() % 5 + 1;
    Facts = new Factory[NFacts];
    for (i = 0; i < NFacts; i++) {
        Facts[i].SetNumber(i + 400);
        Facts[i].SetFloors(rand() % 2 + 1);
        Facts[i].SetEmployees(rand() % 300 + 1);
        Facts[i].SetSales(Facts[i].GetEmployees() * (rand() % 50 + 10));     //vygeneruje obrat za 1 zamestnanca a vynasobi poctom zamestnancov
        Facts[i].SetArea(rand() % 2000 + 200);
    }
}

void Street::PrintFA()
{
    int i;
    for (i = 0; i < NFacts; i++) {
        Facts[i].Print();
    }
}

void Street::GenerateFH()
{
   int i;
   NFamHouses = rand() % 50 + 1;
   FamHouses = new FamilyHouse[NFamHouses];
   for (i = 0; i < NFamHouses; i++) {
       FamHouses[i].SetNumber(i + 100);
       FamHouses[i].SetFloors(rand() % 3 + 1);
       FamHouses[i].SetAreaHouse(rand() % 150 + 50);
       FamHouses[i].SetAreaGarden(rand() % 300 + 20);
   }
}

void Street::PrintFH()
{
    int i;
    for (i = 0; i < NFamHouses; i++) {
        FamHouses[i].Print();
    }
}

void FamilyHouse::Print()
{
    std::cout << "Rodinny dom cislo " << Number << " s " << Floors << " poschodiami, rozholou domu " << AreaHouse << "m^2 a rozlohou zahrady " << AreaGarden << "m^2. \n";
}

void ApartmentHouse::Print()
{
    std::cout << "Bytovy dom cislo " << Number << " s " << Floors << " poschodiami a " << Ap << " bytmi. \n";
}

void BusinessBuilding::Print()
{
    std::cout << "Kancelarska budova cislo " << Number << " s " << Floors << " poschodiami, " << Employees << " zamestnancami, priemernym dennym obratom " << Sales << " Eur a " << Sections << " oddeleniami. \n";
}

void Factory::Print()
{
    std::cout << "Fabrika cislo " << Number << " s " << Floors << " poschodiami, " << Employees << " zamestnancami, priemernym dennym obratom " << Sales << " Eur a rozlohou vyrobnej haly " << Area << "m^2. \n";
}
