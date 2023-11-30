// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0
    ASSERT_TRUE(collection->empty()); // checks that collection is empty
    ASSERT_EQ(collection->size(), 0); // if collection is empty, size must be 0

    add_entries(1);

    // is the collection still empty?
    // if not empty, what must the size be?
    ASSERT_FALSE(collection->empty()); // checks that collection is not empty
    ASSERT_EQ(collection->size(), 1); // if collection is not empty, size must be > 0
    
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    ASSERT_TRUE(collection->empty()); // checks that collection is empty
    ASSERT_EQ(collection->size(), 0); // if collection is empty, size must be 0

    add_entries(5);

    ASSERT_FALSE(collection->empty()); // checks that collection is not empty
    ASSERT_EQ(collection->size(), 5); // if collection is not empty, size must be > 0
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CheckMaxSizeOfVector)
{
    ASSERT_GE(collection->size(), 0); //check that vector size is greater than or equal to 0

    add_entries(1); // add one entry for testing
    ASSERT_GE(collection->max_size(), collection->size());// check that vector size is greater than or equal to 1
    collection->clear(); // clear entries for next test

    add_entries(5); // add five entries for testing
    ASSERT_GE(collection->max_size(), collection->size());// check that vector size is greater than or equal to 5
    collection->clear(); // clear entries for next test

    add_entries(10); // add ten entries for testing
    ASSERT_GE(collection->max_size(), collection->size());// check that vector size is greater than or equal to 10
    collection->clear(); // clear entries for next test
}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CheckCapacityofVector)
{
    ASSERT_GE(collection->capacity(), 0); // check that collection capacity is greater than or equal to 0

    add_entries(1); // add one entry for testing
    ASSERT_GE(collection->capacity(), 1);// check that collection capacity is greater than or equal to 1
    collection->clear(); // clear entries for next test

    add_entries(5); // add five entries for testing
    ASSERT_GE(collection->capacity(), 5);// check that collection capacity is greater than or equal to 5
    collection->clear(); // clear entries for next test
    
    add_entries(10); // add ten entries for testing
    ASSERT_GE(collection->capacity(), 10);// check that collection capacity is greater than or equal to 10
    collection->clear(); // clear entries for next test
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, CheckIncreaseResizingCollection)
{
    collection->resize(20); // resize collection for testing
    ASSERT_TRUE(collection->size(), 20); // check that collection has been resized to 20
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, CheckDecreaseResizingCollection)
{
    add_entries(20); // adding entries for testing
    collection->resize(10); // resize collection to 10 for testing
    ASSERT_TRUE(collection->size(), 10); // check that collection has been resized to 10
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, CheckZeroResizingCollection)
{
    add_entries(10); // add entries for testing
    collection->resize(0); // resize collection to zero
    ASSERT_TRUE(collection->empty()); // check that collection is empty
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, CheckCollectionClear)
{
    add_entries(5);
    collection->clear();
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, CheckEraseCollection)
{
    add_entries(10);
    collection->erase(collection->begin(), collection->end());
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, CheckReserveCollection)
{
    collection->reserve(10);
    ASSERT_TRUE(collection->capacity(), 10);
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, CheckOutOfRangeException) 
{
    collection->reserve(10); // reserve space in vector
    ASSERT_THROW(collection->at(20), std::out_of_range); // check that exception occurs when accessing out of bounds index
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative
TEST_F(CollectionTest, CheckAddEntry)
{
    add_entries(10); // add entry for testing
    collection->push_back(5); // add value 5 to index 10
    ASSERT_TRUE(collection->at(10), 5); // check that index 10 holds value of 5
}

TEST_F(CollectionTest, CheckRemoveEntry)
{
    add_entries(10); // add entries for testing
    collection->pop_back(); // remove the last entry in the vector
    ASSERT_FALSE(collection->size() == 10); // check that the vector no longer has the same length
}