//
// Created by Illia Plaksa on 13.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../src/controller/include/Controller.h"

class ControllerTest : public ::testing::Test
{};

class ModelMock : public IModel
{
};