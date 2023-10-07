
#ifndef Point_h_ENSF337

#define Point_h_ENSF337

struct point
{
    double x ;      // x coordinate for point in a Cartesian coordinate system
    double y;       // y coordinate for point in a Cartesian coordinate system
};

void change_them (struct point point1, struct point*  point2);
#endif /* Point_h_ENSF337 */
