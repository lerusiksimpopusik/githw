#include <gtest/gtest.h>
#include "candle.h"

// Тесты для метода body_contains
TEST(CandleTest, BodyContains_GreenCandle) {
    Candle c(100, 120, 80, 110);  // Зеленая свеча (close > open)
    EXPECT_TRUE(c.body_contains(105));
    EXPECT_TRUE(c.body_contains(110));
    EXPECT_FALSE(c.body_contains(95));  // Ниже open
    EXPECT_FALSE(c.body_contains(125)); // Выше close
}

TEST(CandleTest, BodyContains_RedCandle) {
    Candle c(110, 120, 80, 100);  // Красная свеча (close < open)
    EXPECT_TRUE(c.body_contains(105));
    EXPECT_TRUE(c.body_contains(110));
    EXPECT_FALSE(c.body_contains(95));  // Ниже close
    EXPECT_FALSE(c.body_contains(115)); // Выше open
}

TEST(CandleTest, BodyContains_BorderCases) {
    Candle c(100, 120, 80, 110);
    EXPECT_TRUE(c.body_contains(100));  // Граница open
    EXPECT_TRUE(c.body_contains(110));  // Граница close
}

// Тесты для метода contains
TEST(CandleTest, Contains_InsideRange) {
    Candle candle(100, 110, 90, 105);
    EXPECT_TRUE(candle.contains(95));
}

TEST(CandleTest, Contains_OnEdge) {
    Candle candle(100, 110, 90, 105);
    EXPECT_TRUE(candle.contains(90));
    EXPECT_TRUE(candle.contains(110));
}

TEST(CandleTest, Contains_OutsideRange) {
    Candle candle(100, 110, 90, 105);
    EXPECT_FALSE(candle.contains(85));
    EXPECT_FALSE(candle.contains(115));
}

// Тесты для метода full_size
TEST(CandleTest, FullSize_Normal) {
    Candle candle(100, 110, 90, 105);
    EXPECT_EQ(candle.full_size(), 20);
}

TEST(CandleTest, FullSize_SmallCandle) {
    Candle candle(100, 101, 99, 100);
    EXPECT_EQ(candle.full_size(), 2);
}

TEST(CandleTest, FullSize_LargeCandle) {
    Candle candle(100, 200, 50, 150);
    EXPECT_EQ(candle.full_size(), 150);
}

// Тесты для метода body_size
TEST(CandleTest, BodySize_Normal) {
    Candle candle(100, 110, 90, 105);
    EXPECT_EQ(candle.body_size(), 5); 
}

TEST(CandleTest, BodySize_OnePoint) {
    Candle candle(100, 100, 90, 100);  
    EXPECT_EQ(candle.body_size(), 0);
}

TEST(CandleTest, BodySize_LargeBody) {
    Candle candle(50, 200, 20, 150);
    EXPECT_EQ(candle.body_size(), 100);  
}

// Тесты для метода is_red
TEST(CandleTest, IsRed_True) {
    Candle candle(110, 100, 90, 105);
    EXPECT_TRUE(candle.is_red());
}

TEST(CandleTest, IsRed_False) {
    Candle candle(100, 110, 90, 105);
    EXPECT_FALSE(candle.is_red());
}

TEST(CandleTest, IsRed_NoBody) {
    Candle candle(100, 100, 90, 105);
    EXPECT_FALSE(candle.is_red());
}


// Тесты для метода is_green
TEST(CandleTest, IsGreen_True) {
    Candle candle(100, 110, 90, 105);
    EXPECT_TRUE(candle.is_green());
}

TEST(CandleTest, IsGreen_False) {
    Candle candle(110, 100, 90, 105);
    EXPECT_FALSE(candle.is_green());
}

TEST(CandleTest, IsGreen_NoBody) {
    Candle candle(100, 100, 90, 105);
    EXPECT_TRUE(candle.is_green());
}

TEST(CandleTest, DetectsDoji)
{
	Candle doji(100.0, 105.0, 95.0, 100.5); // тело: 0.5, весь размер: 10
	EXPECT_TRUE(doji.is_doji());

	Candle normal(100.0, 110.0, 90.0, 108.0); // тело: 8.0, весь размер: 20
	EXPECT_FALSE(normal.is_doji());
}