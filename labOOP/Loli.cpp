#include "Loli.h"

// -------- Base --------

int Loli::count = 0;

Loli::Loli(string name, int age) : name(name), age(age) { count++; }
Loli::~Loli()
{
    cout << name << " vanished into sparkles poof!\n";
}
bool Loli::isLegal() { return age >= 18; }
void Loli::introduce()
{
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

LewdLoli::LewdLoli(const string &n, int a, int lvl)
    : Loli(n, a), lewdnessLevel(lvl) {}
double LewdLoli::getLewdness() { return lewdnessLevel; }
void LewdLoli::introduce()
{
    cout << name << ": Ufufu~ You're here to see my new illustration, right?\n";
}
void LewdLoli::interact()
{
    lewdnessLevel += 10;
    if (lewdnessLevel > 70)
        cout << name << " whispers something naughty and winks.\n";
    else if (lewdnessLevel > 30)
        cout << name << " leans close and smirks teasingly.\n";
    else
        cout << name << " twirls her pen playfully.\n";
}

// -------- Tsundere --------

TsundereLoli::TsundereLoli(const string &n, int a, int lvl)
    : Loli(n, a), tsundereLevel(lvl) {}
void TsundereLoli::introduce()
{
    cout << name << ": I-I'm not saying this because I like you or anything!\n";
}
void TsundereLoli::interact()
{
    if (tsundereLevel > 70)
        cout << name << " slaps you and blushes!\n";
    else if (tsundereLevel > 30)
        cout << name << " folds her arms, looking away.\n";
    else
        cout << name << " mutters shyly.\n";
}

// -------- Magical --------

MagicalLoli::MagicalLoli(const string &n, int a, int mp)
    : Loli(n, a), magicPower(mp) {}
void MagicalLoli::introduce()
{
    cout << name << ": I'll protect everyone with my magic!\n";
}
void MagicalLoli::interact()
{
    if (magicPower > 80)
        cout << name << " casts a brilliant shield spell.\n";
    else if (magicPower > 40)
        cout << name << " sprinkles healing glitter.\n";
    else
        cout << name << " hesitates and small sparks fly.\n";
}

// -------- Fire --------

FireLoli::FireLoli(const string &n, int a, int mp)
    : Loli(n, a), MagicalLoli(n, a, mp) {}
void FireLoli::introduce()
{
    cout << name << ": Explosion magic is the best magic!\n";
}
void FireLoli::interact()
{
    if (magicPower > 80)
        cout << name << " unleashes a massive explosion!\n";
    else if (magicPower > 40)
        cout << name << " casts a small fireball.\n";
    else
        cout << name << " coughs up smoke.\n";
}

// -------- Dendro --------

DendroLoli::DendroLoli(const string &n, int a, int mp)
    : Loli(n, a), MagicalLoli(n, a, mp) {}
void DendroLoli::introduce()
{
    cout << name << ": I use plant magic to support and protect.\n";
}
void DendroLoli::interact()
{
    if (magicPower > 80)
        cout << name << " creates a sturdy vine wall.\n";
    else if (magicPower > 50)
        cout << name << " tangles foes in creeping vines.\n";
    else
        cout << name << " coaxes a single flower to bloom.\n";
}

// -------- Elemental --------

ElementalLoli::ElementalLoli(const string &n, int a, int mp, int pp)
    : Loli(n, a),
      MagicalLoli(n, a, mp),
      FireLoli(n, a, mp),
      DendroLoli(n, a, pp),
      yinPower((mp * mp + pp * 42) / (mp + pp + 1))
{
}
void ElementalLoli::introduce()
{
    cout << name << ": I wield Yin magic to twist space and shadow.\n";
}
void ElementalLoli::interact()
{
    if (yinPower > 80)
        cout << name << " rips open a void portal.\n";
    if (yinPower > 50 && yinPower <= 80)
        cout << name << " spears dark stakes from beneath.\n";
    if (yinPower <= 50)
        cout << name << " whispers a soft void chant.\n";
}

// -------- Chef --------

ChefLoli::ChefLoli(const string &n, int a, int lewdLvl,
                   int tsunLvl, int magicPwr)
    : Loli(n, a),
      LewdLoli(n, a, lewdLvl),
      TsundereLoli(n, a, tsunLvl),
      MagicalLoli(n, a, magicPwr)
{
}
void ChefLoli::introduce()
{
    cout << name << ": I'm a chef who can burn and flirt at the same time.\n";
}
void ChefLoli::interact()
{
    if (lewdnessLevel > 60)
        cout << name << " winks and adds extra spice.\n";
    if (tsundereLevel > 50)
        cout << name << " grumbles: 'Don't overcook it, idiot.'\n";
    if (magicPower > 70)
        cout << name << " ignites the pan with a spark.\n";
    if (lewdnessLevel <= 60 && tsundereLevel <= 50 && magicPower <= 70)
        cout << name << " timidly flips a pancake with a tiny flame.\n";
}
ChefLoli::~ChefLoli()
{
    cout << name << " storms out, leaving dishes undone.\n";
}
