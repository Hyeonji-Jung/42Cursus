#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
            for (int j = 0; j < strlen(argv[i]); j++)
                std::cout << (char)(toupper(argv[i][j]));
    }
    std::cout << std::endl;
    return 0;
}
