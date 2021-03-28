#ifndef __TEST_INTERSECTOR2D1D_H
#define __TEST_INTERSECTOR2D1D_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>

#include "Intersector2D1D.h"

using namespace testing;


TEST(TestIntersecto2D1D, IntersectionTest)
{
  Vector3d normalPlane(0.0, 0.0, 1.0);
  double translation = 0.0;

  Vector3d point(4, 3, 2);
  Vector3d direction(0, 0, 1);

  Intersector2D1D intersector;

  intersector.SetPlane(normalPlane, translation);
  intersector.SetLine(point, direction);
  EXPECT_TRUE(intersector.ComputeIntersection());
  EXPECT_TRUE((intersector.IntersectionPoint() - Vector3d(point.x(),point.y(), 0.0)).squaredNorm() < 1.0E-16);
}

TEST(TestIntersecto2D1D, CoplanarTest)
{
  Vector3d normalPlane(0.0, 0.0, 1.0);
  double translation = 0.0;

  Vector3d point(4, 3, 0.0);
  Vector3d direction(0, 1, 0);

  Intersector2D1D intersector;

  intersector.SetPlane(normalPlane, translation);
  intersector.SetLine(point, direction);
  EXPECT_TRUE(!intersector.ComputeIntersection());
  EXPECT_TRUE((intersector.IntersectionType() == Intersector2D1D::Coplanar ));

}

TEST(TestIntersecto2D1D, NoIntersectionTest)
{
  Vector3d normalPlane(0.0, 0.0, 1.0);
  double translation = 0.0;

  Vector3d point(4, 3, 2.0);
  Vector3d direction(0, 1, 0);

  Intersector2D1D intersector;

  intersector.SetPlane(normalPlane, translation);
  intersector.SetLine(point, direction);
  EXPECT_TRUE(!intersector.ComputeIntersection());
  EXPECT_TRUE((intersector.IntersectionType() == Intersector2D1D::NoInteresection ));

}

#endif // __TEST_INTERSECTOR2D1D_H
