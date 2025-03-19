#include "Triangle.h"

int32_t main() {
    Triangle t({ 0, 0 }, { 3, 3 }, { 0, 6 });
    Point points[100];

    cout << "n: ";
    int n;
    cin >> n;

    
    for (int i = 0; i < n; i++)
    {
        cout << "x y: ";
        int u, v;
        cin >> u >> v;
        points[i].x = u;
        points[i].y = v;
    }

    for (int i = 0; i < n; i++) {
        points[i].display();
        if (t.isEdging(points[i]))
            cout << "Mmm, I'm on the edge... just a little more, daddy..." << endl;
        else if (t.contains(points[i]))
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
