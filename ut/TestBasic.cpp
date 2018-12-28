/*
 * TestBasic.cpp
 *
 *  Created on: 2018?8?9?
 *      Author: zonyu
 */

#include <string>
#include <memory>
#include "gtest/gtest.h"


TEST(basic, nullSmartPointer)
{
    auto nullSharedPointer = std::shared_ptr<int>();
    if(not nullSharedPointer)
    {
        std::cout << "nullSharedPointer is false" <<std::endl;
    }
    ASSERT_FALSE(nullSharedPointer);
    auto sharedPointer = std::make_shared<int>();
    ASSERT_TRUE(sharedPointer);
    if(sharedPointer)
    {
        std::cout << "sharedPointer is true" <<std::endl;
    }
}
