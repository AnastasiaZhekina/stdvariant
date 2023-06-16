#include <iostream>

#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {

    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;

    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main() {

    auto result = get_variant();

    if (std::holds_alternative<int>(result)) {
        int num = std::get<int>(result);
        std::cout << num * 2 << std::endl;
    }
    else if (std::holds_alternative<std::string>(result)) {

        std::string str = std::get<std::string>(result);
        std::cout << str << std::endl;
    }
    else if (std::holds_alternative<std::vector<int>>(result)) {

        std::vector<int> arr = std::get<std::vector<int>>(result);

        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}