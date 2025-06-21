add_languages("c++17")
add_rules("mode.debug", "mode.release")

set_policy("build.ccache", true)

target("SmartTgBotPP")
do
	set_kind("static")
	add_files("sources/*.cpp")
	add_links("curl")
end

target("test")
do
	set_kind("binary")
	add_files("test/*.cpp")
	add_deps("SmartTgBotPP")
end

target("JSONTEST")
do
	set_kind("binary")
	add_files("JSONTEST/*.cpp")
end

target("examples/simple")
do
	set_kind("binary")
	add_files("examples/simple.cpp")
	add_deps("SmartTgBotPP")
end

target("examples/InlineKeyboard")
do
	set_kind("binary")
	add_files("examples/InlineKeyboard.cpp")
	add_deps("SmartTgBotPP")
end
