#ifndef GEOMETRYFACTORY_H
#define GEOMETRYFACTORY_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

namespace GeometryFactoryLibrary {

  class Vector2d {
    private:
      double _x;
      double _y;
    public:
      Vector2d(const double& x,
               const double& y);
      const double& X() const { return _x; }
      const double& Y() const { return _y; }
  };

  class Point {
    public:
      double X;
      double Y;
  };

  class Segment {
    public:
      const Point& From;
      const Point& To;
      Segment(const Point& from,
              const Point& to);
  };

      class Polygon {
      };

      class IGeometryFactory {
        public:
          virtual int CreatePolygon(const vector<Vector2d>& vertices) = 0;
          virtual const Polygon& GetPolygon(const int& polygonId) = 0;
          virtual int GetPolygonNumberVertices(const int& polygonId) = 0;
          virtual const Point& GetPolygonVertex(const int& polygonId,
                                                const int& vertexPosition) = 0;
          virtual const Segment& GetPolygonEdge(const int& polygonId,
                                                const int& edgePosition) = 0;
      };

      class GeometryFactory : public IGeometryFactory {
        private:
          unordered_map<int, Polygon> _polygons;
          list<Point> _points;
          list<Segment> _segments;
          unordered_map<int, vector<const Point*>> _polygonVertices;
          unordered_map<int, vector<const Segment*>> _polygonEdges;

        public:
          int CreatePolygon(const vector<Vector2d>& vertices);
          const Polygon& GetPolygon(const int& polygonId);
          int GetPolygonNumberVertices(const int& polygonId);
          const Point& GetPolygonVertex(const int& polygonId,
                                        const int& vertexPosition);
          const Segment& GetPolygonEdge(const int& polygonId,
                                        const int& edgePosition);
      };

  };

#endif // GEOMETRYFACTORY_H
