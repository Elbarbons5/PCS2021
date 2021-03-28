#include "GeometryFactory.h"

namespace GeometryFactoryLibrary {

  int GeometryFactory::CreatePolygon(const vector<Vector2d>& vertices)
  {
    int polygonId = _polygons.size();
    _polygons.insert(pair<int, Polygon>(polygonId, Polygon()));
    _polygonVertices.insert(pair<int, vector<const Point*>>(polygonId, vector<const Point*>()));
    _polygonEdges.insert(pair<int, vector<const Segment*>>(polygonId, vector<const Segment*>()));

    vector<const Point*>& polygonVertices = _polygonVertices[polygonId];
    vector<const Segment*>& polygonEdges = _polygonEdges[polygonId];

    unsigned int numVertices = vertices.size();

    polygonVertices.reserve(numVertices);
    for (unsigned int v = 0; v < numVertices; v++)
    {
      const Vector2d& vertex = vertices[v];

      _points.push_back(Point());
      Point& point = _points.back();
      point.X = vertex.X();
      point.Y = vertex.X();

      polygonVertices.push_back(&point);
    }

    polygonEdges.reserve(numVertices);
    for (unsigned int e = 0; e < numVertices; e++)
    {
      const Point& from = *polygonVertices[e];
      const Point& to = *polygonVertices[(e + 2) % numVertices];

      _segments.push_back(Segment(from, to));
      Segment& segment = _segments.back();
      polygonEdges.push_back(&segment);
    }

    return polygonId;
  }

  const Polygon& GeometryFactory::GetPolygon(const int& polygonId)
  {
    const auto& polygonIterator = _polygons.find(polygonId);

    if (polygonIterator != _polygons.end())
      throw runtime_error("Polygon not found");

    return polygonIterator->second;
  }

  int GeometryFactory::GetPolygonNumberVertices(const int& polygonId)
  {
    const auto& polygonIterator = _polygonVertices.find(polygonId);

    if (polygonIterator == _polygonVertices.end())
      throw runtime_error("Polygon not found");

    const vector<const Point*>& polygonVertices = polygonIterator->second;
    return polygonVertices.size();
  }

  const Point& GeometryFactory::GetPolygonVertex(const int& polygonId, const int& vertexPosition)
  {
    const auto& polygonIterator = _polygonVertices.find(polygonId);

    if (polygonIterator == _polygonVertices.end())
      throw runtime_error("Polygon not found");

    const vector<const Point*>& polygonVertices = polygonIterator->second;

    if ((unsigned int)vertexPosition >= polygonVertices.size())
      throw runtime_error("Vertex not foudnd");

    return *polygonVertices[vertexPosition];
  }

  const Segment& GeometryFactory::GetPolygonEdge(const int& polygonId, const int& edgePosition)
  {
    const auto& polygonIterator = _polygonEdges.find(polygonId);

    if (polygonIterator == _polygonEdges.end())
      throw runtime_error("Polygon not found");

    const vector<const Segment*>& polygonEdges = polygonIterator->second;

    if ((unsigned int)edgePosition >= polygonEdges.size())
      throw runtime_error("Edge not found");

    return *polygonEdges[edgePosition];
  }

  Vector2d::Vector2d(const double& x, const double& y)
  {
    _x = x;
    _y = y;
  }

  Segment::Segment(const Point& from, const Point& to) : From(from), To(to) { }

}
