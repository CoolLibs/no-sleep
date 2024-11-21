#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#include <no_sleep/no_sleep.hpp>
#include <quick_imgui/quick_imgui.hpp>

// Learn how to use Dear ImGui: https://coollibs.github.io/contribute/Programming/dear-imgui

auto main(int argc, char* argv[]) -> int
{
    int const exit_code = doctest::Context{}.run(); // Run all unit tests

    bool const should_run_imgui_tests = argc < 2 || strcmp(argv[1], "-nogpu") != 0; // NOLINT(*pointer-arithmetic)
    if (!should_run_imgui_tests
        || exit_code != 0 // Only open the window if the tests passed; this makes it easier to notice when some tests fail
    )
    {
        return exit_code;
    }
 
    quick_imgui::loop("no_sleep tests", [&]() { // Open a window and run all the ImGui-related code
        ImGui::Begin("no_sleep tests");
        ImGui::End();
        ImGui::ShowDemoWindow();
    });

    return 0;
}

// Check out doctest's documentation: https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md

int factorial(int number)
{
    return number <= 1 ? number : factorial(number - 1) * number;
}

TEST_CASE("testing the factorial function")
{
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}