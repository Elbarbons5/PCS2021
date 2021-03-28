@startuml
enum Type {
  NoIntersection,
  Coplanar,
  LineIntersection
}

class Intersector2D2D {
  .. Attribute ..
    -TypeIntersection intersectionType;

    -double toleranceParallelism;
    -double toleranceIntersection;

    -Vector3d pointLine;
    -Vector3d tangentLine;

    -Vector3d rightHandSide;
    -Matrix3d matrixNomalVector;

  .. Methods ..
    +Intersector2D2D();
    +~Intersector2D2D();

    +void SetTolleranceIntersection(const double& _tolerance) { toleranceIntersection = _tolerance; }
    +void SetTolleranceParallelism(const double& _tolerance) { toleranceParallelism = _tolerance; }

    +const TypeIntersection& IntersectionType() const { return intersectionType; }
    +const double& ToleranceIntersection() const { return toleranceIntersection; }
    +const double& ToleranceParallelism() const { return toleranceParallelism; }
    +const Vector3d& PointLine() const { return pointLine; }
    +const Vector3d& TangentLine() const { return tangentLine; }

    +void SetFirstPlane(const Vector3d& planeNormal, const double& planeTranslation);
    +void SetSecondPlane(const Vector3d& planeNormal, const double& planeTranslation);
    +bool ComputeIntersection();
}


@enduml
