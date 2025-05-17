#include "Loli.h"

int main()
{
    Loli *squad[] = {
        new LewdLoli("Sagiri Izumi", 13, 60),
        new TsundereLoli("Kagami Hiiragi", 17, 75),
        new MagicalLoli("Madoka Kaname", 14, 80),
        new FireLoli("Megumin", 15, 90),
        new Loli("Shinobu Oshino", 598),
        new ChefLoli("Mikakage", 16, 70, 60, 50),
        new ElementalLoli("Beatrice", 400, 90, 50),
        new DendroLoli("Nahida", 500, 69)};

    for (auto *loli : squad)
    {
        loli->introduce();
        loli->interact();
        if (loli->isLegal())
            cout << loli->getName() << " is legal\n";
        cout << "- - -\n";
    }

    cout << "\nLolis counted " << Loli::count << " times\n\n";

    for (auto *loli : squad)
        delete loli;

    return 0;
}
