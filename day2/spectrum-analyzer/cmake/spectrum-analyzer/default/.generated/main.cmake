include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(spectrum_analyzer_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(spectrum_analyzer_default_default_XC8_FILE_TYPE_assemble)
add_library(spectrum_analyzer_default_default_XC8_assemble OBJECT ${spectrum_analyzer_default_default_XC8_FILE_TYPE_assemble})
    spectrum_analyzer_default_default_XC8_assemble_rule(spectrum_analyzer_default_default_XC8_assemble)
    list(APPEND spectrum_analyzer_default_library_list "$<TARGET_OBJECTS:spectrum_analyzer_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(spectrum_analyzer_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(spectrum_analyzer_default_default_XC8_assemblePreprocess OBJECT ${spectrum_analyzer_default_default_XC8_FILE_TYPE_assemblePreprocess})
    spectrum_analyzer_default_default_XC8_assemblePreprocess_rule(spectrum_analyzer_default_default_XC8_assemblePreprocess)
    list(APPEND spectrum_analyzer_default_library_list "$<TARGET_OBJECTS:spectrum_analyzer_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(spectrum_analyzer_default_default_XC8_FILE_TYPE_compile)
add_library(spectrum_analyzer_default_default_XC8_compile OBJECT ${spectrum_analyzer_default_default_XC8_FILE_TYPE_compile})
    spectrum_analyzer_default_default_XC8_compile_rule(spectrum_analyzer_default_default_XC8_compile)
    list(APPEND spectrum_analyzer_default_library_list "$<TARGET_OBJECTS:spectrum_analyzer_default_default_XC8_compile>")
endif()

add_executable(${spectrum_analyzer_default_image_name} ${spectrum_analyzer_default_library_list})

target_link_libraries(${spectrum_analyzer_default_image_name} PRIVATE ${spectrum_analyzer_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
spectrum_analyzer_default_link_rule(${spectrum_analyzer_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${spectrum_analyzer_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${spectrum_analyzer_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${spectrum_analyzer_default_image_name} ${spectrum_analyzer_default_output_dir}/${spectrum_analyzer_default_original_image_name}
                    BYPRODUCTS ${spectrum_analyzer_default_output_dir}/${spectrum_analyzer_default_original_image_name})
