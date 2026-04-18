file(GLOB CIPHER_API_SRC *.c)

add_library(cipher_api ${CIPHER_API_SRC})
target_link_libraries(cipher_api cipher)