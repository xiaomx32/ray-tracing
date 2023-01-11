set_warnings("all")
set_languages("c++20")

if is_plat("windows") then
    set_runtimes("MD")
end

-- support utf-8 with bom on msvc
if is_host("windows") then
    add_defines("UNICODE", "_UNICODE")
    add_cxflags("/execution-charset:utf-8", "/source-charset:utf-8", {tools = "cl"})
end

add_rules("mode.debug", "mode.releasedbg", "mode.release", "mode.minsizerel")

target("main")
    set_kind("binary")
    add_files("src/*.cpp")
    set_rundir("$(projectdir)")
target_end()
