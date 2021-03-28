#ifndef INTERSECTOR1D1D_HPP
#define INTERSECTOR1D1D_HPP

#include "Eigen"
#include "iostream"

using namespace std;
using namespace Eigen;

class Intersector1D1D;

class Intersector1D1D
{
    public:
        enum Type
        {
            NoIntersection = 0,
            IntersectionOnLine = 1,
            IntersectionOnSegment = 2,
            IntersectionParallelOnLine = 3,
            IntersectionParallelOnSegment = 4,
        };
        enum Position
        {
            Begin = 0,
            Inner = 1,
            End = 2,
            Outer = 3
        };

    private:

        double toleranceParallelism;
        double toleranceIntersection;

        Type type;
        Position positionIntersectionFirstEdge;
        Position positionIntersectionSecondEdge;

        Vector2d resultParametricCoordinates;
        Vector2d originFirstSegment;
        Vector2d rightHandSide;
        Matrix2d matrixTangentVector;

    public:
        Intersector1D1D();
        ~Intersector1D1D();

        void SetToleranceParallelism(const double& _tolerance) { toleranceParallelism = _tolerance; }
        void SetToleranceIntersection(const double& _tolerance) { toleranceIntersection = _tolerance; }

        void SetFirstSegment(const Vector2d& origin, const Vector2d& end) {matrixTangentVector.col(0) = end - origin; originFirstSegment = origin; }
        void SetSecondSegment(const Vector2d& origin, const Vector2d& end) {matrixTangentVector.col(1) = origin - end; rightHandSide = origin - originFirstSegment; }

        ///Compute the intersections between the line of the first edge and the second edge and returns the parametric coordinates and the intersection type
        ///The first parametric coordinate refers to the first tangentVector and ...
        ///@note In case of parallelism both the parametric coordinates refers to the first edge
        bool ComputeIntersection();

        const double& ToleranceIntersection() const {return toleranceIntersection; }
        const double& ToleranceParallelism() const {return toleranceParallelism; }

        const Vector2d& ParametricCoordinates() {return resultParametricCoordinates;}
        const double& FirstParametricCoordinate() {return resultParametricCoordinates(0);}
        const double& SecondParametricCoordinate() {return resultParametricCoordinates(1);}

        const Position& PositionIntersectionInFirstEdge(){return positionIntersectionFirstEdge;}
        const Position& PositionIntersectionInSecondEdge(){return positionIntersectionSecondEdge;}
        const Type& TypeIntersection() {return type;}

        Vector2d IntersectionFirstParametricCoordinate(const Vector2d& origin,const Vector2d& end) const {return (1 - resultParametricCoordinates(0)) * origin + resultParametricCoordinates(0) * end; }

        Vector2d IntersectionSecondParametricCoordinate(const Vector2d& origin,const Vector2d& end) const {return (1 - resultParametricCoordinates(1)) * origin + resultParametricCoordinates(0) * end; }

};

#endif // INTERSECTOR1D1D_H

