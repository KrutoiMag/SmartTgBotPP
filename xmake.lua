add_languages("c++17")
add_rules("mode.debug", "mode.release")

target("SmartTgBotPP")
do
	set_kind("static")
	set_symbols("debug")
	add_cxxflags("-g3", "-fsanitize=address", "-fno-omit-frame-pointer")
	add_ldflags("-fsanitize=address")
	add_rules("mode.debug", {optimize = "none"})
	add_files("sources/*.cpp")
	add_links("curl")
end

target("test")
do
	set_kind("binary")
	add_files("test/*.cpp")
	add_deps("SmartTgBotPP")
end
