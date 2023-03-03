typedef struct point3d
{
    float x;
    float y;
    float z;
} Point3d;

void
Point3d_print( const Point3d *pd )
{
    printf("(%g, %g, %g )", pd->x, pd->y, pd->z);
}

#define Point3d_print( pd ) \
    printf("(%g, %g, %g )", pd->x, pd->y, pd->z );

void
my_foo()
{
    Point3d *pd = get_a_point();
    // ...
    /* Direct print poitn ... */
    printf("(%g, %g, %g)", pd->x, pd->y, pd->z);
}

Point3d pt;
pt.x = 0.0;

#define X( p, xval ) (p.x) = (xval);
// ...
X( pt, 0.0 );