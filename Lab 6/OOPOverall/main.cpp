#include <iostream>
#include <graphics.h>
#include <Point.h>
#include <Line.h>
#include <Shape.h>
#include <Circle.h>
#include <Rectangle.h>

using namespace std;

int main()
{
    int n = 0;
    int shape_type = 0;
    int raduis = 0;
    int color  = 15;

    Point P_center, line_start, line_end, rec_left, rec_right;

    Line line_arr[10];
    Circle circle_arr[10];
    Rectanglee rectanglee_arr[10];

    int line_counter = 0;
    int circle_counter = 0;
    int rectangle_counter = 0;

    cout << "NOTE Shapes Codes: 0 for Line, 1 for Circle, 2 for Rectangle" << endl;
    cout << "NOTE Colors Codes: Blue = 1 , Green = 2, Red = 4 , Yellow = 14" << endl<<endl;
    cout << "Enter the number of shapes: ";
    cin >> n;




    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Type of shape number (" << i + 1 << "): ";
        cin >> shape_type;
        switch (shape_type)
        {
        case 0:
            cout << "Enter the Start point: " << endl;
            cin >> line_start;
            line_arr[line_counter].set_p1(line_start.get_x(), line_start.get_y());

            cout << "Enter the End point: " << endl;
            cin >> line_end;
            line_arr[line_counter].set_p2(line_end.get_x(), line_end.get_y());

            cout<< "Enter the color: ";
            cin >> color ;
            line_arr[line_counter].setColor(color);
            line_counter++;
            break;
        case 1:
            cout << "Enter the center point: " << endl;
            cin >> P_center;
            circle_arr[circle_counter].setCenter(P_center.get_x() , P_center.get_y());

            cout << "Enter the raduis: " << endl;
            cin >> raduis;
            circle_arr[circle_counter].setRaduis(raduis);

            // Check if the circle is inside the window
           /*if (P_center.get_x() - raduis >= 0 && P_center.get_x() + raduis <= getmaxx() &&
                P_center.get_y() - raduis >= 0 && P_center.get_y() + raduis <= getmaxy())
            {
                circle_arr[circle_counter].setCenter(P_center.get_x(), P_center.get_y());
                circle_arr[circle_counter].setRaduis(raduis);

                cout << "Enter the color: ";
                cin >> color;
                circle_arr[circle_counter].setColor(color);

                circle_counter++;
            }
            else
            {
                cout << "Circle is outside the window. Please enter valid coordinates." << endl;
                i--; // Decrement i to repeat the current iteration
            }*/
            cout<< "Enter the color: ";
            cin >> color ;
            circle_arr[circle_counter].setColor(color);
            circle_counter++;
            break;
        case 2:
            cout << "Enter the Top Left point: " << endl;
            cin >> rec_left;
            rectanglee_arr[rectangle_counter].set_p1(rec_left.get_x() , rec_left.get_y());

            cout << "Enter the Bottom Right point: " << endl;
            cin >> rec_right;
            rectanglee_arr[rectangle_counter].set_p2(rec_right.get_x() , rec_right.get_y());

            cout<< "Enter the color: ";
            cin >> color ;
            rectanglee_arr[rectangle_counter].setColor(color);

            rectangle_counter++;
            break;
        }
    }
    initwindow(600, 400, "Shapes");
    // Draw all lines
    for (int i = 0; i < line_counter; i++)
    {
        setcolor(line_arr[i].getColor());
        line_arr[i].Draw();
    }
    for (int i = 0; i < circle_counter; i++)
    {
        setcolor(circle_arr[i].getColor());
        circle_arr[i].Draw();
    }
    for (int i = 0; i < rectangle_counter; i++)
    {
        setcolor(rectanglee_arr[i].getColor());
        rectanglee_arr[i].Draw();
    }
     getch();

    // Close the graphics window
    closegraph();

    return 0;
}
