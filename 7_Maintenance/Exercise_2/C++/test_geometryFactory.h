#ifndef __TEST_PIZZA_H
#define __TEST_PIZZA_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>

#include "GeometryFactory.h"

using namespace GeometryFactoryLibrary;

using namespace testing;

namespace GeometryFactoryTesting {

  void FillPolygonVertices(vector<Vector2d>& vertices)
  {
    vertices.reserve(10);
    vertices.push_back(Vector2d(1.0000e+00, 2.0000e+00));
    vertices.push_back(Vector2d(7.6489e-01, 1.3236e+00));
    vertices.push_back(Vector2d(4.8943e-02, 1.3090e+00));
    vertices.push_back(Vector2d(6.1958e-01, 8.7639e-01));
    vertices.push_back(Vector2d(4.1221e-01, 1.9098e-01));
    vertices.push_back(Vector2d(1.0000e+00, 6.0000e-01));
    vertices.push_back(Vector2d(1.5878e+00, 1.9098e-01));
    vertices.push_back(Vector2d(1.3804e+00, 8.7639e-01));
    vertices.push_back(Vector2d(1.9511e+00, 1.3090e+00));
    vertices.push_back(Vector2d(1.2351e+00, 1.3236e+00));
  }

  TEST(TestGeometryFactory, TestCreatePolygon)
  {
    vector<Vector2d> vertices;
    FillPolygonVertices(vertices);

    GeometryFactory geometryFactory;

    try
    {
      EXPECT_EQ(geometryFactory.CreatePolygon(vertices), 1);
    }
    catch (const exception& exception)
    {
      FAIL();
    }
  }

  TEST(TestGeometryFactory, TestGetPolygon)
  {
    vector<Vector2d> vertices;
    FillPolygonVertices(vertices);

    GeometryFactory geometryFactory;

    try
    {
      geometryFactory.CreatePolygon(vertices);

      EXPECT_EQ(geometryFactory.GetPolygonNumberVertices(1), 10);

      geometryFactory.GetPolygon(1);
    }
    catch (const exception& exception)
    {
      FAIL();
    }
  }

  TEST(TestGeometryFactory, TestGetPolygonVertex)
  {
    vector<Vector2d> vertices;
    FillPolygonVertices(vertices);

    GeometryFactory geometryFactory;

    try
    {
      geometryFactory.CreatePolygon(vertices);

      const Point& vertex = geometryFactory.GetPolygonVertex(1, 2);
      EXPECT_EQ(vertex.X, vertices[2].X());
      EXPECT_EQ(vertex.Y, vertices[2].Y());
    }
    catch (const exception& exception)
    {
      FAIL();
    }
  }

  TEST(TestGeometryFactory, TestGetPolygonEdge)
  {
    vector<Vector2d> vertices;
    FillPolygonVertices(vertices);

    GeometryFactory geometryFactory;

    try
    {
      geometryFactory.CreatePolygon(vertices);

      const Segment& edge = geometryFactory.GetPolygonEdge(1, 3);
      EXPECT_EQ(edge.From.X, vertices[3].X());
      EXPECT_EQ(edge.From.Y, vertices[3].Y());
      EXPECT_EQ(edge.To.X, vertices[4].X());
      EXPECT_EQ(edge.To.Y, vertices[4].Y());
    }
    catch (const exception& exception)
    {
      FAIL();
    }
  }

  TEST(TestGeometryFactory, TestGetPolygonFailed)
  {
    GeometryFactory geometryFactory;

    try
    {
      geometryFactory.GetPolygon(12);
      FAIL();
    }
    catch (const exception& exception)
    {
      EXPECT_THAT(std::string(exception.what()), Eq("Polygon not found"));
    }
  }

  TEST(TestGeometryFactory, TestGetPolygonVertexFailed)
  {
    vector<Vector2d> vertices;
    FillPolygonVertices(vertices);

    GeometryFactory geometryFactory;
    geometryFactory.CreatePolygon(vertices);

    try
    {
      geometryFactory.GetPolygonVertex(12, 2);
      FAIL();
    }
    catch (const exception& exception)
    {
      EXPECT_THAT(std::string(exception.what()), Eq("Polygon not found"));
    }

    try
    {
      geometryFactory.GetPolygonVertex(1, 17);
      FAIL();
    }
    catch (const exception& exception)
    {
      EXPECT_THAT(std::string(exception.what()), Eq("Vertex not found"));
    }
  }

  TEST(TestGeometryFactory, TestGetPolygonEdgeFailed)
  {
    vector<Vector2d> vertices;
    FillPolygonVertices(vertices);

    GeometryFactory geometryFactory;
    geometryFactory.CreatePolygon(vertices);

    try
    {
      geometryFactory.GetPolygonEdge(12, 3);
      FAIL();
    }
    catch (const exception& exception)
    {
      EXPECT_THAT(std::string(exception.what()), Eq("Polygon not found"));
    }

    try
    {
      geometryFactory.GetPolygonEdge(1, 17);
      FAIL();
    }
    catch (const exception& exception)
    {
      EXPECT_THAT(std::string(exception.what()), Eq("Edge not found"));
    }

  }
}

#endif // __TEST_PIZZA_H
