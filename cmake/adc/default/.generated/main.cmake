include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(adc_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(adc_default_default_XC8_FILE_TYPE_assemble)
add_library(adc_default_default_XC8_assemble OBJECT ${adc_default_default_XC8_FILE_TYPE_assemble})
    adc_default_default_XC8_assemble_rule(adc_default_default_XC8_assemble)
    list(APPEND adc_default_library_list "$<TARGET_OBJECTS:adc_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(adc_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(adc_default_default_XC8_assemblePreprocess OBJECT ${adc_default_default_XC8_FILE_TYPE_assemblePreprocess})
    adc_default_default_XC8_assemblePreprocess_rule(adc_default_default_XC8_assemblePreprocess)
    list(APPEND adc_default_library_list "$<TARGET_OBJECTS:adc_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(adc_default_default_XC8_FILE_TYPE_compile)
add_library(adc_default_default_XC8_compile OBJECT ${adc_default_default_XC8_FILE_TYPE_compile})
    adc_default_default_XC8_compile_rule(adc_default_default_XC8_compile)
    list(APPEND adc_default_library_list "$<TARGET_OBJECTS:adc_default_default_XC8_compile>")
endif()

add_executable(${adc_default_image_name} ${adc_default_library_list})

target_link_libraries(${adc_default_image_name} PRIVATE ${adc_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
adc_default_link_rule(${adc_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${adc_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${adc_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${adc_default_image_name} ${adc_default_output_dir}/${adc_default_original_image_name}
                    BYPRODUCTS ${adc_default_output_dir}/${adc_default_original_image_name})
