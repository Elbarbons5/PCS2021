@startuml
enum Type {
  NoIntersection,
  Coplanar,
  PointIntersection
}

class Intersector1D1D {
  .. Attribute ..
    -double toleranceParallelism;
    -double toleranceIntersection;

    -const double* planeTranslationPointer;
    -const Vector3d* planeNormalPointer;
    -const Vector3d* lineOriginPointer;
    -const Vector3d* lineTangentPointer;

    -TypeIntersection intersectionType;
    -double intersectionParametricCoordinate;

  .. Methods ..
    +Intersector2D1D();
    +~Intersector2D1D();

    +void SetToleranceIntersection(const double& _tolerance) { toleranceIntersection = _tolerance; }
    +void SetToleranceParallelism(const double& _tolerance) { toleranceParallelism = _tolerance; }

    +const double& ToleranceIntersection() const {return toleranceIntersection; }
    +const double& ToleranceParallelism() const {return toleranceParallelism; }
    +const TypeIntersection& IntersectionType() const { return intersectionType; }
    +const double& IntersectionParametricCoordinate() const { return intersectionParametricCoordinate; }
    +Vector3d IntersectionPoint() { return *lineOriginPointer + intersectionParametricCoordinate * *lineTangentPointer; }

    +void SetPlane(const Vector3d& planeNormal, const double& planeTranslation);
    +void SetLine(const Vector3d& lineOrigin, const Vector3d& lineTangent);

    +bool ComputeIntersection();
}


@enduml
