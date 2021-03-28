@startuml
enum Position {
  Begin
  Inner
  End
  Outer
}
enum Type {
  NoIntersection
  IntersectionOnLine
  IntersectionOnSegment
  IntersectionParallelOnLine
  IntersectionParallelOnSegment
}
class Intersector1D1D {
  .. Attribute ..
  -double toleranceParallelism;
  -double toleranceIntersection;

  -Type type;
  -Position positionIntersectionFirstEdge;
  -Position positionIntersectionSecondEdge;

  -Vector2d resultParametricCoordinates;
  -Vector2d originFirstSegment;
  -Vector2d rightHandSide;
  -Matrix2d matrixTangentVector;
  .. Methods ..
        +Intersector1D1D();
        +~Intersector1D1D();

        +void SetToleranceParallelism(const double& _tolerance) 
        +void SetToleranceIntersection(const double& _tolerance)

        +void SetFirstSegment(const Vector2d& origin, const Vector2d& end) 
        +void SetSecondSegment(const Vector2d& origin, const Vector2d& end) 

        +const bool ComputeIntersection();

        +const double& ToleranceIntersection() const 
        +const double& ToleranceParallelism() const 

        +const Vector2d& ParametricCoordinates() 
        +const double& FirstParametricCoordinate()
        +const double& SecondParametricCoordinate()

        +const Position& PositionIntersectionInFirstEdge()
        +const Position& PositionIntersectionInSecondEdge()
        +const Type& TypeIntersection()

        +Vector2d IntersectionFirstParametricCoordinate(const Vector2d& origin,const Vector2d& end) 
        +Vector2d IntersectionSecondParametricCoordinate(const Vector2d& origin,const Vector2d& end) 

}


@enduml
