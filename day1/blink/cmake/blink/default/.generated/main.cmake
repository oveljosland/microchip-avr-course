include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(blink_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(blink_default_default_XC8_FILE_TYPE_assemble)
add_library(blink_default_default_XC8_assemble OBJECT ${blink_default_default_XC8_FILE_TYPE_assemble})
    blink_default_default_XC8_assemble_rule(blink_default_default_XC8_assemble)
    list(APPEND blink_default_library_list "$<TARGET_OBJECTS:blink_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(blink_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(blink_default_default_XC8_assemblePreprocess OBJECT ${blink_default_default_XC8_FILE_TYPE_assemblePreprocess})
    blink_default_default_XC8_assemblePreprocess_rule(blink_default_default_XC8_assemblePreprocess)
    list(APPEND blink_default_library_list "$<TARGET_OBJECTS:blink_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(blink_default_default_XC8_FILE_TYPE_compile)
add_library(blink_default_default_XC8_compile OBJECT ${blink_default_default_XC8_FILE_TYPE_compile})
    blink_default_default_XC8_compile_rule(blink_default_default_XC8_compile)
    list(APPEND blink_default_library_list "$<TARGET_OBJECTS:blink_default_default_XC8_compile>")
endif()

add_executable(${blink_default_image_name} ${blink_default_library_list})

target_link_libraries(${blink_default_image_name} PRIVATE ${blink_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
blink_default_link_rule(${blink_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${blink_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${blink_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${blink_default_image_name} ${blink_default_output_dir}/${blink_default_original_image_name}
                    BYPRODUCTS ${blink_default_output_dir}/${blink_default_original_image_name})
