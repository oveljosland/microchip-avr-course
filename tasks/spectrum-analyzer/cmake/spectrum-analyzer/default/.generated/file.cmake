# The following variables contains the files used by the different stages of the build process.
set(spectrum_analyzer_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${spectrum_analyzer_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(spectrum_analyzer_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${spectrum_analyzer_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)
set(spectrum_analyzer_default_default_XC8_FILE_TYPE_compile "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c")
set_source_files_properties(${spectrum_analyzer_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(spectrum_analyzer_default_default_XC8_FILE_TYPE_link)

# The (internal) path to the resulting build image.
set(spectrum_analyzer_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/spectrum-analyzer/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(spectrum_analyzer_default_image_name "spectrum_analyzer_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(spectrum_analyzer_default_original_image_name "default.elf")

# The output directory of the final image.
set(spectrum_analyzer_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/spectrum-analyzer")
