from unittest import TestCase

import main as geometryFactoryLibrary


class TestGeometryFactory(TestCase):
    @staticmethod
    def FillPolygonVertices() -> []:
        vertices = [geometryFactoryLibrary.Vector2d(1.0000e+00, 2.0000e+00),
                    geometryFactoryLibrary.Vector2d(7.6489e-01, 1.3236e+00),
                    geometryFactoryLibrary.Vector2d(4.8943e-02, 1.3090e+00),
                    geometryFactoryLibrary.Vector2d(6.1958e-01, 8.7639e-01),
                    geometryFactoryLibrary.Vector2d(4.1221e-01, 1.9098e-01),
                    geometryFactoryLibrary.Vector2d(1.0000e+00, 6.0000e-01),
                    geometryFactoryLibrary.Vector2d(1.5878e+00, 1.9098e-01),
                    geometryFactoryLibrary.Vector2d(1.3804e+00, 8.7639e-01),
                    geometryFactoryLibrary.Vector2d(1.9511e+00, 1.3090e+00),
                    geometryFactoryLibrary.Vector2d(1.2351e+00, 1.3236e+00)]
        return vertices

    def test_create_polygon(self):
        vertices = TestGeometryFactory.FillPolygonVertices()

        geometryFactory = geometryFactoryLibrary.GeometryFactory()

        try:
            self.assertEqual(geometryFactory.CreatePolygon(vertices), 1)
        except Exception as ex:
            self.fail()

    def test_get_polygon(self):
        vertices = TestGeometryFactory.FillPolygonVertices()

        geometryFactory = geometryFactoryLibrary.GeometryFactory()

        try:
            geometryFactory.CreatePolygon(vertices)
            self.assertEqual(geometryFactory.GetPolygonNumberVertices(1), 10)

            geometryFactory.GetPolygon(1)
        except Exception as ex:
            self.fail()

    def test_get_polygon_vertex(self):
        vertices = TestGeometryFactory.FillPolygonVertices()

        geometryFactory = geometryFactoryLibrary.GeometryFactory()

        try:
            geometryFactory.CreatePolygon(vertices)

            vertex = geometryFactory.GetPolygonVertex(1, 2)
            self.assertEqual(vertex.X, vertices[2].X())
            self.assertEqual(vertex.Y, vertices[2].Y())
        except Exception as ex:
            self.fail()

    def test_get_polygon_edge(self):
        vertices = TestGeometryFactory.FillPolygonVertices()

        geometryFactory = geometryFactoryLibrary.GeometryFactory()

        try:
            geometryFactory.CreatePolygon(vertices)

            edge = geometryFactory.GetPolygonEdge(1, 3)
            self.assertEqual(edge.From.X, vertices[3].X())
            self.assertEqual(edge.From.Y, vertices[3].Y())
            self.assertEqual(edge.To.X, vertices[4].X())
            self.assertEqual(edge.To.Y, vertices[4].Y())
        except Exception as ex:
            self.fail()

    def test_get_polygon_failed(self):
        vertices = TestGeometryFactory.FillPolygonVertices()

        geometryFactory = geometryFactoryLibrary.GeometryFactory()

        try:
            geometryFactory.GetPolygon(12)
            self.fail()
        except Exception as ex:
            self.assertEqual(str(ex), "Polygon not found")

    def test_get_polygon_vertex_failed(self):
        vertices = TestGeometryFactory.FillPolygonVertices()

        geometryFactory = geometryFactoryLibrary.GeometryFactory()
        geometryFactory.CreatePolygon(vertices)

        try:
            geometryFactory.GetPolygonVertex(12, 1)
            self.fail()
        except Exception as ex:
            self.assertEqual(str(ex), "Polygon not found")

        try:
            geometryFactory.GetPolygonVertex(1, 17)
            self.fail()
        except Exception as ex:
            self.assertEqual(str(ex), "Vertex not found")

    def test_get_polygon_edge_failed(self):
        vertices = TestGeometryFactory.FillPolygonVertices()

        geometryFactory = geometryFactoryLibrary.GeometryFactory()
        geometryFactory.CreatePolygon(vertices)

        try:
            geometryFactory.GetPolygonEdge(12, 1)
            self.fail()
        except Exception as ex:
            self.assertEqual(str(ex), "Polygon not found")

        try:
            geometryFactory.GetPolygonEdge(1, 17)
            self.fail()
        except Exception as ex:
            self.assertEqual(str(ex), "Edge not found")