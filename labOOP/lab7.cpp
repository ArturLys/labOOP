#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Base class
class Loli {
    string name;
    int age;
public:
    Loli(string n, int a) : name(n), age(a) {}
    void interact() {
        cout << name << " has just had an interesting interaction\n";
    }
};

// Proxy
class LoliProxy {
    unique_ptr<Loli> realLoli;
    string name;
    int age;
public:
    LoliProxy(string n, int a) : name(n), age(a) {}
    void interact(int userAge) {
        if (userAge < 18) {
            if (!realLoli) realLoli = make_unique<Loli>(name, age);
            realLoli->interact();
        } else {
            cout << "Access denied. You're too creepy to interact with lolis\n";
        }
    }
};

// Singleton
class LoliAccessManager {
private:
    static unique_ptr<LoliAccessManager> instance;
    LoliAccessManager() {}
public:
    static LoliAccessManager& getInstance() {
        if (!instance) instance = make_unique<LoliAccessManager>();
        return *instance;
    }

    void requestLoli(const string& name, int age, int userAge) {
        LoliProxy proxy(name, age);
        proxy.interact(userAge);
    }

    LoliAccessManager(const LoliAccessManager&) = delete;
    LoliAccessManager& operator=(const LoliAccessManager&) = delete;
};

unique_ptr<LoliAccessManager> LoliAccessManager::instance = nullptr;



int32_t main() {
    auto& manager = LoliAccessManager::getInstance();

    manager.requestLoli("Vanilla", 12, 21);  // Rejected
    manager.requestLoli("Shiro", 11, 17); // Allowed
}
