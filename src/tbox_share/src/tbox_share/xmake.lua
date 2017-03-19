-- add target
target("tbox_share")

    -- set kind
    set_kind("shared")

    -- add defines
    add_defines("__tb_prefix__=\"tbox_share\"")

    -- set the auto-generated config.h
    set_config_h("$(buildir)/tbox_share/config.h")
    set_config_h_prefix("CONFIG")
    
    add_includedirs("../../tbox/include")
    add_linkdirs("../../tbox/lib")
    add_links("tbox")

    -- add the header files for installing
    add_headers("../(tbox_share/**.h)")

    -- add includes directory
    add_includedirs("$(buildir)")
    add_includedirs("$(buildir)/tbox_share")

    -- set the object files directory
    set_objectdir("$(buildir)/.objs")

    -- add packages
    add_options("tbox", "base")

    -- add files
    add_files("*.c") 

