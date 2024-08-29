#include "World.hpp"
#include "black_box/Application.hpp"
#include <iostream>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        // std::cout << "arg0: " << argv[0] << std::endl;
        std::cerr << "Please, call with one argument "
                  << "( example: " << argv[0] << " <path to file smile.txt> )";
        return 1;
    } else {
        // std::cout << "arg0: " << argv[0] << '\n'
        //           << "arg1: " << argv[1] << std::endl;
    }

    try {
        World w(argv[1]);
        /**
         * Код ниже запускает выполнение приложения. Для
         * выполнения задания нет необходимости изучать
         * или менять содержимое Application. Для начала
         * лучше сфокусироваться на Ball.hpp, Ball.cpp и
         * World.cpp
         */
        Application app("physics");
        app.run(w);
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 2;
    }
    return 0;
}
