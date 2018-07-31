cmake_minimum_required(VERSION 2.8)

project(indicator-memory)

set(PNAME com.github.dawidd6.${PROJECT_NAME})

find_package(PkgConfig REQUIRED)

pkg_check_modules(APPIND3 REQUIRED appindicator3-0.1)

include_directories(${APPIND3_INCLUDE_DIRS})

link_directories(${APPIND3_LIBRARY_DIRS})

add_definitions(${APPIND3_CFLAGS_OTHER})

add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.c)

target_link_libraries(${PROJECT_NAME} ${APPIND3_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES data/${PROJECT_NAME}.desktop DESTINATION share/applications RENAME ${PNAME}.desktop)
install(FILES data/${PROJECT_NAME}.desktop DESTINATION /etc/xdg/autostart RENAME ${PNAME}.desktop)
install(FILES data/icon.svg DESTINATION share/icons/hicolor/scalable/apps RENAME ${PNAME}.svg)
install(FILES data/icon_16.png DESTINATION share/icons/hicolor/16x16/apps RENAME ${PNAME}.png)
install(FILES data/icon_20.png DESTINATION share/icons/hicolor/20x20/apps RENAME ${PNAME}.png)
install(FILES data/icon_22.png DESTINATION share/icons/hicolor/22x22/apps RENAME ${PNAME}.png)
install(FILES data/icon_24.png DESTINATION share/icons/hicolor/24x24/apps RENAME ${PNAME}.png)
install(FILES data/icon_42.png DESTINATION share/icons/hicolor/42x42/apps RENAME ${PNAME}.png)
install(FILES data/icon_48.png DESTINATION share/icons/hicolor/48x48/apps RENAME ${PNAME}.png)
install(FILES data/icon_64.png DESTINATION share/icons/hicolor/64x64/apps RENAME ${PNAME}.png)
