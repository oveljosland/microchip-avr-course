include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(menusystem_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(menusystem_default_default_XC8_FILE_TYPE_assemble)
add_library(menusystem_default_default_XC8_assemble OBJECT ${menusystem_default_default_XC8_FILE_TYPE_assemble})
    menusystem_default_default_XC8_assemble_rule(menusystem_default_default_XC8_assemble)
    list(APPEND menusystem_default_library_list "$<TARGET_OBJECTS:menusystem_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(menusystem_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(menusystem_default_default_XC8_assemblePreprocess OBJECT ${menusystem_default_default_XC8_FILE_TYPE_assemblePreprocess})
    menusystem_default_default_XC8_assemblePreprocess_rule(menusystem_default_default_XC8_assemblePreprocess)
    list(APPEND menusystem_default_library_list "$<TARGET_OBJECTS:menusystem_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(menusystem_default_default_XC8_FILE_TYPE_compile)
add_library(menusystem_default_default_XC8_compile OBJECT ${menusystem_default_default_XC8_FILE_TYPE_compile})
    menusystem_default_default_XC8_compile_rule(menusystem_default_default_XC8_compile)
    list(APPEND menusystem_default_library_list "$<TARGET_OBJECTS:menusystem_default_default_XC8_compile>")
endif()

add_executable(${menusystem_default_image_name} ${menusystem_default_library_list})

target_link_libraries(${menusystem_default_image_name} PRIVATE ${menusystem_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
menusystem_default_link_rule(${menusystem_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${menusystem_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${menusystem_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${menusystem_default_image_name} ${menusystem_default_output_dir}/${menusystem_default_original_image_name}
                    BYPRODUCTS ${menusystem_default_output_dir}/${menusystem_default_original_image_name})
