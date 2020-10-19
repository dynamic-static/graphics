
# ==========================================
#   Copyright (c) 2017-2020 dynamic_static
#     Patrick Purcell
#       Licensed under the MIT license
#     http://opensource.org/licenses/MIT
# ==========================================

set(SPIRV-Reflect_sourceDirectory "${externalDirectory}/SPIRV-Reflect/")
set(SPIRV-Reflect_includeDirectory "${CMAKE_BINARY_DIR}/external/SPIRV-Reflect/")
add_library(
    SPIRV-Reflect STATIC
    "${SPIRV-Reflect_sourceDirectory}/spirv_reflect.c"
    "${SPIRV-Reflect_sourceDirectory}/spirv_reflect.h"
)
target_include_directories(SPIRV-Reflect PUBLIC "${SPIRV-Reflect_includeDirectory}")
set_target_properties(SPIRV-Reflect PROPERTIES FOLDER "external/")
