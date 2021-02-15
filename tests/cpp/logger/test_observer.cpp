#include <iostream>

#include "ioh.hpp"
#include <gtest/gtest.h> 


using ioh::logger::Observer;

TEST(observer, always) {
    const auto o1 = Observer(true);
    ASSERT_TRUE(o1.trigger_always());
    const auto o2 = Observer(false);
    ASSERT_FALSE(o2.trigger_always());
}


TEST(observer, improvement) {
    auto observer = Observer(false);
    ASSERT_TRUE(observer.improvement_trigger(100.0));
    ASSERT_FALSE(observer.improvement_trigger(100.0));
    ASSERT_FALSE(observer.improvement_trigger(101.0));
    ASSERT_TRUE(observer.improvement_trigger(99.0));
}

TEST(observer, interval) {
    const auto observer = Observer(false, 3);
    ASSERT_TRUE(observer.interval_trigger(1));
    ASSERT_FALSE(observer.interval_trigger(2));
    ASSERT_TRUE(observer.interval_trigger(3));
    ASSERT_FALSE(observer.interval_trigger(2));
    ASSERT_TRUE(observer.interval_trigger(6));
    ASSERT_FALSE(observer.interval_trigger(2));
    ASSERT_TRUE(observer.interval_trigger(9));
}


TEST(observer, time_points) {
    auto observer = Observer(false, 0, 0,
                               false, {1, 5}
        );

    ASSERT_TRUE(observer.time_points_trigger(1));
    ASSERT_FALSE(observer.time_points_trigger(2));

    ASSERT_TRUE(observer.time_points_trigger(5));
    ASSERT_FALSE(observer.time_points_trigger(6));

    ASSERT_TRUE(observer.time_points_trigger(10));
    ASSERT_FALSE(observer.time_points_trigger(11));

    ASSERT_TRUE(observer.time_points_trigger(50));
    ASSERT_FALSE(observer.time_points_trigger(51));

    ASSERT_TRUE(observer.time_points_trigger(100));
    ASSERT_FALSE(observer.time_points_trigger(110));

    ASSERT_TRUE(observer.time_points_trigger(500));
    ASSERT_FALSE(observer.time_points_trigger(510));

    auto observer_base5 = Observer(false, 0, 0,
                                     false, {1, 3},
                                     ioh::common::OptimizationType::minimization, 5);

    ASSERT_TRUE(observer_base5.time_points_trigger(1));
    ASSERT_FALSE(observer_base5.time_points_trigger(2));
    ASSERT_TRUE(observer_base5.time_points_trigger(3));
    ASSERT_FALSE(observer_base5.time_points_trigger(4));

    ASSERT_TRUE(observer_base5.time_points_trigger(15));
    ASSERT_FALSE(observer_base5.time_points_trigger(16));

    ASSERT_TRUE(observer_base5.time_points_trigger(25));
    ASSERT_FALSE(observer_base5.time_points_trigger(26));
    ASSERT_TRUE(observer_base5.time_points_trigger(75));
    ASSERT_FALSE(observer_base5.time_points_trigger(76));
}


TEST(observer, time_range) {
    auto observer = Observer(false, 0, 
        5);

    ASSERT_TRUE(observer.time_range_trigger(1));
    ASSERT_FALSE(observer.time_range_trigger(2));
    ASSERT_TRUE(observer.time_range_trigger(3));
    ASSERT_FALSE(observer.time_range_trigger(4));
    ASSERT_TRUE(observer.time_range_trigger(5));
    ASSERT_FALSE(observer.time_range_trigger(6));
    ASSERT_TRUE(observer.time_range_trigger(7));
    ASSERT_FALSE(observer.time_range_trigger(8));
    ASSERT_TRUE(observer.time_range_trigger(9));



    ASSERT_TRUE(observer.time_range_trigger(10));
    ASSERT_FALSE(observer.time_range_trigger(25));

    ASSERT_TRUE(observer.time_range_trigger(30));
    ASSERT_FALSE(observer.time_range_trigger(40));
    ASSERT_TRUE(observer.time_range_trigger(50));
    ASSERT_FALSE(observer.time_range_trigger(51));
    ASSERT_TRUE(observer.time_range_trigger(70));
    ASSERT_FALSE(observer.time_range_trigger(81));
    ASSERT_TRUE(observer.time_range_trigger(90));
   
}