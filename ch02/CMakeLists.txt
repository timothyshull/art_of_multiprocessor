project(ch02)

include_directories(../include)

add_library(lock_one Lock_one.cpp)
add_executable(lock_one_main lock_one_main.cpp)
target_link_libraries(lock_one_main lock_one)

add_library(lock_two Lock_two.cpp)
add_executable(lock_two_main lock_two_main.cpp)
target_link_libraries(lock_two_main lock_two)

add_library(bakery Bakery_lock.cpp)
add_executable(bakery_main bakery_main.cpp)
target_link_libraries(bakery_main bakery)

add_library(peterson_lock Peterson_lock.cpp)
add_executable(peterson_lock_main peterson_lock_main.cpp)
target_link_libraries(peterson_lock_main peterson_lock)

add_library(filter_lock Filter_lock.cpp)
add_executable(filter_lock_main filter_lock_main.cpp)
target_link_libraries(filter_lock_main filter_lock)