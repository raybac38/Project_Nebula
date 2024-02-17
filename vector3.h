typedef struct Vector3
{
    double x;
    double y;
    double z;
}Vector3;

typedef struct Point3
{
    double x;
    double y;
    double z;
}Point3;

Vector3 * InitVector3(void);

Point3 * InitPoint3(void);

Vector3 ScaleVector3(Vector3 a, double factor);

Point3 ScalePoint3(Point3 a, double factor);

Vector3 SumVector3(Vector3 a, Vector3 b);

Vector3 SumPoint3(Point3 a, Point3 b);

