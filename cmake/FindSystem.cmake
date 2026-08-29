set(name system)
set(tag main)

# CHERCHER, puis seulement rapatrier. Ce module ne faisait que le dernier
# tiers : il ne savait repondre qu'a "est-ce que J'AI deja telecharge ca ?",
# ce qui laissait passer tout le reste.

# 1. La cible existe deja dans cet arbre - un autre depot l'a amenee avant
#    nous, ou un add_subdirectory l'a posee. On ne la reclone pas par-dessus.
if (TARGET ${name})
    return()
endif()

# 2. Ton checkout, s'il est la. Quand tu travailles en local, ce depot et
#    ${name} sont voisins de palier, et c'est CE code-la qu'il faut
#    compiler - pas la version poussee sur GitHub. Sans cette etape, on lit
#    un fichier et on en compile un autre.
#
#    Par FETCHCONTENT_SOURCE_DIR plutot que par un add_subdirectory : un
#    seul chemin de code ensuite. Et sans FORCE, donc un -D en ligne de
#    commande reste prioritaire.
get_filename_component(_neighbour "${CMAKE_CURRENT_LIST_DIR}/../../${name}" ABSOLUTE)
if (EXISTS "${_neighbour}/CMakeLists.txt")
    string(TOUPPER "${name}" _upper)
    set(FETCHCONTENT_SOURCE_DIR_${_upper} "${_neighbour}" CACHE PATH
        "checkout local de ${name}")
    unset(_upper)
endif()
unset(_neighbour)

# 3. Sinon GitHub.
include(FetchContent)
FetchContent_GetProperties(${name})
if (NOT ${name}_POPULATED)
    FetchContent_Declare(
        ${name}
        GIT_REPOSITORY https://github.com/P-E-R-R-Y/${name}.git
        GIT_TAG ${tag}
    )
    FetchContent_MakeAvailable(${name})
endif()
