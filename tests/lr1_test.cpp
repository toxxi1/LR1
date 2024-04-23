#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
using namespace std;

// Тестовый класс
class process_arrayTest : public ::testing::Test {
protected:
    // Здесь вы можете добавить дополнительные настройки для тестов
    // в функции SetUp()
    void SetUp() override {
        // Например, инициализация данных
        arr = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override {
        // Например, очистка данных
        arr.clear();
    }

    // Объявляем переменные, которые будут использоваться в тестах
    vector<int> arr;
    pair<int, vector<int>> result;
};

//Тест1
TEST_F(process_arrayTest, FlowGraphTest) {
    vector<int> arr;
    pair<int, vector<int>> result;

    // Инициализация данных
    arr = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };

    // Вызываем функцию abc с тестовыми данными
    result = abc(arr);

    // Проверяем ожидаемые результаты
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, arr);
}
//Тест2, проверка массива с 1 числом
TEST_F(process_arrayTest, ConditionTest) {
    vector<int> arr;
    pair<int, vector<int>> result;

    // Инициализация данных
    arr = { 100 };

    // Вызываем функцию abc с тестовыми данными
    result = abc(arr);

    // Проверяем ожидаемые результаты
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, arr);
}

//Тест3, проверка массива с отрицательными числами по убыванию
TEST_F(process_arrayTest, NegativeDescendingTest) {
    vector<int> arr;
    pair<int, vector<int>> result;

    arr = { -1, -2, -3, -4, -5 };

    result = abc(arr);
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, arr);
}

//Тест4, проверка массива с отрицательными числами по возрастанию
TEST_F(process_arrayTest, NegativeAscendingTest) {
    vector<int> arr;
    pair<int, vector<int>> result;

    arr = { -5, -4, -3, -2, -1 };


    result = abc(arr);
    EXPECT_EQ(result.first, 0);
    EXPECT_EQ(result.second, arr);
}

// Тест5, проверка большого массива по возрастанию
TEST_F(process_arrayTest, ArraySizeTest) {
    vector<int> arr;
    pair<int, vector<int>> result;

    for (int size = 1; size <= 1024; size += 52) {
        arr.resize(size);
        // Заполняем массив значениями, чтобы проверить функцию на разных размерах
        for (int i = 0; i < size; ++i) {
            arr[i] = static_cast<double>(i);
        }
    }
    result = abc(arr);
    EXPECT_EQ(result.first, 0);
    EXPECT_EQ(result.second, arr);
}

// Тест6, проверка большого массива по убыванию
TEST_F(process_arrayTest, NegativeArraySizeTest) {
    vector<int> arr;
    pair<int, vector<int>> result;

    for (int size = 1; size <= 1024; size += 52) {
        arr.resize(size);
        // Заполняем массив значениями, чтобы проверить функцию на разных размерах
        for (int i = 1023; i < size - 100; i = i - 1) {
            arr[i] = static_cast<double>(i);
        }
    }
    result = abc(arr);
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, arr);
}

// Тест7, проверка большого массива по возрастанию, с отрицательными числами.
TEST_F(process_arrayTest, NegativeArraySizeTest1) {
    vector<int> arr;
    pair<int, vector<int>> result;

    for (int i = -500; i <= 500; ++i) {
        arr.push_back(i); // Заполнение вектора числами от -500 до 500
    }

    result = abc(arr);
    EXPECT_EQ(result.first, 0);
    EXPECT_EQ(result.second, arr);
}
