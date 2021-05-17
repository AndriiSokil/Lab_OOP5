/* Створити базовий клас НАСТІЛЬНА ГРА (задається назва). Створити похідні класи ШАШКИ (задаються вага кожної з 24 однотипних фігур, вага дошки для гри розміром 8x8)
та ДОМІНО (задаються вага кожної з 28 однотипних фігур, вага коробки для зберігання). Для заданих прикладів різних комплектів настільних ігор відсортувати їх за
спаданням ваги і обчислити сумарну вагу всіх комплектів . Для перевірки використати масив вказівників на об’єкти базового класу,
яким присвоїти адреси об’єктів похідних класів.*/

#include <iostream>
using namespace std;


class BOARDGAME {

protected:

    string name;

public:
    //конструктор
    BOARDGAME() {
            name = "DEFAULT_NAME";

    }

    //конструктор з параметрами 
    BOARDGAME(const string& name) : name(name) {
    }


    // деструктор

    ~BOARDGAME() {
    }

    string GetName() const {
        return name;
    }

    virtual void SetName(string names) {
        name = names;
    }

    virtual void GetFullInfo() const {
        cout << "\nНазва набору: " << GetName() << "\n";
    }

    virtual double TotalWeight() const {
        return 1;
    }

    virtual void GetFullInfoTV() const {

    }
};



class Shaski : public BOARDGAME
{

private:

    double WeightShaski;
    double WeightBOARD;

public:
    //конструктор
    Shaski() : BOARDGAME() {
        WeightShaski = 1;
        WeightBOARD = 1;
    }
    //конструктор з параметрами 
    Shaski(const string& names, const double& WeightShaski, const double& WeightBOARD) :BOARDGAME(names),
        WeightShaski(WeightShaski), WeightBOARD(WeightBOARD)
    {
    }


    // деструктор
    ~Shaski()
    {
    }



    double GetWeightShaski() const {
        return WeightShaski;
    }

    double GetWeightBOARD() const {
        return WeightBOARD;
    }

    void SetWeightShaski(double WeightS) {
        WeightShaski = WeightS;
    }

    void SetWeightBOARD(double WeightB) {
        WeightBOARD = WeightB;
    }

    double TotalWeightShask() const {
        return WeightShaski * 24;
    }

    double TotalWeight() const {
        return WeightBOARD + WeightShaski * 24;
    }
    void GetFullInfoTV() const {
        cout << "\nВага однієї шашки — " << GetWeightShaski() << "g" <<
            "\nВага дошки — " << GetWeightBOARD() << "g" << "\n\n";

    }

};

class Domino : public BOARDGAME
{

private:

    double WeightDomino;
    double WeightBOX;

public:
    //конструктор
    Domino() : BOARDGAME() {
        WeightDomino = 1;
        WeightBOX = 1;
    }
    //конструктор з параметрами 
    Domino(const string& names, const double& WeightDomino, const double& WeightBOX) :BOARDGAME(names),
        WeightDomino(WeightDomino), WeightBOX(WeightBOX)
    {
    }


    // деструктор
    ~Domino()
    {
 
    }



    double GetWeightDomino() const {
        return WeightDomino;
    }

    double GetWeightBOX() const {
        return WeightBOX;
    }

    void SetWeightDomino(double WeightS) {
        WeightDomino = WeightS;
    }

    void SetWeightBOX(double WeightB) {
        WeightBOX = WeightB;
    }

    double TotalWeightDomino() const {
        return WeightDomino * 28;
    }

    double TotalWeight() const {
        return WeightBOX + WeightDomino * 28;
    }
    void GetFullInfoTV() const {
        cout << "\nВага однієї шашки — " << GetWeightDomino() << "g" <<
            "\nВага коробки — " << GetWeightBOX() << "g" << "\n\n";

    }

};

bool operator > (const BOARDGAME& adv1, const BOARDGAME& adv2) {
    return adv1.TotalWeight() > adv2.TotalWeight();
}

bool operator < (const BOARDGAME& adv1, const BOARDGAME& adv2) {
    return adv1.TotalWeight() < adv2.TotalWeight();
}


int main() {

    system("chcp 1251");

    Shaski Shaski1("Міжнародні шашки", 2.35, 140);
    Shaski Shaski2("Американські шашки", 3, 140);
    Shaski Shaski3("Шашки для басейну", 2.4, 144.5);
    Domino Domino1("Dungeon Master", 5, 300);
    Domino Domino2("Naruto", 1.06, 720);

    BOARDGAME* arrSha[] = { &Shaski1, &Shaski2, &Shaski3 , &Domino1  , &Domino2 };
    BOARDGAME* arrShaTemp;

    int k1, k2, kst, i;
    double sum = 0;
    kst = sizeof(arrSha) / sizeof(*arrSha);

    cout << "\n\t\t********************\n\t\t*Сортування вставки*\n\t\t********************\n\n";
    for (k1 = 1; k1 < kst; k1++) {
        arrShaTemp = *(arrSha + k1);
        k2 = k1 - 1;
        while (k2 >= 0 and (*arrShaTemp > *arrSha[k2])) {
            (arrSha[k2 + 1]) = arrSha[k2];
            k2--;
        }
        arrSha[k2 + 1] = arrShaTemp;
    }

    for (i = 0; i < kst; i++) {
        cout << "№" << i + 1 << " За вагою набору: " << arrSha[i]->TotalWeight() << "g \n";
        sum += arrSha[i]->TotalWeight();
        arrSha[i]->GetFullInfo();
        arrSha[i]->GetFullInfoTV();
    }
    cout << "\t Загальна вага всіх комплектів: " << sum << "g" << "\n\n";

    return 0;
}