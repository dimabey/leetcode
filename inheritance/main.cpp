#include "gtest/gtest.h"

// Given the struct:
struct Element
{
    int value1;
    int value2;
};

// And the following conditions:

// IS_AWESOME: if (value1 + value2 == 10);
// IS_LESS_AWESOME: if (value1 + value2 == 5);
// IS_PHENOMENAL: if (value1 + value2 == 10 && value1 % 2 == 0);

// Write a function (and unit tests) that can retrieve the sum of all
// AWESOME/LESS_AWESOME/PHENOMENAL elements, or any combination of these
// conditions.
// For example, we might want the sum of all the `AWESOME` elements, or all
// the `AWESOME` and `LESS_AWESOME` elements etc.

// For example:
// elements = [{1,9}, {4,1}, {-2,12}, {3,3}, {8,-3}];

// Awesome:
//   List of elements: [{1, 9}, {-2, 12}];
//   Sum of elements: {-1, 21}
// Less awesome:
//   List of elements: [{4, 1}, {8, -3}];
//   Sum: {12, -2}
// LessAwesome or Phenomenal:
//   List of elements: [{4, 1}, {-2, 12}, {8, -3}];
//   Sum: {10, 10}
// Awesome and Phenomenal:
//   List of elements: [{-2, 12}];
//   Sum: {-2, 12}

// The problem statement is intentionally left vague to avoid forcing a
// particular implementation.  Use your best judgement in terms of how
// to solve it.
// Consider also maintainability and scalability (extension with
// other conditions) in your answer.

// Add your implementation here

bool operator==(const Element& element1, const Element& element2)
{
    return element1.value1 == element2.value1 &&
           element1.value2 == element2.value2;
}

template <typename Function1, typename Function2>
auto orCond(Function1 function1, Function2 function2)
{
    return [function1, function2](const Element& element) {
        return function1(element) || function2(element);
    };
}

template <typename Function1, typename Function2>
auto andCond(Function1 function1, Function2 function2)
{
    return [function1, function2](const Element& element) {
        return function1(element) && function2(element);
    };
}

template <typename Function>
Element getCondSum(const std::vector<Element>& elements, Function&& condition)
{
    Element res({0, 0});
    for (auto element : elements)
    {
        if (condition(element))
        {
            res.value1 += element.value1;
            res.value2 += element.value2;
        }
    }
    return res;
}

bool isAwesome(const Element& element)
{
    return element.value1 + element.value2 == 10;
}

bool isLessAwesome(const Element& element)
{
    return element.value1 + element.value2 == 5;
}

bool isPhenomenal(const Element& element)
{
    return element.value1 + element.value2 == 10 && element.value1 % 2 == 0;
}

// Unit test section.  Feel free to add as many unit tests as you deem
// necessary.
TEST(ConditionalSumTest, BaseCondiditions)
{
    EXPECT_EQ(getCondSum(std::vector<Element>({{1, 9}, {-2, 12}}), isAwesome),
              Element({-1, 21}));
    EXPECT_EQ(
        getCondSum(std::vector<Element>({{4, 1}, {8, -3}}), isLessAwesome),
        Element({12, -2}));
    EXPECT_EQ(getCondSum(std::vector<Element>({{2, 8}, {4, 6}}),
                         andCond(isAwesome, isPhenomenal)),
              Element({6, 14}));
}

TEST(ConditionalSumTest, CompoundingFunctions)
{
    EXPECT_EQ(getCondSum(std::vector<Element>({{4, 1}, {-2, 12}, {8, -3}}),
                         orCond(isLessAwesome, isPhenomenal)),
              Element({10, 10}));
    EXPECT_EQ(getCondSum(std::vector<Element>({{-2, 12}}),
                         andCond(isAwesome, isPhenomenal)),
              Element({-2, 12}));
}

// DO NOT CHANGE BELOW THIS LINE //
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}