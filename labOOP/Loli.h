#pragma once
#include <iostream>
#include <string>
using namespace std;


class Loli {
protected:
    string name;
    int age;
public:
    static int loliCount;
    Loli(string name = "", int age = -1);
    virtual ~Loli();
    bool isLegal();
    virtual void introduce();
    virtual void interact();
    string getName();
    int getAge();
};

// -------------------------

class LewdLoli : public Loli {
private:
    int lewdnessLevel;
public:
    LewdLoli(const string& n, int a, int lvl = 50);
    double getLewdness();
    void introduce() override;
    void interact();
};

// -------------------------

class TsundereLoli : public Loli {
    int tsundereLevel;
public:
    TsundereLoli(const string& n, int a, int lvl = 50);
    void introduce() override;
    void interact();
};

// -------------------------

class MagicalLoli : public Loli {
protected:
    int magicPower;
public:
    MagicalLoli(const string& n, int a, int mp = 75);
    void introduce() override;
    void interact();
};

// -------------------------

class FireLoli : public MagicalLoli {
public:
    FireLoli(const string& n, int a, int mp = 90);
    void introduce() override;
    void interact();
};
