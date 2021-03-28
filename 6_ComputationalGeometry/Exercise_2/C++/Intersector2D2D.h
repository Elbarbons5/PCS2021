#ifndef INTERSECTOR2D2D_HPP
#define INTERSECTOR2D2D_HPP

#include "Eigen"
#include "iostream"

using namespace std;
using namespace Eigen;

class Intersector2D2D;

class Intersector2D2D
{
  public:
    enum TypeIntersection
    {
      NoInteresection = 0,
      Coplanar = 1,
      LineIntersection = 2
    };

  protected:
    TypeIntersection intersectionType;

    double toleranceParallelism;
    double toleranceIntersection;

    Vector3d pointLine;
    Vector3d tangentLine;

    Vector3d rightHandSide;
    Matrix3d matrixNomalVector;

  public:
    Intersector2D2D();
    ~Intersector2D2D();

    void SetTolleranceIntersection(const double& _tolerance) { toleranceIntersection = _tolerance; }
    void SetTolleranceParallelism(const double& _tolerance) { toleranceParallelism = _tolerance; }

    const TypeIntersection& IntersectionType() const { return intersectionType; }
    const double& ToleranceIntersection() const { return toleranceIntersection; }
    const double& ToleranceParallelism() const { return toleranceParallelism; }
    const Vector3d& PointLine() const { return pointLine; }
    const Vector3d& TangentLine() const { return tangentLine; }

    void SetFirstPlane(const Vector3d& planeNormal, const double& planeTranslation);
    void SetSecondPlane(const Vector3d& planeNormal, const double& planeTranslation);
    bool ComputeIntersection();
};

#endif //INTERSECTOR2D2D_HPP

