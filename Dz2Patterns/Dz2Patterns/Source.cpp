#include <iostream>
#include <clocale> 

using namespace std;

// ����������� ����������
class Herbivore 
{
public:
    virtual void EatGrass() = 0;
    virtual int GetWeight() const = 0;
};

// ����������� �������
class Carnivore
{
public:
    virtual void Eat(Herbivore* herbivore) = 0;
    virtual int GetPower() const = 0;
};

//����������
class Wildebeest : public Herbivore
{
    int weight = 100; //�������� ���
public:
    void EatGrass() override 
    {
        weight += 10;
        cout << "�������� ��� ���� �����, ��� ������: " << weight << endl;
    }
    int GetWeight() const override { return weight; }
};

class Bison : public Herbivore 
{
    int weight = 200; //�����
public:
    void EatGrass() override 
    {
        weight += 10;
        cout << "����� ���� �����, ��� ������: " << weight << endl;
    }
    int GetWeight() const override { return weight; }
};

class Elk : public Herbivore 
{
    int weight = 300; //����
public:
    void EatGrass() override 
    {
        weight += 10;
        cout << "���� ���� �����, ��� ������: " << weight << endl;
    }
    int GetWeight() const override { return weight; }
};

//�������
class Lion : public Carnivore 
{
    int power = 150; //���
public:
    void Eat(Herbivore* herbivore) override 
    {
        if (power > herbivore->GetWeight()) 
        {
            power += 10;
            cout << "��� ������� ����������, ���� ������: " << power << endl;
        }
        else 
        {
            power -= 10;
            cout << "��� �� ���� ������ ����������, ���� ������: " << power << endl;
        }
    }
    int GetPower() const override { return power; }
};

class Wolf : public Carnivore 
{
    int power = 120; //����
public:
    void Eat(Herbivore* herbivore) override 
    {
        if (power > herbivore->GetWeight()) 
        {
            power += 10;
            cout << "���� ������� ����������, ���� ������: " << power << endl;
        }
        else {
            power -= 10;
            cout << "���� �� ���� ������ ����������, ���� ������: " << power << endl;
        }
    }
    int GetPower() const override { return power; }
};

class Tiger : public Carnivore 
{
    int power = 200; //����
public:
    void Eat(Herbivore* herbivore) override 
    {
        if (power > herbivore->GetWeight()) 
        {
            power += 10;
            cout << "���� ������� ����������, ���� ������: " << power << endl;
        }
        else {
            power -= 10;
            cout << "���� �� ���� ������ ����������, ���� ������: " << power << endl;
        }
    }
    int GetPower() const override { return power; }
};

// ����������� �������
class Continent
{
public:
    virtual Herbivore* CreateHerbivore() = 0;
    virtual Carnivore* CreateCarnivore() = 0;
};

// ������� ����������
class Africa : public Continent 
{
public:
    Herbivore* CreateHerbivore() override 
    {
        return new Wildebeest();
    }
    Carnivore* CreateCarnivore() override 
    {
        return new Lion();
    }
};

class NorthAmerica : public Continent 
{
public:
    Herbivore* CreateHerbivore() override 
    {
        return new Bison();
    }
    Carnivore* CreateCarnivore() override 
    {
        return new Wolf();
    }
};

class Eurasia : public Continent
{
public:
    Herbivore* CreateHerbivore() override 
    {
        return new Elk();
    }
    Carnivore* CreateCarnivore() override 
    {
        return new Tiger();
    }
};

// ��� ��������
class AnimalWorld 
{
    Herbivore* herbivore;
    Carnivore* carnivore;
public:
    AnimalWorld(Continent* continent) 
    {
        herbivore = continent->CreateHerbivore();
        carnivore = continent->CreateCarnivore();
    }
    void RunLifeCycle() 
    {
        herbivore->EatGrass();
        carnivore->Eat(herbivore);
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    Continent* africa = new Africa();
    AnimalWorld world(africa);
    world.RunLifeCycle();

    Continent* northAmerica = new NorthAmerica();
    AnimalWorld worldNA(northAmerica);
    worldNA.RunLifeCycle();

    Continent* eurasia = new Eurasia();
    AnimalWorld worldEU(eurasia);
    worldEU.RunLifeCycle();

    delete africa;
    delete northAmerica;
    delete eurasia;

    return 0;
}