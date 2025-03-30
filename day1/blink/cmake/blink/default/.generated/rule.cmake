# The following functions contains all the flags passed to the different build stages.

set(PACK_REPO_PATH "/Users/oveljosland/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")

function(blink_default_default_XC8_assemble_rule target)
    set(options
        "-c"
        "${MP_EXTRA_AS_PRE}"
        "-mcpu=AVR128DB48"
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.7.321/xc8"
        "-Wl,--gc-sections"
        "-O1"
        "-ffunction-sections"
        "-fdata-sections"
        "-fshort-enums"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Wall"
        "-gdwarf-3"
        "-mno-const-data-in-progmem"
        "-Wa,--defsym=__MPLAB_BUILD=1")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__AVR128DB48__"
        PRIVATE "XPRJ_default=default")
endfunction()
function(blink_default_default_XC8_assemblePreprocess_rule target)
    set(options
        "-c"
        "${MP_EXTRA_AS_PRE}"
        "-mcpu=AVR128DB48"
        "-x"
        "assembler-with-cpp"
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.7.321/xc8"
        "-Wl,--gc-sections"
        "-O1"
        "-ffunction-sections"
        "-fdata-sections"
        "-fshort-enums"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Wall"
        "-gdwarf-3"
        "-mno-const-data-in-progmem"
        "-Wa,--defsym=__MPLAB_BUILD=1")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__AVR128DB48__"
        PRIVATE "XPRJ_default=default")
endfunction()
function(blink_default_default_XC8_compile_rule target)
    set(options
        "-c"
        "${MP_EXTRA_CC_PRE}"
        "-mcpu=AVR128DB48"
        "-x"
        "c"
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.7.321/xc8"
        "-Wl,--gc-sections"
        "-O1"
        "-ffunction-sections"
        "-fdata-sections"
        "-fshort-enums"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Wall"
        "-gdwarf-3"
        "-mno-const-data-in-progmem")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__AVR128DB48__"
        PRIVATE "XPRJ_default=default")
endfunction()
function(blink_default_link_rule target)
    set(options
        "-Wl,-Map=mem.map"
        "${MP_EXTRA_LD_PRE}"
        "-mcpu=AVR128DB48"
        "-Wl,--defsym=__MPLAB_BUILD=1"
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.7.321/xc8"
        "-Wl,--gc-sections"
        "-O1"
        "-ffunction-sections"
        "-fdata-sections"
        "-fshort-enums"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Wall"
        "-gdwarf-3"
        "-mno-const-data-in-progmem"
        "-Wl,--memorysummary,memoryfile.xml")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
