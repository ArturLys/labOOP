#include "Triangle.h"
using namespace std;

int32_t main() {
    Triangle t({ 0, 0 }, { 5, 0 }, { 0, 5 });
    vector<Point> points = { {3,1},{4,1},{5,9} };

    for (auto& p : points) {
        p.display();
        if (t.isEdging(p))
            cout << "Mmm, I'm on the edge... just a little more, daddy..." << endl;
        else if (t.contains(p))
            cout << "Mmm, yeah... all the way in~" << endl;
        else 
            cout << "No daddy, it's too big to fit" << endl;
        cout << endl;
    }

    points[0].display();
    if (t.otherContains(points[0]))
        cout << "Oh yes, it's in there tight~" << endl;
    else 
        cout << "Nah bro, it’s not getting in" << endl;

    cout << endl;
    if (t.isDegenerate())
        cout << "Flat is justice! Lolis for the win" << endl;
    else
        cout << "I mean, it's a nice triangle and all, but... where's the charm?" << endl;

}
