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
