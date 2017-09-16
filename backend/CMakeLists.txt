# Include subdirs from here
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# All subdirs' sources

set(BASIC_INSTANCES_SRC
  basic_instances/pitem_instance.cpp
  basic_instances/course_instance.cpp
)
set(ABSTRACTS_SRC
        abstract_classes/abstract_genetic_pool.cpp
        abstract_classes/abstract_specimen.cpp
        abstract_classes/mark.cpp
)
set(SHARED_DATA_SRC
  shared_data/shared_data.cpp
  shared_data/shared_instances.cpp
)
set(GENETIC_POOL_SRC
  genetic_pool_instances/genetic_pool_alpha.cpp
  genetic_pool_instances/genetic_pool_species.cpp
)
set(SPECIMEN_SRC
  specimen_instances/specimen_alpha.cpp
)

add_executable(main_backend 
  main.cpp 
  application/application.cpp 
  ${ABSTRACTS_SRC}
  ${BASIC_INSTANCES_SRC}
  ${SHARED_DATA_SRC} 
  ${SPECIMEN_SRC}
  ${GENETIC_POOL_SRC}
) 

