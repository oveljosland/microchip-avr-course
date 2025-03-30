include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(debounce_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(debounce_default_default_XC8_FILE_TYPE_assemble)
add_library(debounce_default_default_XC8_assemble OBJECT ${debounce_default_default_XC8_FILE_TYPE_assemble})
    debounce_default_default_XC8_assemble_rule(debounce_default_default_XC8_assemble)
    list(APPEND debounce_default_library_list "$<TARGET_OBJECTS:debounce_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(debounce_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(debounce_default_default_XC8_assemblePreprocess OBJECT ${debounce_default_default_XC8_FILE_TYPE_assemblePreprocess})
    debounce_default_default_XC8_assemblePreprocess_rule(debounce_default_default_XC8_assemblePreprocess)
    list(APPEND debounce_default_library_list "$<TARGET_OBJECTS:debounce_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(debounce_default_default_XC8_FILE_TYPE_compile)
add_library(debounce_default_default_XC8_compile OBJECT ${debounce_default_default_XC8_FILE_TYPE_compile})
    debounce_default_default_XC8_compile_rule(debounce_default_default_XC8_compile)
    list(APPEND debounce_default_library_list "$<TARGET_OBJECTS:debounce_default_default_XC8_compile>")
endif()

add_executable(${debounce_default_image_name} ${debounce_default_library_list})

target_link_libraries(${debounce_default_image_name} PRIVATE ${debounce_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
debounce_default_link_rule(${debounce_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${debounce_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${debounce_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${debounce_default_image_name} ${debounce_default_output_dir}/${debounce_default_original_image_name}
                    BYPRODUCTS ${debounce_default_output_dir}/${debounce_default_original_image_name})
