add_languages("c++17")
add_rules("mode.debug", "mode.release")

set_policy("build.ccache", true)

if is_mode("debug") then
	set_symbols("debug")
	set_optimize("none")
	set_warnings("all")
end

target("SmartTgBotPP")
do
	set_kind("static")
	add_files("sources/*.cpp")
	add_links("curl")
	set_symbols("debug")
	set_optimize("none")
	add_defines("DEBUG")
end

target("test")
do
	set_kind("binary")
	add_files("test/*.cpp")
	add_deps("SmartTgBotPP")
	set_symbols("debug")
	set_optimize("none")
	add_defines("DEBUG")
end

target("JSONTEST")
do
	set_kind("binary")
	add_files("JSONTEST/*.cpp")
	set_symbols("debug")
	set_optimize("none")
	add_defines("DEBUG")
end

target("examples/simple")
do
	set_kind("binary")
	add_files("examples/simple.cpp")
	add_deps("SmartTgBotPP")
	set_symbols("debug")
	set_optimize("none")
	add_defines("DEBUG")
end

target("examples/InlineKeyboard")
do
	set_kind("binary")
	add_files("examples/InlineKeyboard.cpp")
	add_deps("SmartTgBotPP")
	set_symbols("debug")
	set_optimize("none")
	add_defines("DEBUG")
end

target("examples/GettingUpdate")
do
	set_kind("binary")
	add_files("examples/GettingUpdate.cpp")
	add_deps("SmartTgBotPP")
	set_symbols("debug")
	set_optimize("none")
	add_defines("DEBUG")
end
