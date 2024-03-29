#include <iostream>
#include <clocale> 

using namespace std;

// Абстрактные травоядные
class Herbivore 
{
public:
    virtual void EatGrass() = 0;
    virtual int GetWeight() const = 0;
};

// Абстрактные хищники
class Carnivore
{
public:
    virtual void Eat(Herbivore* herbivore) = 0;
    virtual int GetPower() const = 0;
};

//Травоядные
class Wildebeest : public Herbivore
{
    int weight = 100; //Антилопа Гну
public:
    void EatGrass() override 
    {
        weight += 10;
        cout << "Антилопа Гну есть траву, вес сейчас: " << weight << endl;
    }
    int GetWeight() const override { return weight; }
};

class Bison : public Herbivore 
{
    int weight = 200; //Бизон
public:
    void EatGrass() override 
    {
        weight += 10;
        cout << "Бизон есть траву, вес сейчас: " << weight << endl;
    }
    int GetWeight() const override { return weight; }
};

class Elk : public Herbivore 
{
    int weight = 300; //Лось
public:
    void EatGrass() override 
    {
        weight += 10;
        cout << "Лось есть траву, вес сейчас: " << weight << endl;
    }
    int GetWeight() const override { return weight; }
};

//Хищники
class Lion : public Carnivore 
{
    int power = 150; //Лев
public:
    void Eat(Herbivore* herbivore) override 
    {
        if (power > herbivore->GetWeight()) 
        {
            power += 10;
            cout << "Лев съедает травоядное, сила сейчас: " << power << endl;
        }
        else 
        {
            power -= 10;
            cout << "Лев не смог съесть травоядное, сила сейчас: " << power << endl;
        }
    }
    int GetPower() const override { return power; }
};

class Wolf : public Carnivore 
{
    int power = 120; //Волк
public:
    void Eat(Herbivore* herbivore) override 
    {
        if (power > herbivore->GetWeight()) 
        {
            power += 10;
            cout << "Волк съедает травоядное, сила сейчас: " << power << endl;
        }
        else {
            power -= 10;
            cout << "Волк не смог съесть травоядное, сила сейчас: " << power << endl;
        }
    }
    int GetPower() const override { return power; }
};

class Tiger : public Carnivore 
{
    int power = 200; //Тигр
public:
    void Eat(Herbivore* herbivore) override 
    {
        if (power > herbivore->GetWeight()) 
        {
            power += 10;
            cout << "Тигр съедает травоядное, сила сейчас: " << power << endl;
        }
        else {
            power -= 10;
            cout << "Тигр не смог съесть травоядное, сила сейчас: " << power << endl;
        }
    }
    int GetPower() const override { return power; }
};

// Абстрактная фабрика
class Continent
{
public:
    virtual Herbivore* CreateHerbivore() = 0;
    virtual Carnivore* CreateCarnivore() = 0;
};

// Фабрики континенты
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

// Мир животных
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