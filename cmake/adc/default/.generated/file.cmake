# The following variables contains the files used by the different stages of the build process.
set(adc_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${adc_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(adc_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${adc_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)
set(adc_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../day1/blink/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../day1/button/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../day1/extras/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../day1/solutions/blink.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../day1/solutions/button.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../day2/adc/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/menusystem/display/ssd1306.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/menusystem/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/menusystem/peripherals/i2c/i2c.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/display/ssd1306.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/filter/kfc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/filter/kiss_fft.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/filter/kiss_fftnd.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/filter/kiss_fftndr.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/filter/kiss_fftr.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/peripherals/adc/adc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/peripherals/clk/clk.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/peripherals/dac/dac.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/peripherals/data_streamer/data_streamer.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/peripherals/i2c/i2c.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/peripherals/tca/tca.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../tasks/spectrum-analyzer/peripherals/usart/usart3.c")
set_source_files_properties(${adc_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(adc_default_default_XC8_FILE_TYPE_link)

# The (internal) path to the resulting build image.
set(adc_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/adc/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(adc_default_image_name "adc_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(adc_default_original_image_name "default.elf")

# The output directory of the final image.
set(adc_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/adc")
