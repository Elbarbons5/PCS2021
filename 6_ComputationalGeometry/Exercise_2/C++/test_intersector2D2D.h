#ifndef __TEST_INTERSECTOR2D2D_H
#define __TEST_INTERSECTOR2D2D_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>

#include "Intersector2D2D.h"
#include "Intersector2D1D.h"
using namespace testing;


TEST(TestIntersecto2D2D, IntersectionTest)
{
  Vector3d normalPlane(0.0, 0.0, 1.0);
  double translation = 0.0;

  Vector3d normalPlane2(0.0, 1.0, 0.0);
  double translation2 = 0.0;

  Intersector2D2D intersector;

  intersector.SetFirstPlane(normalPlane, translation);
  intersector.SetSecondPlane(normalPlane2, translation2);
  EXPECT_TRUE(intersector.ComputeIntersection());
  EXPECT_TRUE((intersector.IntersectionType() == Intersector2D2D::LineIntersection ));

}

TEST(TestIntersecto2D2D, CoplanarTest)
{
  Vector3d normalPlane(0.0, 0.0, 1.0);
  double translation = 0.0;

  Vector3d normalPlane2(0.0, 0.0, 1.0);
  double translation2 = 0.0;

  Intersector2D2D intersector;

  intersector.SetFirstPlane(normalPlane, translation);
  intersector.SetSecondPlane(normalPlane2, translation2);
  EXPECT_TRUE(!intersector.ComputeIntersection());
  EXPECT_TRUE((intersector.IntersectionType() == Intersector2D2D::Coplanar ));
}

TEST(TestIntersecto2D2D, NoIntersectionTest)
{
  Vector3d normalPlane(0.0, 0.0, 1.0);
  double translation = 0.0;

  Vector3d normalPlane2(0.0, 0.0, 1.0);
  double translation2 = 1.0;

  Intersector2D2D intersector;

  intersector.SetFirstPlane(normalPlane, translation);
  intersector.SetSecondPlane(normalPlane2, translation2);
  EXPECT_TRUE(!intersector.ComputeIntersection());
  EXPECT_TRUE((intersector.IntersectionType() == Intersector2D2D::NoInteresection ));
}

#endif // __TEST_INTERSECTOR2D2D_H
