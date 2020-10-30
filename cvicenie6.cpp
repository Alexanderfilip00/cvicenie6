#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <stdlib.h>



class FamilyHouse{
protected:
    int Number;
    int Floors;
    float AreaHouse;
    float AreaGarden;
public:
    FamilyHouse() { std::cout << "Prazdny kostruktor objektu typu FamilyHouse.\n"; };
    FamilyHouse(int N, int F, float AH, float AG);
    //FamilyHouse(int N, int F, float AH, float AG, std::string NS, std::string NC);
    ~FamilyHouse() { std::cout << "Destruktor objektu typu FamilyHouse.\n"; };
    void Print();
    
    void SetNumber(int n) { Number = n; };
};

class ApartmentHouse{
protected:
    int Number;
    int Floors;
    int Ap;
public:
    ApartmentHouse() { std::cout << "Prazdny kostruktor objektu typu ApartmentHouse.\n"; };
    ApartmentHouse(int N, int F, int A);
    //ApartmentHouse(int N, int F, int A, std::string NS, std::string NC);
    ~ApartmentHouse() { std::cout << "Destruktor objektu typu ApartmentHouse.\n"; };
    void Print();
};

class BusinessBuilding{
protected:
    int Number;
    int Floors;
    int Employees;
    float Sales;
    int Sections;
public:
    BusinessBuilding() { std::cout << "Prazdny kostruktor objektu typu BusinessBuilding.\n"; };
    BusinessBuilding(int N, int F, int E, float Sa, int Se);
    //BusinessBuilding(int N, int F, int E, float Sa, int Se, std::string NS, std::string NC);
    ~BusinessBuilding() { std::cout << "Destruktor objektu typu BusinessBuilding.\n"; };
    void Print();
};

class Factory{
protected:
    int Number;
    int Floors;
    int Employees;
    float Sales;
    float Area;
public:
    Factory() { std::cout << "Prazdny kostruktor objektu typu Factory.\n"; };
    Factory(int N, int F, int E, float Sa, float A);
    //Factory(int N, int F, int E, float Sa, float A, std::string NS, std::string NC);
    ~Factory() { std::cout << "Destruktor objektu typu Factory.\n"; };
    void Print();   
};

class Street : private FamilyHouse, private ApartmentHouse, private BusinessBuilding, private Factory {
private:
    FamilyHouse* FamHouses;
    ApartmentHouse* AparHouses;
    BusinessBuilding* BusiBuilds;
    Factory* Facts;

    int NFamHouses;

protected:
    std::string NameStreet;
    std::string NameCity;

public:
    Street() { std::cout << "Prazdny konstruktor objektu typu Street.\n"; };
    Street(std::string S, std::string C);
    ~Street() { std::cout << "Destruktor objektu typu Street.\n"; };
    void Generate_FH();
    void Print_FH();
    //void Generate_AH() { NAparHouses = rand() % 26; };
    //void Generate_BB() { NBusiBuilds = rand() % 15; };
    //void Generate_FA() { NFacts = rand() % 5; };
};

//######################################################################################################

int main()
{
    srand((unsigned)time(0));
    Street kosicka("Kosicka", "Bratislava");
    kosicka.Generate_FH();
    kosicka.Print_FH();
    return 0;
}

//######################################################################################################

Street::Street(std::string S, std::string C)
{
    NameStreet = S;
    NameCity = C;
    std::cout << "Vytvara sa objekt typu Street.\n";
}

void Street::Generate_FH()
{
   int i;
   NFamHouses = rand() % 50;
   FamHouses = new FamilyHouse[NFamHouses];
   for (i = 0; i < NFamHouses; i++) {
       FamHouses[i].SetNumber(i + 100);
   }
}

void Street::Print_FH()
{
    int i;
    for (i = 0; i < NFamHouses; i++) {
        FamHouses[i].Print();
    }
}


FamilyHouse::FamilyHouse(int N, int F, float AH, float AG)
{
    Number = N;
    Floors = F;
    AreaHouse = AH;
    AreaGarden = AG;
    std::cout << "Konstruktor objektu typu FamilyHouse.\n";
}

void FamilyHouse::Print()
{
    std::cout << "Rodinny dom cislo " << Number << " s " << Floors << " poschodiami, rozholou domu " << AreaHouse << "m^2 a rozlohou zahrady " << AreaGarden << "m^2. \n";
}

ApartmentHouse::ApartmentHouse(int N, int F, int A)
{
    Number = N;
    Floors = F;
    Ap = A;
    std::cout << "Konstruktor objektu typu ApartmentHouse.\n";
}

void ApartmentHouse::Print()
{
    std::cout << "Bytovy dom cislo " << Number << " s " << Floors << " poschodiami a " << Ap << " bytmi. \n";
}

BusinessBuilding::BusinessBuilding(int N, int F, int E, float Sa, int Se)
{
    Number = N;
    Floors = F;
    Employees = E;
    Sales = Sa;
    Sections = Se;
    std::cout << "Konstruktor objektu typu BusinessBuilding.\n";
}

void BusinessBuilding::Print()
{
    std::cout << "Kancelarska budova cislo " << Number << " s " << Floors << " poschodiami, " << Employees << " zamestnancami, priemernym dennym obratom " << Sales << " Eur a " << Sections << " oddeleniami. \n";
}

Factory::Factory(int N, int F, int E, float Sa, float A)
{
    Number = N;
    Floors = F;
    Employees = E;
    Sales = Sa;
    Area = A;
    std::cout << "Konstruktor objektu typu Factory.\n";
}

void Factory::Print()
{
    std::cout << "Fabrika cislo " << Number << " s " << Floors << " poschodiami, " << Employees << " zamestnancami, priemernym dennym obratom " << Sales << " Eur a rozlohou vyrobnej haly " << Area << "m^2. \n";
}
