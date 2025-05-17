#pragma once
#include <iostream>
#include <string>
using namespace std;

class Loli
{
protected:
    string name;
    int age;

public:
    static int count;
    Loli(string name = "", int age = -1);
    virtual ~Loli();
    bool isLegal();
    virtual void introduce();
    virtual void interact();
    string getName();
    int getAge();
};

// -------------------------

class LewdLoli : virtual public Loli
{
protected:
    int lewdnessLevel;

public:
    LewdLoli(const string &n, int a, int lvl = 50);
    double getLewdness();
    void introduce() override;
    void interact();
};

// -------------------------

class TsundereLoli : virtual public Loli
{
protected:
    int tsundereLevel;

public:
    TsundereLoli(const string &n, int a, int lvl = 50);
    void introduce() override;
    void interact();
};

// -------------------------

class MagicalLoli : virtual public Loli
{
protected:
    int magicPower;

public:
    MagicalLoli(const string &n, int a, int mp = 75);
    void introduce() override;
    void interact();
};

// -------------------------

class FireLoli : public virtual MagicalLoli
{
public:
    FireLoli(const string &n, int a, int mp = 90);
    void introduce() override;
    void interact() override;
};

// -------------------------
class DendroLoli : public virtual MagicalLoli
{
public:
    DendroLoli(const string &n, int a, int mp = 50);
    void introduce() override;
    void interact() override;
};

// -------------------------

class ElementalLoli : virtual public FireLoli,
                      virtual public DendroLoli
{
protected:
    int yinPower;

public:
    ElementalLoli(const string &n, int a, int mp = 90, int pp = 50);
    void introduce() override;
    void interact() override;
};

// -------------------------

class ChefLoli : public LewdLoli,
                 public TsundereLoli,
                 public MagicalLoli
{
public:
    ChefLoli(const string &n, int a,
             int lewdLvl = 40, int tsunLvl = 60, int magicPwr = 50);
    void introduce() override;
    void interact() override;
    ~ChefLoli();
};
