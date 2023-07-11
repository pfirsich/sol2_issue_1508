#include <cstdio>
#include <limits> // Needed for successful compilation with sol 3.2.1

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

class MyException : public std::runtime_error {
public:
    template <typename Msg>
    explicit MyException(Msg&& msg)
        : std::runtime_error(std::forward<Msg>(msg))
    {
        std::printf("MyException\n");
    }
};

int solExceptionHandler(
    lua_State* L, sol::optional<const std::exception&> exc, sol::string_view desc)
{
    if (exc) {
        std::fprintf(stderr, "Exception: %s\n", exc->what());
    } else {
        std::string s(desc);
        std::fprintf(stderr, "Error: %s\n", s.c_str());
    }
    std::exit(1);
    return sol::stack::push(L, desc);
}

int main()
{
    std::printf("enter main\n");
    sol::state lua;
    lua.set_exception_handler(solExceptionHandler);
    lua["throw"] = [](std::string msg) { throw MyException(msg); };
    lua.do_string("throw(\"Foobar\")");
    std::printf("exit main\n");
    return 0;
}
