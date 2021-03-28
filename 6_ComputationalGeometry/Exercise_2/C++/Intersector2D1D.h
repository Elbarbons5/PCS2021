#ifndef INTERSECTOR2D1D_HPP
#define INTERSECTOR2D1D_HPP

#include "Eigen"
#include "iostream"

using namespace std;
using namespace Eigen;

class Intersector2D1D;

class Intersector2D1D
{
  public:
    enum TypeIntersection
    {
      NoInteresection = 0,
      Coplanar = 1,
      PointIntersection = 2
    };

  protected:
    double toleranceParallelism;
    double toleranceIntersection;

    const double* planeTranslationPointer;
    const Vector3d* planeNormalPointer;
    const Vector3d* lineOriginPointer;
    const Vector3d* lineTangentPointer;

    TypeIntersection intersectionType;
    double intersectionParametricCoordinate;

  public:
    Intersector2D1D();
    ~Intersector2D1D();

    void SetToleranceIntersection(const double& _tolerance) { toleranceIntersection = _tolerance; }
    void SetToleranceParallelism(const double& _tolerance) { toleranceParallelism = _tolerance; }

    const double& ToleranceIntersection() const {return toleranceIntersection; }
    const double& ToleranceParallelism() const {return toleranceParallelism; }
    const TypeIntersection& IntersectionType() const { return intersectionType; }
    const double& IntersectionParametricCoordinate() const { return intersectionParametricCoordinate; }
    Vector3d IntersectionPoint() { return Vector3d(0.0,0.0,0.0); }

    void SetPlane(const Vector3d& planeNormal, const double& planeTranslation);
    void SetLine(const Vector3d& lineOrigin, const Vector3d& lineTangent);

    bool ComputeIntersection();
};

#endif // INTERSECTOR2D1D_H

