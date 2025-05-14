#include "Loli.h"

// -------- Base --------

int Loli::loliCount = 0;

Loli::Loli(string name, int age) : name(name), age(age) {
    loliCount++;
}
Loli::~Loli() {
    cout << name << " vanished into sparkles poof!\n";
}
bool Loli::isLegal() {
    return age >= 18;
}
void Loli::introduce() {
    if (!name.empty() && age > 0)
    {
        cout << "My name is " << name << " and I'm " << age << " years old!\n";
        return;
    }
    cout << "Who am I?\n";
}
void Loli::interact() {}
string Loli::getName() { return name; }
int Loli::getAge() { return age; }

// -------- Lewd --------

LewdLoli::LewdLoli(const string& n, int a, int lvl) : Loli(n, a), lewdnessLevel(lvl) {}
double LewdLoli::getLewdness() { return lewdnessLevel; }
void LewdLoli::introduce() {
    cout << name << ": Ufufu~ You're here to see my new illustration, right?\n";
}
void LewdLoli::interact() {
    lewdnessLevel += 10;
    if (lewdnessLevel > 70) cout << name << " whispers something naughty and winks.\n";
    else if (lewdnessLevel > 30) cout << name << " leans close and smirks teasingly.\n";
    else cout << name << " twirls her pen playfully.\n";
}

// -------- Tsundere --------

TsundereLoli::TsundereLoli(const string& n, int a, int lvl) : Loli(n, a), tsundereLevel(lvl) {}
void TsundereLoli::introduce() {
    cout << name << ": I-I'm not saying this because I like you or anything!\n";
}
void TsundereLoli::interact() {
    if (tsundereLevel > 70) cout << name << " slaps you and blushes!\n";
    else if (tsundereLevel > 30) cout << name << " folds her arms, looking away.\n";
    else cout << name << " mutters shyly.\n";
}

// -------- Magical --------

MagicalLoli::MagicalLoli(const string& n, int a, int mp) : Loli(n, a), magicPower(mp) {}
void MagicalLoli::introduce() {
    cout << name << ": I'll protect everyone with my magic!\n";
}
void MagicalLoli::interact() {
    if (magicPower > 80) cout << name << " casts a brilliant shield spell.\n";
    else if (magicPower > 40) cout << name << " sprinkles healing glitter.\n";
    else cout << name << " hesitates and small sparks fly.\n";
}

// -------- Fire --------

FireLoli::FireLoli(const string& n, int a, int mp) : MagicalLoli(n, a, mp) {}
void FireLoli::introduce() {
    cout << name << ": Explosion magic is the best magic!\n";
}
void FireLoli::interact() {
    if (magicPower > 80) cout << name << " unleashes a massive explosion!\n";
    else if (magicPower > 40) cout << name << " casts a small fireball.\n";
    else cout << name << " coughs up smoke.\n";
}
