# The following variables contains the files used by the different stages of the build process.
set(menusystem_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${menusystem_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(menusystem_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${menusystem_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)
set(menusystem_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../display/ssd1306.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../peripherals/i2c/i2c.c")
set_source_files_properties(${menusystem_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(menusystem_default_default_XC8_FILE_TYPE_link)

# The (internal) path to the resulting build image.
set(menusystem_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/menusystem/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(menusystem_default_image_name "menusystem_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(menusystem_default_original_image_name "default.elf")

# The output directory of the final image.
set(menusystem_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/menusystem")
