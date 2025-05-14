#include "Loli.h"

using namespace std;

int32_t main() {
    Loli* squad[] = {
           new LewdLoli("Sagiri Izumi", 13, 60),
           new TsundereLoli("Kagami Hiiragi", 17, 75),
           new MagicalLoli("Madoka Kaname", 14, 80),
           new FireLoli("Megumin", 15, 90),
           new Loli("Shinobu Oshino", 598)
    };

    for (auto* loli : squad) {
        loli->introduce();
        loli->interact();
        if (loli->isLegal())
            cout << loli->getName() << " is legal\n";
        cout << "- - -\n";
    }

    cout << "\nTotal lolis constructed: " << Loli::loliCount << "\n\n";

    for (auto* loli : squad)
        delete loli;


    return 0;
}