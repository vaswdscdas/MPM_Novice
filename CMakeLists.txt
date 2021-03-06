cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(MPM2DProject)

# Figure out the system (to link against the correct version of libaceutility)
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(WINDOWS TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINUX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

if (MACOSX)
message("Hello Mac User")
set(AceUtil "/Users/sash/mpm_2d/ace_mate/libaceutility_mac.a")
endif(MACOSX)

if (LINUX)
message("Hello Linux User")
set(AceUtil "/home/smaassen/.Mathematica/Applications/AceFEM/Include/CDriver/Linux64/libaceutility.a")
endif(LINUX)

add_library(mdm2dp
    ace_mate/SMSUtility.c
    ace_mate/SmallStrainHookePlaneStrain2D.cpp
    ace_mate/SmallStrainHookePlaneStress2D.cpp
    ace_mate/STVKPlaneStress2D.cpp
    ace_mate/STVKPlaneStrain2D.cpp
    ace_mate/J2FiniteStrain3D.cpp
    src/MPM_Process.cpp
    src/MPM_OutputVTK.cpp
    src/MPM_Particle.cpp
    src/MPM_Body.cpp
    src/MPM_GridNode.cpp
    src/MPM_GridElement.cpp
    src/ELSE_System.cpp
)

add_library(ELSE_CORE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ELSE_System.cpp
)

add_library(ELSE_MPM
    ${CMAKE_CURRENT_SOURCE_DIR}/particles/ELSE_MPMParticle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/materials/ELSE_MPMMaterial.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/materials/LinearElasticity_A.cpp
)

add_library(tiny_xml2
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/tiny_xml2/tinyxml2.cpp
)

#target_include_directories(
#  mdm2dp
#  PUBLIC
#    "include"
#    "ace_mate"
#)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/ace_mate
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/tiny_xml2
  ${CMAKE_CURRENT_SOURCE_DIR}/materials
  ${CMAKE_CURRENT_SOURCE_DIR}/particles
  )

#The follwing copy thing worked !
#file(COPY /Users/sash/mpm_2d/ace_mate/libaceutility_mac.a DESTINATION ${CMAKE_BINARY_DIR}/libAceUtil.a)

# Metal Cutting
add_executable(MetalCut
              metal_cut/metal_cut.cpp
)
target_link_libraries(MetalCut
                      mdm2dp
                      ${AceUtil}
)


add_executable(MPM2D
               main.cpp
)
target_link_libraries(MPM2D
                      mdm2dp
                      ${AceUtil}
)

add_executable(DiscMDM2D
               two_discs.cpp
)
target_link_libraries(DiscMDM2D
                      mdm2dp
                      ${AceUtil}
)


add_executable(DiscMDM2Dn
               two_discs_n.cpp
)
target_link_libraries(DiscMDM2Dn
                      mdm2dp
                      ${AceUtil}
)

add_executable(BarMDM2D
               bar.cpp
)
target_link_libraries(BarMDM2D
                      mdm2dp
                      ${AceUtil}
)

################################## HIGH VELOCITY IMPACT
#set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_SOURCE_DIR}/impact/)
add_executable(ImpactMDM2D
               impact/impact.cpp
)
target_link_libraries(ImpactMDM2D
                      mdm2dp
                      ${AceUtil}
)
#message(${CMAKE_CURRENT_BINARY_DIR}/ImpactMDM2D)
#message(${CMAKE_SOURCE_DIR}/impact/ImpactMDM2D)
#file(COPY ${CMAKE_CURRENT_BINARY_DIR}/ImpactMDM2D DESTINATION ${CMAKE_SOURCE_DIR}/impact/)
##################################

################################## ELSE
add_executable(ELSE
               else.cpp
)
target_link_libraries(ELSE
                      mdm2dp
                      ${AceUtil}
                      tiny_xml2
                      ELSE_CORE
                      ELSE_MPM
)
##################################
