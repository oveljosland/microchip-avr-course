include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(button_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(button_default_default_XC8_FILE_TYPE_assemble)
add_library(button_default_default_XC8_assemble OBJECT ${button_default_default_XC8_FILE_TYPE_assemble})
    button_default_default_XC8_assemble_rule(button_default_default_XC8_assemble)
    list(APPEND button_default_library_list "$<TARGET_OBJECTS:button_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(button_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(button_default_default_XC8_assemblePreprocess OBJECT ${button_default_default_XC8_FILE_TYPE_assemblePreprocess})
    button_default_default_XC8_assemblePreprocess_rule(button_default_default_XC8_assemblePreprocess)
    list(APPEND button_default_library_list "$<TARGET_OBJECTS:button_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(button_default_default_XC8_FILE_TYPE_compile)
add_library(button_default_default_XC8_compile OBJECT ${button_default_default_XC8_FILE_TYPE_compile})
    button_default_default_XC8_compile_rule(button_default_default_XC8_compile)
    list(APPEND button_default_library_list "$<TARGET_OBJECTS:button_default_default_XC8_compile>")
endif()

add_executable(${button_default_image_name} ${button_default_library_list})

target_link_libraries(${button_default_image_name} PRIVATE ${button_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
button_default_link_rule(${button_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${button_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${button_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${button_default_image_name} ${button_default_output_dir}/${button_default_original_image_name}
                    BYPRODUCTS ${button_default_output_dir}/${button_default_original_image_name})
