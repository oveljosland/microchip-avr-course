include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(game_of_life_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(game_of_life_default_default_XC8_FILE_TYPE_assemble)
add_library(game_of_life_default_default_XC8_assemble OBJECT ${game_of_life_default_default_XC8_FILE_TYPE_assemble})
    game_of_life_default_default_XC8_assemble_rule(game_of_life_default_default_XC8_assemble)
    list(APPEND game_of_life_default_library_list "$<TARGET_OBJECTS:game_of_life_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(game_of_life_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(game_of_life_default_default_XC8_assemblePreprocess OBJECT ${game_of_life_default_default_XC8_FILE_TYPE_assemblePreprocess})
    game_of_life_default_default_XC8_assemblePreprocess_rule(game_of_life_default_default_XC8_assemblePreprocess)
    list(APPEND game_of_life_default_library_list "$<TARGET_OBJECTS:game_of_life_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(game_of_life_default_default_XC8_FILE_TYPE_compile)
add_library(game_of_life_default_default_XC8_compile OBJECT ${game_of_life_default_default_XC8_FILE_TYPE_compile})
    game_of_life_default_default_XC8_compile_rule(game_of_life_default_default_XC8_compile)
    list(APPEND game_of_life_default_library_list "$<TARGET_OBJECTS:game_of_life_default_default_XC8_compile>")
endif()

add_executable(${game_of_life_default_image_name} ${game_of_life_default_library_list})

target_link_libraries(${game_of_life_default_image_name} PRIVATE ${game_of_life_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
game_of_life_default_link_rule(${game_of_life_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${game_of_life_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${game_of_life_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${game_of_life_default_image_name} ${game_of_life_default_output_dir}/${game_of_life_default_original_image_name}
                    BYPRODUCTS ${game_of_life_default_output_dir}/${game_of_life_default_original_image_name})
