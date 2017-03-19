-- add target
target("demo")

    -- set kind
    set_kind("binary")

    set_warnings("less")

    -- add deps
    add_deps("tbox_share")

    -- add defines
    add_defines("__tb_prefix__=\"demo\"")
    
    -- set the object files directory
    set_objectdir("$(buildir)/.objs")

    -- add links directory
    add_linkdirs("$(buildir)")

    -- add includes directory
    add_includedirs("$(buildir)")
    add_includedirs("$(buildir)/tbox_share")

    -- add links
    add_links("tbox_share")

    -- add packages
    add_options("tbox", "base")

    -- add files
    add_files("*.c") 

