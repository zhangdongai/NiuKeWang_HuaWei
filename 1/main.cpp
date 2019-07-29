#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string input_str;
    std::getline(std::cin, input_str);
    std::cout << input_str << std::endl;
    std::size_t last_index = input_str.find_last_of(' ');
    if (last_index == std::string::npos)
        std::cout << input_str.size() << std::endl;
    else 
        std::cout << input_str.size() - last_index - 1 << std::endl;
    return 0;
}
