
#define SOL_ALL_SAFETIES_ON 1

#include <stdio.h>

#include <sol/sol.hpp>

extern "C" int tcc_main(int, char**);

int main(int argc, char** argv) {
	sol::state lua;

	// open some common libraries
	lua.open_libraries(sol::lib::base, sol::lib::package);
	lua.script("print('bark bark bark!')");

    return tcc_main(argc, argv);
}

int blah() {
    printf("Doin it!\n");
    return 1;
}

int asefaef = blah();
