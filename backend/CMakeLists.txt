# Include subdirs from here
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# All subdirs' sources

set(ABSTRACTS_SRC
        abstract_classes/abstract_genetic_pool.cpp
        abstract_classes/abstract_specimen.cpp
        )
set(TEMPLATES_SRC
  templates/template_planning_item.cpp
  templates/template_class.cpp
)
set(SHARED_DATA_SRC
  shared_data/shared_data.cpp
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
  ${TEMPLATES_SRC} 
  ${SHARED_DATA_SRC} 
  ${GENETIC_POOL_SRC}
  ${SPECIMEN_SRC}
        ${ABSTRACTS_SRC}
) 

