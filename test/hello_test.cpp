#include <gtest/gtest.h>
#include "three.h"

#include <gtest/gtest.h>
#include "three.h"

// Фикстура для тестирования класса Three
class ThreeTest : public ::testing::Test {
protected:
    Three three;

    // Установка фикстуры
    void SetUp() override {
        // Инициализация необходимых объектов или переменных
    }

    // Очистка фикстуры
    void TearDown() override {
        // Освобождение ресурсов, используемых в тесте
    }

    // Объект класса Three для тестирования
};

// Тест для конструктора
TEST_F(ThreeTest, ConstructorTest) {
    // Упорядочивание (Arrange)
    uint64_t n = 123;

    // Действие (Act)
    Three three(n);

    // Утверждение (Assert)
    ASSERT_EQ(three, Three(123));
}

// Тест для копирующего конструктора
TEST_F(ThreeTest, CopyConstructorTest) {
    // Упорядочивание (Arrange)
    Three original(123);

    // Действие (Act)
    Three copy(original);

    // Утверждение (Assert)
    ASSERT_EQ(copy, original);
}

// Тест для перемещающего конструктора
TEST_F(ThreeTest, MoveConstructorTest) {
    // Упорядочивание (Arrange)
    Three original(123);

    // Действие (Act)
    Three moved(std::move(original));

    // Утверждение (Assert)
    ASSERT_EQ(moved, Three(123));
}

// Тест для оператора присваивания с копированием
TEST_F(ThreeTest, CopyAssignmentOperatorTest) {
    // Упорядочивание (Arrange)
    Three original(123);
    Three copy;

    // Действие (Act)
    copy = original;

    // Утверждение (Assert)
    ASSERT_EQ(copy, original);
}

// Тест для функции print
TEST_F(ThreeTest, PrintTest) {
    // Упорядочивание (Arrange)
    // three уже инициализирован в SetUp()

    // Перенаправление потока вывода в строковый поток
    std::stringstream output;
    std::streambuf *oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    // Вызов функции print
    three.print();

    // Восстановление исходного буфера cout
    std::cout.rdbuf(oldCoutBuffer);

    // Утверждение (Assert)
    ASSERT_EQ(output.str(), "321\n");
}

// Тест для оператора вывода в поток
TEST_F(ThreeTest, OutputOperatorTest) {
    // Упорядочивание (Arrange)
    // three уже инициализирован в SetUp()

    // Перенаправление потока вывода в строковый поток
    std::stringstream output;
    output << three;

    // Утверждение (Assert)
    ASSERT_EQ(output.str(), "321");
}

// Запуск тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

