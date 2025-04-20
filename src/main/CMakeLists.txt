
aux_source_directory(. SRCS)
add_executable(${ITEM_NAME} ${SRCS})

target_link_libraries(${ITEM_NAME} base)