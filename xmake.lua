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
