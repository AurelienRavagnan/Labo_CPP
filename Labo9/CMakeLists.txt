cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(ApplicGarage)

# Standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Trouver les modules Qt nécessaires
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# Répertoires d'includes
include_directories(${PROJECT_SOURCE_DIR}/includes)
include_directories(${PROJECT_SOURCE_DIR})

# Fichiers source du projet
set(SOURCES
    InterfaceQt/main.cpp
    InterfaceQt/applicgaragewindow.cpp
    InterfaceQt/moc_applicgaragewindow.cpp
    sources/Car.cpp
    sources/Model.cpp
    sources/Option.cpp
    sources/Employee.cpp
    sources/Client.cpp
    sources/Actor.cpp
    sources/Garage.cpp
    sources/Option.cpp
    sources/Exception.cpp
    sources/OptionException.cpp
    sources/PasswordException.cpp
    sources/Person.cpp
)

# Fichier UI généré 
# qt5_wrap_ui(UI_HEADERS ui/applicgaragewindow.ui)

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier Qt
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

