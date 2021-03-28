#ifndef __TEST_EMPTYCLASS_H
#define __TEST_EMPTYCLASS_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>

#include "Eigen"

#include "EmptyClass.hpp"

using namespace EmptyNamespace;
using namespace testing;
using namespace std;

namespace EmptyTesting {

  TEST(TestEmptyClass, TestEmptyMethod)
  {
    EmptyClass emptyObject;

    try
    {
      Eigen::Vector3d test(1.0, 2.0, 6.0);
      EXPECT_EQ(test.x(), 1.0);
      EXPECT_EQ(test.y(), 2.0);
      EXPECT_EQ(test.z(), 6.0);

      EXPECT_EQ(emptyObject.EmptyMethod(), true);
    }
    catch (const exception& exception)
    {
      FAIL();
    }
  }
}

#endif // __TEST_EMPTYCLASS_H
