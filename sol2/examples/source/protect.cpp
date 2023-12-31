#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>


int main(int, char*[]) {

	struct protect_me {
		int gen(int x) {
			return x;
		}
	};

	sol::state lua;
	lua.open_libraries(sol::lib::base);
	lua.new_usertype<protect_me>(
	     "protect_me", "gen", sol::protect(&protect_me::gen));

	lua.script(R"__(
	pm = protect_me.new()
	value = pcall(pm.gen,"wrong argument")
	)__");
	bool value = lua["value"];
	SOL_ASSERT(!value);

	return 0;
}
