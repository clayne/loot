/*  LOOT

A load order optimisation tool for Oblivion, Skyrim, Fallout 3 and
Fallout: New Vegas.

Copyright (C) 2014 WrinklyNinja

This file is part of LOOT.

LOOT is free software: you can redistribute
it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

LOOT is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with LOOT.  If not, see
<https://www.gnu.org/licenses/>.
*/

#ifndef LOOT_TESTS_GUI_STATE_CHANGE_COUNT_TEST
#define LOOT_TESTS_GUI_STATE_CHANGE_COUNT_TEST

#include <gtest/gtest.h>

#include "gui/state/change_count.h"

namespace loot {
namespace test {
TEST(ChangeCount, isNonZeroShouldBeFalseByDefault) {
  ChangeCount counter;
  EXPECT_FALSE(counter.IsNonZero());
}

TEST(ChangeCount, isNonZeroShouldBeFalseIfCounterIsDecremented) {
  ChangeCount counter;
  counter.Decrement();

  EXPECT_FALSE(counter.IsNonZero());
}

TEST(ChangeCount, isNonZeroShouldBeTrueIfCounterIsIncremented) {
  ChangeCount counter;
  counter.Increment();

  EXPECT_TRUE(counter.IsNonZero());
}

TEST(
    ChangeCount,
    isNonZeroShouldBeTrueIfIncrementingTheChangeCounterMoreThanItIsDecremented) {
  ChangeCount counter;
  counter.Increment();
  counter.Increment();
  counter.Decrement();

  EXPECT_TRUE(counter.IsNonZero());
}

TEST(
    ChangeCount,
    isNonZeroShouldBeFalseIfIncrementingTheChangeCounterLessThanItIsDecremented) {
  ChangeCount counter;
  counter.Increment();
  counter.Decrement();
  counter.Decrement();

  EXPECT_FALSE(counter.IsNonZero());
}

TEST(
    ChangeCount,
    isNonZeroShouldBeFalseIfIncrementingTheChangeCounterThenDecrementingItEqually) {
  ChangeCount counter;
  counter.Increment();
  counter.Increment();
  counter.Decrement();
  counter.Decrement();

  EXPECT_FALSE(counter.IsNonZero());
}
}
}

#endif
