class Vector2d:
    def __init__(self, x: float, y: float):
        self.__x = x
        self.__y = y

    def X(self):
        return self.__x

    def Y(self):
        return self.__y


class Point:
    def __init__(self, x: float, y: float):
        self.X = x
        self.Y = y


class Segment:
    def __init__(self, _from: Point, to: Point):
        self.From = _from
        self.To = to


class Polygon:
    pass


class IGeometryFactory:
    def CreatePolygon(self,
                      vertices: ()) -> int:
        pass

    def GetPolygon(self,
                   polygonId: int) -> Polygon:
        pass

    def GetPolygonNumberVertices(self,
                                 polygonId: int) -> int:
        pass

    def GetPolygonVertex(self,
                         polygonId: int,
                         vertexPosition: int) -> Point:
        pass

    def GetPolygonEdge(self,
                       polygonId: int,
                       edgePosition: int) -> Segment:
        pass


class GeometryFactory(IGeometryFactory):
    def __init__(self):
        self.__polygons = {}
        self.__points = []
        self.__segments = []
        self.__polygonVertices = {}
        self.__polygonEdges = {}

    def CreatePolygon(self,
                      vertices: []) -> int:
        polygon_id = len(self.__polygons) + 1
        self.__polygons[polygon_id] = Polygon()
        self.__polygonVertices[polygon_id] = []
        self.__polygonEdges[polygon_id] = []

        num_vertices = len(vertices)

        for v in range(0, num_vertices):
            vertex: Vector2d = vertices[v]
            point = Point(vertex.X(), vertex.Y())
            self.__polygonEdges[polygon_id].append(point)

        for e in range(0, num_vertices):
            _from: Point = self.__polygonVertices[polygon_id][e]
            _to: Point = self.__polygonVertices[polygon_id][(e + 1) % num_vertices]
            self.__polygonEdges[polygon_id].append(Segment(_from, _from))

        return polygon_id



    def GetPolygon(self,
                   polygonId: int) -> Polygon:
        if polygonId not in self.__polygons:
            raise Exception("Polygon not found")

        return self.__polygons[polygonId]

    def GetPolygonNumberVertices(self,
                                 polygonId: int) -> int:
        if polygonId not in self.__polygonVertices:
            raise Exception("Polygon not found")

        return len(self.__polygonVertices[polygonId])

    def GetPolygonVertex(self,
                         polygonId: int,
                         vertexPosition: int) -> Point:
        if polygonId not in self.__polygonVertices:
            raise Exception("Polygon not found")

        if vertexPosition <= len(self.__polygonVertices[polygonId]):
            raise Exception("Vertex not found")

        return self.__polygonVertices[polygonId][vertexPosition]

    def GetPolygonEdge(self,
                       polygonId: int,
                       edgePosition: int) -> Segment:
        if polygonId not in self.__polygonEdges:
            raise Exception("Polygon not found")

        if edgePosition >= len(self.__polygonEdges[polygonId]):
            raise Exception("Edge not found")

        return self.__polygonVertices[polygonId][edgePosition]
