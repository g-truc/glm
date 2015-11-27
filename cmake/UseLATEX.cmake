# File: UseLATEX.cmake
# CMAKE commands to actually use the LaTeX compiler
# Version: 2.2.0
# Author: Kenneth Moreland <kmorel@sandia.gov>
#
# Copyright 2004, 2015 Sandia Corporation.
# Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
# license for use of this work by or on behalf of the U.S. Government.
#
# This software is released under the BSD 3-Clause License.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
# contributors may be used to endorse or promote products derived from this
# software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
# IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#
# The following function is defined:
#
# add_latex_document(<tex_file>
#                    [BIBFILES <bib_files>]
#                    [INPUTS <input_tex_files>]
#                    [IMAGE_DIRS] <image_directories>
#                    [IMAGES] <image_files>
#                    [CONFIGURE] <tex_files>
#                    [DEPENDS] <tex_files>
#                    [MULTIBIB_NEWCITES] <suffix_list>
#                    [USE_INDEX]
#                    [INDEX_NAMES <index_names>]
#                    [USE_GLOSSARY] [USE_NOMENCL]
#                    [FORCE_PDF] [FORCE_DVI] [FORCE_HTML]
#                    [TARGET_NAME] <name>
#                    [EXCLUDE_FROM_ALL]
#                    [EXCLUDE_FROM_DEFAULTS])
#       Adds targets that compile <tex_file>.  The latex output is placed
#       in LATEX_OUTPUT_PATH or CMAKE_CURRENT_BINARY_DIR if the former is
#       not set.  The latex program is picky about where files are located,
#       so all input files are copied from the source directory to the
#       output directory.  This includes the target tex file, any tex file
#       listed with the INPUTS option, the bibliography files listed with
#       the BIBFILES option, and any .cls, .bst, and .clo files found in
#       the current source directory.  Images found in the IMAGE_DIRS
#       directories or listed by IMAGES are also copied to the output
#       directory and converted to an appropriate format if necessary.  Any
#       tex files also listed with the CONFIGURE option are also processed
#       with the CMake CONFIGURE_FILE command (with the @ONLY flag).  Any
#       file listed in CONFIGURE but not the target tex file or listed with
#       INPUTS has no effect. DEPENDS can be used to specify generated files
#       that are needed to compile the latex target.
#
#       The following targets are made. The name prefix is based off of the
#       base name of the tex file unless TARGET_NAME is specified. If
#       TARGET_NAME is specified, then that name is used for the targets.
#
#               name_dvi: Makes <name>.dvi
#               name_pdf: Makes <name>.pdf using pdflatex.
#               name_safepdf: Makes <name>.pdf using ps2pdf.  If using the
#                       default program arguments, this will ensure all fonts
#                       are embedded and no lossy compression has been
#                       performed on images.
#               name_ps: Makes <name>.ps
#               name_html: Makes <name>.html
#               name_auxclean: Deletes <name>.aux and other auxiliary files.
#                       This is sometimes necessary if a LaTeX error occurs
#                       and writes a bad aux file.  Unlike the regular clean
#                       target, it does not delete other input files, such as
#                       converted images, to save time on the rebuild.
#
#       Unless the EXCLUDE_FROM_ALL option is given, one of these targets
#       is added to the ALL target and built by default. Which target is
#       determined by the LATEX_DEFAULT_BUILD CMake variable. See the
#       documentation of that variable for more details.
#
#       Unless the EXCLUDE_FROM_DEFAULTS option is given, all these targets
#       are added as dependencies to targets named dvi, pdf, safepdf, ps,
#       html, and auxclean, respectively.
#
#       If the argument USE_INDEX is given, then commands to build an index
#       are made. If the argument INDEX_NAMES is given, an index file is
#       generated for each name in this list. See the LaTeX package multind
#       for more information about how to generate multiple indices.
#
#       If the argument USE_GLOSSARY is given, then commands to
#       build a glossary are made.  If the argument MULTIBIB_NEWCITES is
#       given, then additional bibtex calls are added to the build to
#       support the extra auxiliary files created with the \newcite command
#       in the multibib package.
#
# History:
#
# 2.1.1 Support for finding bmp, ppm, and other image files.
#
# 2.1.0 Fix an error where the pdf target and others were defined multiple
#       times if UseLATEX.cmake was included multiple times.
#
#       Added INDEX_NAMES option to support multiple indexes in a single
#       document from the multind package (thanks to Dan Lipsa).
#
# 2.0.0 First major revision of UseLATEX.cmake updates to more recent features
#       of CMake and some non-backward compatible changes.
#
#       Changed all function and macro names to lower case. CMake's identifiers
#       are case insensitive, but the convention moved from all upper case to
#       all lower case somewhere around the release of CMake 2. (The original
#       version of UseLATEX.cmake predates that.)
#
#       Remove condition matching in if statements. They are no longer necessary
#       and are even discouraged (because else clauses get confusing).
#
#       Use "new" features available in CMake such as list and argument parsing.
#
#       Remove some code that has been deprecated for a while.
#
#       Mark variables for compiler and converter executables as advanced to
#       match the more conventional CMake behavior.
#
#       Changed how default builds are specified and add the ability to force
#       a particular build.
#
#       Made the base targets (pdf, dvi, etc.) global. add_latex_document
#       always mangles its target names and these base targets depend on
#       the targets with mangled names.
#
# 1.10.5 Fix for Window's convert check (thanks to Martin Baute).
#
# 1.10.4 Copy font files to binary directory for packages that come with
#       their own fonts.
#
# 1.10.3 Check for Windows version of convert being used instead of
#       ImageMagick's version (thanks to Martin Baute).
#
# 1.10.2 Use htlatex as a fallback when latex2html is not available (thanks
#       to Tomasz Grzegurzko).
#
# 1.10.1 Make convert program mandatory only if actually used (thanks to
#       Julien Schueller).
#
# 1.10.0 Added NO_DEFAULT and DEFAULT_PS options.
#       Fixed issue with cleaning files for LaTeX documents originating in
#       a subdirectory.
#
# 1.9.6 Fixed problem with LATEX_SMALL_IMAGES.
#       Strengthened check to make sure the output directory does not contain
#       the source files.
#
# 1.9.5 Add support for image types not directly supported by either latex
#       or pdflatex.  (Thanks to Jorge Gerardo Pena Pastor for SVG support.)
#
# 1.9.4 Fix issues with filenames containing multiple periods.
#
# 1.9.3 Hide some variables that are now cached but should not show up in
#       the ccmake list of variables.
#
# 1.9.2 Changed MACRO declarations to FUNCTION declarations.  The better
#       FUNCTION scoping will hopefully avoid some common but subtle bugs.
#       This implicitly increases the minimum CMake version to 4.6 (although
#       I honestly only test it with the latest 4.8 version).
#
#       Since we are updating the minimum CMake version, I'm going to start
#       using the builtin LIST commands that are now available.
#
#       Favor using pdftops from the Poppler package to convert from pdf to
#       eps.  It does a much better job than ImageMagick or ghostscript.
#
# 1.9.1 Fixed typo that caused the LATEX_SMALL_IMAGES option to fail to
#       activate.
#
# 1.9.0 Add support for the multibib package (thanks to Antonio LaTorre).
#
# 1.8.2 Fix corner case when an argument name was also a variable containing
#       the text of an argument.  In this case, the CMake IF was matching
#       the argument text with the contents of the variable with the same
#       argument name.
#
# 1.8.1 Fix problem where ps2pdf was not getting the appropriate arguments.
#
# 1.8.0 Add support for synctex.
#
# 1.7.7 Support calling xindy when making glossaries.
#
#       Improved make clean support.
#
# 1.7.6 Add support for the nomencl package (thanks to Myles English).
#
# 1.7.5 Fix issue with bibfiles being copied two different ways, which causes
#       Problems with dependencies (thanks to Edwin van Leeuwen).
#
# 1.7.4 Added the DEFAULT_SAFEPDF option (thanks to Raymond Wan).
#
#       Added warnings when image directories are not found (and were
#       probably not given relative to the source directory).
#
# 1.7.3 Fix some issues with interactions between makeglossaries and bibtex
#       (thanks to Mark de Wever).
#
# 1.7.2 Use ps2pdf to convert eps to pdf to get around the problem with
#       ImageMagick dropping the bounding box (thanks to Lukasz Lis).
#
# 1.7.1 Fixed some dependency issues.
#
# 1.7.0 Added DEPENDS options (thanks to Theodore Papadopoulo).
#
# 1.6.1 Ported the makeglossaries command to CMake and embedded the port
#       into UseLATEX.cmake.
#
# 1.6.0 Allow the use of the makeglossaries command.  Thanks to Oystein
#       S. Haaland for the patch.
#
# 1.5.0 Allow any type of file in the INPUTS lists, not just tex file
#       (suggested by Eric Noulard).  As a consequence, the ability to
#       specify tex files without the .tex extension is removed.  The removed
#       function is of dubious value anyway.
#
#       When copying input files, skip over any file that exists in the
#       binary directory but does not exist in the source directory with the
#       assumption that these files were added by some other mechanism.  I
#       find this useful when creating large documents with multiple
#       chapters that I want to build separately (for speed) as I work on
#       them.  I use the same boilerplate as the starting point for all
#       and just copy it with different configurations.  This was what the
#       separate ADD_LATEX_DOCUMENT method was supposed to originally be for.
#       Since its external use is pretty much deprecated, I removed that
#       documentation.
#
# 1.4.1 Copy .sty files along with the other class and package files.
#
# 1.4.0 Added a MANGLE_TARGET_NAMES option that will mangle the target names.
#
#       Fixed problem with copying bib files that became apparent with
#       CMake 2.4.
#
# 1.3.0 Added a LATEX_OUTPUT_PATH variable that allows you or the user to
#       specify where the built latex documents to go.  This is especially
#       handy if you want to do in-source builds.
#
#       Removed the ADD_LATEX_IMAGES macro and absorbed the functionality
#       into ADD_LATEX_DOCUMENT.  The old interface was always kind of
#       clunky anyway since you had to specify the image directory in both
#       places.  It also made supporting LATEX_OUTPUT_PATH problematic.
#
#       Added support for jpeg files.
#
# 1.2.0 Changed the configuration options yet again.  Removed the NO_CONFIGURE
#       Replaced it with a CONFIGURE option that lists input files for which
#       configure should be run.
#
#       The pdf target no longer depends on the dvi target.  This allows you
#       to build latex documents that require pdflatex.  Also added an option
#       to make the pdf target the default one.
#
# 1.1.1 Added the NO_CONFIGURE option.  The @ character can be used when
#       specifying table column separators.  If two or more are used, then
#       will incorrectly substitute them.
#
# 1.1.0 Added ability include multiple bib files.  Added ability to do copy
#       sub-tex files for multipart tex files.
#
# 1.0.0 If both ps and pdf type images exist, just copy the one that
#       matches the current render mode.  Replaced a bunch of STRING
#       commands with GET_FILENAME_COMPONENT commands that were made to do
#       the desired function.
#
# 0.4.0 First version posted to CMake Wiki.
#

if(__USE_LATEX_INCLUDED)
  return()
endif()
set(__USE_LATEX_INCLUDED TRUE)

#############################################################################
# Find the location of myself while originally executing.  If you do this
# inside of a macro, it will recode where the macro was invoked.
#############################################################################
set(LATEX_USE_LATEX_LOCATION ${CMAKE_CURRENT_LIST_FILE}
  CACHE INTERNAL "Location of UseLATEX.cmake file." FORCE
  )

#############################################################################
# Generic helper functions
#############################################################################

include(CMakeParseArguments)

function(latex_list_contains var value)
  set(input_list ${ARGN})
  list(FIND input_list "${value}" index)
  if(index GREATER -1)
    set(${var} TRUE PARENT_SCOPE)
  else()
    set(${var} PARENT_SCOPE)
  endif()
endfunction(latex_list_contains)

# Match the contents of a file to a regular expression.
function(latex_file_match variable filename regexp default)
  # The FILE STRINGS command would be a bit better, but I'm not totally sure
  # the match will always be to a whole line, and I don't want to break things.
  file(READ ${filename} file_contents)
  string(REGEX MATCHALL "${regexp}"
    match_result ${file_contents}
    )
  if(match_result)
    set(${variable} "${match_result}" PARENT_SCOPE)
  else()
    set(${variable} "${default}" PARENT_SCOPE)
  endif()
endfunction(latex_file_match)

# A version of GET_FILENAME_COMPONENT that treats extensions after the last
# period rather than the first.  To the best of my knowledge, all filenames
# typically used by LaTeX, including image files, have small extensions
# after the last dot.
function(latex_get_filename_component varname filename type)
  set(result)
  if("${type}" STREQUAL "NAME_WE")
    get_filename_component(name ${filename} NAME)
    string(REGEX REPLACE "\\.[^.]*\$" "" result "${name}")
  elseif("${type}" STREQUAL "EXT")
    get_filename_component(name ${filename} NAME)
    string(REGEX MATCH "\\.[^.]*\$" result "${name}")
  else()
    get_filename_component(result ${filename} ${type})
  endif()
  set(${varname} "${result}" PARENT_SCOPE)
endfunction(latex_get_filename_component)

#############################################################################
# Functions that perform processing during a LaTeX build.
#############################################################################
function(latex_makeglossaries)
  # This is really a bare bones port of the makeglossaries perl script into
  # CMake scripting.
  message("**************************** In makeglossaries")
  if(NOT LATEX_TARGET)
    message(SEND_ERROR "Need to define LATEX_TARGET")
  endif()

  set(aux_file ${LATEX_TARGET}.aux)

  if(NOT EXISTS ${aux_file})
    message(SEND_ERROR "${aux_file} does not exist.  Run latex on your target file.")
  endif()

  latex_file_match(newglossary_lines ${aux_file}
    "@newglossary[ \t]*{([^}]*)}{([^}]*)}{([^}]*)}{([^}]*)}"
    "@newglossary{main}{glg}{gls}{glo}"
    )

  latex_file_match(istfile_line ${aux_file}
    "@istfilename[ \t]*{([^}]*)}"
    "@istfilename{${LATEX_TARGET}.ist}"
    )
  string(REGEX REPLACE "@istfilename[ \t]*{([^}]*)}" "\\1"
    istfile ${istfile_line}
    )

  string(REGEX MATCH ".*\\.xdy" use_xindy "${istfile}")
  if(use_xindy)
    message("*************** Using xindy")
    if(NOT XINDY_COMPILER)
      message(SEND_ERROR "Need to define XINDY_COMPILER")
    endif()
  else()
    message("*************** Using makeindex")
    if(NOT MAKEINDEX_COMPILER)
      message(SEND_ERROR "Need to define MAKEINDEX_COMPILER")
    endif()
  endif()

  foreach(newglossary ${newglossary_lines})
    string(REGEX REPLACE
      "@newglossary[ \t]*{([^}]*)}{([^}]*)}{([^}]*)}{([^}]*)}"
      "\\1" glossary_name ${newglossary}
      )
    string(REGEX REPLACE
      "@newglossary[ \t]*{([^}]*)}{([^}]*)}{([^}]*)}{([^}]*)}"
      "${LATEX_TARGET}.\\2" glossary_log ${newglossary}
      )
    string(REGEX REPLACE
      "@newglossary[ \t]*{([^}]*)}{([^}]*)}{([^}]*)}{([^}]*)}"
      "${LATEX_TARGET}.\\3" glossary_out ${newglossary}
      )
    string(REGEX REPLACE
      "@newglossary[ \t]*{([^}]*)}{([^}]*)}{([^}]*)}{([^}]*)}"
      "${LATEX_TARGET}.\\4" glossary_in ${newglossary}
      )

    if(use_xindy)
      latex_file_match(xdylanguage_line ${aux_file}
        "@xdylanguage[ \t]*{${glossary_name}}{([^}]*)}"
        "@xdylanguage{${glossary_name}}{english}"
        )
      string(REGEX REPLACE
        "@xdylanguage[ \t]*{${glossary_name}}{([^}]*)}"
        "\\1"
        language
        ${xdylanguage_line}
        )
      # What crazy person makes a LaTeX index generator that uses different
      # identifiers for language than babel (or at least does not support
      # the old ones)?
      if(${language} STREQUAL "frenchb")
        set(language "french")
      elseif(${language} MATCHES "^n?germanb?$")
        set(language "german")
      elseif(${language} STREQUAL "magyar")
        set(language "hungarian")
      elseif(${language} STREQUAL "lsorbian")
        set(language "lower-sorbian")
      elseif(${language} STREQUAL "norsk")
        set(language "norwegian")
      elseif(${language} STREQUAL "portuges")
        set(language "portuguese")
      elseif(${language} STREQUAL "russianb")
        set(language "russian")
      elseif(${language} STREQUAL "slovene")
        set(language "slovenian")
      elseif(${language} STREQUAL "ukraineb")
        set(language "ukrainian")
      elseif(${language} STREQUAL "usorbian")
        set(language "upper-sorbian")
      endif()
      if(language)
        set(language_flags "-L ${language}")
      else()
        set(language_flags "")
      endif()

      latex_file_match(codepage_line ${aux_file}
        "@gls@codepage[ \t]*{${glossary_name}}{([^}]*)}"
        "@gls@codepage{${glossary_name}}{utf}"
        )
      string(REGEX REPLACE
        "@gls@codepage[ \t]*{${glossary_name}}{([^}]*)}"
        "\\1"
        codepage
        ${codepage_line}
        )
      if(codepage)
        set(codepage_flags "-C ${codepage}")
      else()
        # Ideally, we would check that the language is compatible with the
        # default codepage, but I'm hoping that distributions will be smart
        # enough to specify their own codepage.  I know, it's asking a lot.
        set(codepage_flags "")
      endif()

      message("${XINDY_COMPILER} ${MAKEGLOSSARIES_COMPILER_FLAGS} ${language_flags} ${codepage_flags} -I xindy -M ${glossary_name} -t ${glossary_log} -o ${glossary_out} ${glossary_in}"
        )
      exec_program(${XINDY_COMPILER}
        ARGS ${MAKEGLOSSARIES_COMPILER_FLAGS}
          ${language_flags}
          ${codepage_flags}
          -I xindy
          -M ${glossary_name}
          -t ${glossary_log}
          -o ${glossary_out}
          ${glossary_in}
        OUTPUT_VARIABLE xindy_output
        )
      message("${xindy_output}")

      # So, it is possible (perhaps common?) for aux files to specify a
      # language and codepage that are incompatible with each other.  Check
      # for that condition, and if it happens run again with the default
      # codepage.
      if("${xindy_output}" MATCHES "^Cannot locate xindy module for language (.+) in codepage (.+)\\.$")
        message("*************** Retrying xindy with default codepage.")
        exec_program(${XINDY_COMPILER}
          ARGS ${MAKEGLOSSARIES_COMPILER_FLAGS}
            ${language_flags}
            -I xindy
            -M ${glossary_name}
            -t ${glossary_log}
            -o ${glossary_out}
            ${glossary_in}
          )
      endif()

    else()
      message("${MAKEINDEX_COMPILER} ${MAKEGLOSSARIES_COMPILER_FLAGS} -s ${istfile} -t ${glossary_log} -o ${glossary_out} ${glossary_in}")
      exec_program(${MAKEINDEX_COMPILER} ARGS ${MAKEGLOSSARIES_COMPILER_FLAGS}
        -s ${istfile} -t ${glossary_log} -o ${glossary_out} ${glossary_in}
        )
    endif()

  endforeach(newglossary)
endfunction(latex_makeglossaries)

function(latex_makenomenclature)
  message("**************************** In makenomenclature")
  if(NOT LATEX_TARGET)
    message(SEND_ERROR "Need to define LATEX_TARGET")
  endif()

  if(NOT MAKEINDEX_COMPILER)
    message(SEND_ERROR "Need to define MAKEINDEX_COMPILER")
  endif()

  set(nomencl_out ${LATEX_TARGET}.nls)
  set(nomencl_in ${LATEX_TARGET}.nlo)

  exec_program(${MAKEINDEX_COMPILER} ARGS ${MAKENOMENCLATURE_COMPILER_FLAGS}
    ${nomencl_in} -s "nomencl.ist" -o ${nomencl_out}
    )
endfunction(latex_makenomenclature)

function(latex_correct_synctex)
  message("**************************** In correct SyncTeX")
  if(NOT LATEX_TARGET)
    message(SEND_ERROR "Need to define LATEX_TARGET")
  endif()

  if(NOT GZIP)
    message(SEND_ERROR "Need to define GZIP")
  endif()

  if(NOT LATEX_SOURCE_DIRECTORY)
    message(SEND_ERROR "Need to define LATEX_SOURCE_DIRECTORY")
  endif()

  if(NOT LATEX_BINARY_DIRECTORY)
    message(SEND_ERROR "Need to define LATEX_BINARY_DIRECTORY")
  endif()

  set(synctex_file ${LATEX_BINARY_DIRECTORY}/${LATEX_TARGET}.synctex)
  set(synctex_file_gz ${synctex_file}.gz)

  if(EXISTS ${synctex_file_gz})

    message("Making backup of synctex file.")
    configure_file(${synctex_file_gz} ${synctex_file}.bak.gz COPYONLY)

    message("Uncompressing synctex file.")
    exec_program(${GZIP}
      ARGS --decompress ${synctex_file_gz}
      )

    message("Reading synctex file.")
    file(READ ${synctex_file} synctex_data)

    message("Replacing relative with absolute paths.")
    string(REGEX REPLACE
      "(Input:[0-9]+:)([^/\n][^\n]*)"
      "\\1${LATEX_SOURCE_DIRECTORY}/\\2"
      synctex_data
      "${synctex_data}"
      )

    message("Writing synctex file.")
    file(WRITE ${synctex_file} "${synctex_data}")

    message("Compressing synctex file.")
    exec_program(${GZIP}
      ARGS ${synctex_file}
      )

  else()

    message(SEND_ERROR "File ${synctex_file_gz} not found.  Perhaps synctex is not supported by your LaTeX compiler.")

  endif()

endfunction(latex_correct_synctex)

#############################################################################
# Helper functions for establishing LaTeX build.
#############################################################################

function(latex_needit VAR NAME)
  if(NOT ${VAR})
    message(SEND_ERROR "I need the ${NAME} command.")
  endif()
endfunction(latex_needit)

function(latex_wantit VAR NAME)
  if(NOT ${VAR})
    message(STATUS "I could not find the ${NAME} command.")
  endif()
endfunction(latex_wantit)

function(latex_setup_variables)
  set(LATEX_OUTPUT_PATH "${LATEX_OUTPUT_PATH}"
    CACHE PATH "If non empty, specifies the location to place LaTeX output."
    )

  find_package(LATEX)

  find_program(XINDY_COMPILER
    NAME xindy
    PATHS ${MIKTEX_BINARY_PATH} /usr/bin
    )

  find_package(UnixCommands)

  find_program(PDFTOPS_CONVERTER
    NAMES pdftops
    DOC "The pdf to ps converter program from the Poppler package."
    )

  mark_as_advanced(
    LATEX_COMPILER
    PDFLATEX_COMPILER
    BIBTEX_COMPILER
    MAKEINDEX_COMPILER
    XINDY_COMPILER
    DVIPS_CONVERTER
    PS2PDF_CONVERTER
    PDFTOPS_CONVERTER
    LATEX2HTML_CONVERTER
    )

  latex_needit(LATEX_COMPILER latex)
  latex_wantit(PDFLATEX_COMPILER pdflatex)
  latex_needit(BIBTEX_COMPILER bibtex)
  latex_needit(MAKEINDEX_COMPILER makeindex)
  latex_wantit(DVIPS_CONVERTER dvips)
  latex_wantit(PS2PDF_CONVERTER ps2pdf)
  latex_wantit(PDFTOPS_CONVERTER pdftops)
  # MiKTeX calls latex2html htlatex
  if(NOT ${LATEX2HTML_CONVERTER})
    find_program(HTLATEX_CONVERTER
      NAMES htlatex
      PATHS ${MIKTEX_BINARY_PATH}
            /usr/bin
      )
    mark_as_advanced(HTLATEX_CONVERTER)
    if(HTLATEX_CONVERTER)
      set(USING_HTLATEX TRUE CACHE INTERNAL "True when using MiKTeX htlatex instead of latex2html" FORCE)
      set(LATEX2HTML_CONVERTER ${HTLATEX_CONVERTER}
        CACHE FILEPATH "htlatex taking the place of latex2html" FORCE)
    else()
      set(USING_HTLATEX FALSE CACHE INTERNAL "True when using MiKTeX htlatex instead of latex2html" FORCE)
    endif()
  endif()
  latex_wantit(LATEX2HTML_CONVERTER latex2html)

  set(LATEX_COMPILER_FLAGS "-interaction=nonstopmode"
    CACHE STRING "Flags passed to latex.")
  set(PDFLATEX_COMPILER_FLAGS ${LATEX_COMPILER_FLAGS}
    CACHE STRING "Flags passed to pdflatex.")
  set(LATEX_SYNCTEX_FLAGS "-synctex=1"
    CACHE STRING "latex/pdflatex flags used to create synctex file.")
  set(BIBTEX_COMPILER_FLAGS ""
    CACHE STRING "Flags passed to bibtex.")
  set(MAKEINDEX_COMPILER_FLAGS ""
    CACHE STRING "Flags passed to makeindex.")
  set(MAKEGLOSSARIES_COMPILER_FLAGS ""
    CACHE STRING "Flags passed to makeglossaries.")
  set(MAKENOMENCLATURE_COMPILER_FLAGS ""
    CACHE STRING "Flags passed to makenomenclature.")
  set(DVIPS_CONVERTER_FLAGS "-Ppdf -G0 -t letter"
    CACHE STRING "Flags passed to dvips.")
  set(PS2PDF_CONVERTER_FLAGS "-dMaxSubsetPct=100 -dCompatibilityLevel=1.3 -dSubsetFonts=true -dEmbedAllFonts=true -dAutoFilterColorImages=false -dAutoFilterGrayImages=false -dColorImageFilter=/FlateEncode -dGrayImageFilter=/FlateEncode -dMonoImageFilter=/FlateEncode"
    CACHE STRING "Flags passed to ps2pdf.")
  set(PDFTOPS_CONVERTER_FLAGS -r 600
    CACHE STRING "Flags passed to pdftops.")
  set(LATEX2HTML_CONVERTER_FLAGS ""
    CACHE STRING "Flags passed to latex2html.")
  mark_as_advanced(
    LATEX_COMPILER_FLAGS
    PDFLATEX_COMPILER_FLAGS
    LATEX_SYNCTEX_FLAGS
    BIBTEX_COMPILER_FLAGS
    MAKEINDEX_COMPILER_FLAGS
    MAKEGLOSSARIES_COMPILER_FLAGS
    MAKENOMENCLATURE_COMPILER_FLAGS
    DVIPS_CONVERTER_FLAGS
    PS2PDF_CONVERTER_FLAGS
    PDFTOPS_CONVERTER_FLAGS
    LATEX2HTML_CONVERTER_FLAGS
    )
  separate_arguments(LATEX_COMPILER_FLAGS)
  separate_arguments(PDFLATEX_COMPILER_FLAGS)
  separate_arguments(LATEX_SYNCTEX_FLAGS)
  separate_arguments(BIBTEX_COMPILER_FLAGS)
  separate_arguments(MAKEINDEX_COMPILER_FLAGS)
  separate_arguments(MAKEGLOSSARIES_COMPILER_FLAGS)
  separate_arguments(MAKENOMENCLATURE_COMPILER_FLAGS)
  separate_arguments(DVIPS_CONVERTER_FLAGS)
  separate_arguments(PS2PDF_CONVERTER_FLAGS)
  separate_arguments(PDFTOPS_CONVERTER_FLAGS)
  separate_arguments(LATEX2HTML_CONVERTER_FLAGS)

  find_program(IMAGEMAGICK_CONVERT convert
    DOC "The convert program that comes with ImageMagick (available at http://www.imagemagick.org)."
    )
  mark_as_advanced(IMAGEMAGICK_CONVERT)

  if(DEFINED ENV{LATEX_DEFAULT_BUILD})
    set(default_build $ENV{LATEX_DEFAULT_BUILD})
  else()
    set(default_build Pdf)
  endif()

  set(LATEX_DEFAULT_BUILD "${default_build}" CACHE STRING
    "Choose the default type of LaTeX build. Valid options are Pdf, Dvi, Ps, SafePdf, Html"
    )

  option(LATEX_USE_SYNCTEX
    "If on, have LaTeX generate a synctex file, which WYSIWYG editors can use to correlate output files like dvi and pdf with the lines of LaTeX source that generates them.  In addition to adding the LATEX_SYNCTEX_FLAGS to the command line, this option also adds build commands that \"corrects\" the resulting synctex file to point to the original LaTeX files rather than those generated by UseLATEX.cmake."
    OFF
    )

  option(LATEX_SMALL_IMAGES
    "If on, the raster images will be converted to 1/6 the original size.  This is because papers usually require 600 dpi images whereas most monitors only require at most 96 dpi.  Thus, smaller images make smaller files for web distribution and can make it faster to read dvi files."
    OFF)
  if(LATEX_SMALL_IMAGES)
    set(LATEX_RASTER_SCALE 16 PARENT_SCOPE)
    set(LATEX_OPPOSITE_RASTER_SCALE 100 PARENT_SCOPE)
  else()
    set(LATEX_RASTER_SCALE 100 PARENT_SCOPE)
    set(LATEX_OPPOSITE_RASTER_SCALE 16 PARENT_SCOPE)
  endif()

  # Just holds extensions for known image types.  They should all be lower case.
  # For historical reasons, these are all declared in the global scope.
  set(LATEX_DVI_VECTOR_IMAGE_EXTENSIONS .eps CACHE INTERNAL "")
  set(LATEX_DVI_RASTER_IMAGE_EXTENSIONS CACHE INTERNAL "")
  set(LATEX_DVI_IMAGE_EXTENSIONS
    ${LATEX_DVI_VECTOR_IMAGE_EXTENSIONS}
    ${LATEX_DVI_RASTER_IMAGE_EXTENSIONS}
    CACHE INTERNAL ""
    )

  set(LATEX_PDF_VECTOR_IMAGE_EXTENSIONS .pdf CACHE INTERNAL "")
  set(LATEX_PDF_RASTER_IMAGE_EXTENSIONS .jpeg .jpg .png CACHE INTERNAL "")
  set(LATEX_PDF_IMAGE_EXTENSIONS
    ${LATEX_PDF_VECTOR_IMAGE_EXTENSIONS}
    ${LATEX_PDF_RASTER_IMAGE_EXTENSIONS}
    CACHE INTERNAL ""
    )

  set(LATEX_OTHER_VECTOR_IMAGE_EXTENSIONS .ai .dot .svg CACHE INTERNAL "")
  set(LATEX_OTHER_RASTER_IMAGE_EXTENSIONS
    .bmp .bmp2 .bmp3 .dcm .dcx .ico .gif .pict .ppm .tif .tiff
    CACHE INTERNAL "")
  set(LATEX_OTHER_IMAGE_EXTENSIONS
    ${LATEX_OTHER_VECTOR_IMAGE_EXTENSIONS}
    ${LATEX_OTHER_RASTER_IMAGE_EXTENSIONS}
    CACHE INTERNAL ""
    )

  set(LATEX_VECTOR_IMAGE_EXTENSIONS
    ${LATEX_DVI_VECTOR_IMAGE_EXTENSIONS}
    ${LATEX_PDF_VECTOR_IMAGE_EXTENSIONS}
    ${LATEX_OTHER_VECTOR_IMAGE_EXTENSIONS}
    CACHE INTERNAL ""
    )
  set(LATEX_RASTER_IMAGE_EXTENSIONS
    ${LATEX_DVI_RASTER_IMAGE_EXTENSIONS}
    ${LATEX_PDF_RASTER_IMAGE_EXTENSIONS}
    ${LATEX_OTHER_RASTER_IMAGE_EXTENSIONS}
    CACHE INTERNAL ""
    )
  set(LATEX_IMAGE_EXTENSIONS
    ${LATEX_DVI_IMAGE_EXTENSIONS}
    ${LATEX_PDF_IMAGE_EXTENSIONS}
    ${LATEX_OTHER_IMAGE_EXTENSIONS}
    CACHE INTERNAL ""
    )
endfunction(latex_setup_variables)

function(latex_setup_targets)
  if(NOT TARGET pdf)
    add_custom_target(pdf)
  endif()
  if(NOT TARGET dvi)
    add_custom_target(dvi)
  endif()
  if(NOT TARGET ps)
    add_custom_target(ps)
  endif()
  if(NOT TARGET safepdf)
    add_custom_target(safepdf)
  endif()
  if(NOT TARGET html)
    add_custom_target(html)
  endif()
  if(NOT TARGET auxclean)
    add_custom_target(auxclean)
  endif()
endfunction(latex_setup_targets)

function(latex_get_output_path var)
  set(latex_output_path)
  if(LATEX_OUTPUT_PATH)
    get_filename_component(
      LATEX_OUTPUT_PATH_FULL "${LATEX_OUTPUT_PATH}" ABSOLUTE
      )
    if("${LATEX_OUTPUT_PATH_FULL}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
      message(SEND_ERROR "You cannot set LATEX_OUTPUT_PATH to the same directory that contains LaTeX input files.")
    else()
      set(latex_output_path "${LATEX_OUTPUT_PATH_FULL}")
    endif()
  else()
    if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
      message(SEND_ERROR "LaTeX files must be built out of source or you must set LATEX_OUTPUT_PATH.")
    else()
      set(latex_output_path "${CMAKE_CURRENT_BINARY_DIR}")
    endif()
  endif()
  set(${var} ${latex_output_path} PARENT_SCOPE)
endfunction(latex_get_output_path)

function(latex_add_convert_command
    output_path
    input_path
    output_extension
    input_extension
    flags
    )
  set(require_imagemagick_convert TRUE)
  set(convert_flags "")
  if(${input_extension} STREQUAL ".eps" AND ${output_extension} STREQUAL ".pdf")
    # ImageMagick has broken eps to pdf conversion
    # use ps2pdf instead
    if(PS2PDF_CONVERTER)
      set(require_imagemagick_convert FALSE)
      set(converter ${PS2PDF_CONVERTER})
      set(convert_flags -dEPSCrop ${PS2PDF_CONVERTER_FLAGS})
    else()
      message(SEND_ERROR "Using postscript files with pdflatex requires ps2pdf for conversion.")
    endif()
  elseif(${input_extension} STREQUAL ".pdf" AND ${output_extension} STREQUAL ".eps")
    # ImageMagick can also be sketchy on pdf to eps conversion.  Not good with
    # color spaces and tends to unnecessarily rasterize.
    # use pdftops instead
    if(PDFTOPS_CONVERTER)
      set(require_imagemagick_convert FALSE)
      set(converter ${PDFTOPS_CONVERTER})
      set(convert_flags -eps ${PDFTOPS_CONVERTER_FLAGS})
    else()
      message(STATUS "Consider getting pdftops from Poppler to convert PDF images to EPS images.")
      set(convert_flags ${flags})
    endif()
  else()
    set(convert_flags ${flags})
  endif()

  if(require_imagemagick_convert)
    if(IMAGEMAGICK_CONVERT)
      string(TOLOWER ${IMAGEMAGICK_CONVERT} IMAGEMAGICK_CONVERT_LOWERCASE)
      if(${IMAGEMAGICK_CONVERT_LOWERCASE} MATCHES "system32[/\\\\]convert\\.exe")
        message(SEND_ERROR "IMAGEMAGICK_CONVERT set to Window's convert.exe for changing file systems rather than ImageMagick's convert for changing image formats.  Please make sure ImageMagick is installed (available at http://www.imagemagick.org) and its convert program is used for IMAGEMAGICK_CONVERT.  (It is helpful if ImageMagick's path is before the Windows system paths.)")
      else()
        set(converter ${IMAGEMAGICK_CONVERT})
      endif()
    else()
      message(SEND_ERROR "Could not find convert program. Please download ImageMagick from http://www.imagemagick.org and install.")
    endif()
  endif()

  add_custom_command(OUTPUT ${output_path}
    COMMAND ${converter}
      ARGS ${convert_flags} ${input_path} ${output_path}
    DEPENDS ${input_path}
    )
endfunction(latex_add_convert_command)

# Makes custom commands to convert a file to a particular type.
function(latex_convert_image
    output_files_var
    input_file
    output_extension
    convert_flags
    output_extensions
    other_files
    )
  set(output_file_list)
  set(input_dir ${CMAKE_CURRENT_SOURCE_DIR})
  latex_get_output_path(output_dir)

  latex_get_filename_component(extension "${input_file}" EXT)

  # Check input filename for potential problems with LaTeX.
  latex_get_filename_component(name "${input_file}" NAME_WE)
  if(name MATCHES ".*\\..*")
    string(REPLACE "." "-" suggested_name "${name}")
    set(suggested_name "${suggested_name}${extension}")
    message(WARNING "Some LaTeX distributions have problems with image file names with multiple extensions.  Consider changing ${name}${extension} to something like ${suggested_name}.")
  endif()

  string(REGEX REPLACE "\\.[^.]*\$" ${output_extension} output_file
    "${input_file}")

  latex_list_contains(is_type ${extension} ${output_extensions})
  if(is_type)
    if(convert_flags)
      latex_add_convert_command(${output_dir}/${output_file}
        ${input_dir}/${input_file} ${output_extension} ${extension}
        "${convert_flags}")
      set(output_file_list ${output_dir}/${output_file})
    else()
      # As a shortcut, we can just copy the file.
      add_custom_command(OUTPUT ${output_dir}/${input_file}
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy ${input_dir}/${input_file} ${output_dir}/${input_file}
        DEPENDS ${input_dir}/${input_file}
        )
      set(output_file_list ${output_dir}/${input_file})
    endif()
  else()
    set(do_convert TRUE)
    # Check to see if there is another input file of the appropriate type.
    foreach(valid_extension ${output_extensions})
      string(REGEX REPLACE "\\.[^.]*\$" ${output_extension} try_file
        "${input_file}")
      latex_list_contains(has_native_file "${try_file}" ${other_files})
      if(has_native_file)
        set(do_convert FALSE)
      endif()
    endforeach(valid_extension)

    # If we still need to convert, do it.
    if(do_convert)
      latex_add_convert_command(${output_dir}/${output_file}
        ${input_dir}/${input_file} ${output_extension} ${extension}
        "${convert_flags}")
      set(output_file_list ${output_dir}/${output_file})
    endif()
  endif()

  set(${output_files_var} ${output_file_list} PARENT_SCOPE)
endfunction(latex_convert_image)

# Adds custom commands to process the given files for dvi and pdf builds.
# Adds the output files to the given variables (does not replace).
function(latex_process_images dvi_outputs_var pdf_outputs_var)
  latex_get_output_path(output_dir)
  set(dvi_outputs)
  set(pdf_outputs)
  foreach(file ${ARGN})
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
      latex_get_filename_component(extension "${file}" EXT)
      set(convert_flags)

      # Check to see if we need to downsample the image.
      latex_list_contains(is_raster "${extension}"
        ${LATEX_RASTER_IMAGE_EXTENSIONS})
      if(LATEX_SMALL_IMAGES)
        if(is_raster)
          set(convert_flags -resize ${LATEX_RASTER_SCALE}%)
        endif()
      endif()

      # Make sure the output directory exists.
      latex_get_filename_component(path "${output_dir}/${file}" PATH)
      make_directory("${path}")

      # Do conversions for dvi.
      latex_convert_image(output_files "${file}" .eps "${convert_flags}"
        "${LATEX_DVI_IMAGE_EXTENSIONS}" "${ARGN}")
      list(APPEND dvi_outputs ${output_files})

      # Do conversions for pdf.
      if(is_raster)
        latex_convert_image(output_files "${file}" .png "${convert_flags}"
          "${LATEX_PDF_IMAGE_EXTENSIONS}" "${ARGN}")
        list(APPEND pdf_outputs ${output_files})
      else()
        latex_convert_image(output_files "${file}" .pdf "${convert_flags}"
          "${LATEX_PDF_IMAGE_EXTENSIONS}" "${ARGN}")
        list(APPEND pdf_outputs ${output_files})
      endif()
    else()
      message(WARNING "Could not find file ${CMAKE_CURRENT_SOURCE_DIR}/${file}.  Are you sure you gave relative paths to IMAGES?")
    endif()
  endforeach(file)

  set(${dvi_outputs_var} ${dvi_outputs} PARENT_SCOPE)
  set(${pdf_outputs_var} ${pdf_outputs} PARENT_SCOPE)
endfunction(latex_process_images)

function(latex_copy_globbed_files pattern dest)
  file(GLOB file_list ${pattern})
  foreach(in_file ${file_list})
    latex_get_filename_component(out_file ${in_file} NAME)
    configure_file(${in_file} ${dest}/${out_file} COPYONLY)
  endforeach(in_file)
endfunction(latex_copy_globbed_files)

function(latex_copy_input_file file)
  latex_get_output_path(output_dir)

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    latex_get_filename_component(path ${file} PATH)
    file(MAKE_DIRECTORY ${output_dir}/${path})

    latex_list_contains(use_config ${file} ${LATEX_CONFIGURE})
    if(use_config)
      configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${file}
        ${output_dir}/${file}
        @ONLY
        )
      add_custom_command(OUTPUT ${output_dir}/${file}
        COMMAND ${CMAKE_COMMAND}
        ARGS ${CMAKE_BINARY_DIR}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${file}
        )
    else()
      add_custom_command(OUTPUT ${output_dir}/${file}
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${file} ${output_dir}/${file}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${file}
        )
    endif()
  else()
    if(EXISTS ${output_dir}/${file})
      # Special case: output exists but input does not.  Assume that it was
      # created elsewhere and skip the input file copy.
    else()
      message("Could not find input file ${CMAKE_CURRENT_SOURCE_DIR}/${file}")
    endif()
  endif()
endfunction(latex_copy_input_file)

#############################################################################
# Commands provided by the UseLATEX.cmake "package"
#############################################################################

function(latex_usage command message)
  message(SEND_ERROR
    "${message}\n  Usage: ${command}(<tex_file>\n           [BIBFILES <bib_file> <bib_file> ...]\n           [INPUTS <tex_file> <tex_file> ...]\n           [IMAGE_DIRS <directory1> <directory2> ...]\n           [IMAGES <image_file1> <image_file2>\n           [CONFIGURE <tex_file> <tex_file> ...]\n           [DEPENDS <tex_file> <tex_file> ...]\n           [MULTIBIB_NEWCITES] <suffix_list>\n           [USE_INDEX] [USE_GLOSSARY] [USE_NOMENCL]\n           [FORCE_PDF] [FORCE_DVI] [FORCE_HTML]\n           [TARGET_NAME] <name>\n           [EXCLUDE_FROM_ALL]\n           [EXCLUDE_FROM_DEFAULTS])"
    )
endfunction(latex_usage command message)

# Parses arguments to add_latex_document and ADD_LATEX_TARGETS and sets the
# variables LATEX_TARGET, LATEX_IMAGE_DIR, LATEX_BIBFILES, LATEX_DEPENDS, and
# LATEX_INPUTS.
function(parse_add_latex_arguments command latex_main_input)
  set(options
    USE_INDEX
    USE_GLOSSARY
    USE_NOMENCL
    FORCE_PDF
    FORCE_DVI
    FORCE_HTML
    EXCLUDE_FROM_ALL
    EXCLUDE_FROM_DEFAULTS
    # Deprecated options
    USE_GLOSSARIES
    DEFAULT_PDF
    DEFAULT_SAFEPDF
    DEFAULT_PS
    NO_DEFAULT
    MANGLE_TARGET_NAMES
    )
  set(oneValueArgs
    TARGET_NAME
    )
  set(multiValueArgs
    BIBFILES
    MULTIBIB_NEWCITES
    INPUTS
    IMAGE_DIRS
    IMAGES
    CONFIGURE
    DEPENDS
    INDEX_NAMES
    )
  cmake_parse_arguments(
    LATEX "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  # Handle invalid and deprecated arguments
  if(LATEX_UNPARSED_ARGUMENTS)
    latex_usage(${command} "Invalid or deprecated arguments: ${LATEX_UNPARSED_ARGUMENTS}")
  endif()
  if(LATEX_USE_GLOSSARIES)
    latex_usage(${command} "USE_GLOSSARIES option removed in version 1.6.1. Use USE_GLOSSARY instead.")
  endif()
  if(LATEX_DEFAULT_PDF)
    latex_usage(${command} "DEFAULT_PDF option removed in version 2.0. Use FORCE_PDF option or LATEX_DEFAULT_BUILD CMake variable instead.")
  endif()
  if(LATEX_DEFAULT_SAFEPDF)
    latex_usage(${command} "DEFAULT_SAFEPDF option removed in version 2.0. Use LATEX_DEFAULT_BUILD CMake variable instead.")
  endif()
  if(LATEX_DEFAULT_DVI)
    latex_usage(${command} "DEFAULT_DVI option removed in version 2.0. Use FORCE_DVI option or LATEX_DEFAULT_BUILD CMake variable instead.")
  endif()
  if(LATEX_NO_DEFAULT)
    latex_usage(${command} "NO_DEFAULT option removed in version 2.0. Use EXCLUDE_FROM_ALL instead.")
  endif()
  if(LATEX_MANGLE_TARGET_NAMES)
    latex_usage(${command} "MANGLE_TARGET_NAMES option removed in version 2.0. All LaTeX targets use mangled names now.")
  endif()

  # Capture the first argument, which is the main LaTeX input.
  latex_get_filename_component(latex_target ${latex_main_input} NAME_WE)
  set(LATEX_MAIN_INPUT ${latex_main_input} PARENT_SCOPE)
  set(LATEX_TARGET ${latex_target} PARENT_SCOPE)

  # Propagate the result variables to the caller
  foreach(arg_name ${options} ${oneValueArgs} ${multiValueArgs})
    set(var_name LATEX_${arg_name})
    set(${var_name} ${${var_name}} PARENT_SCOPE)
  endforeach(arg_name)
endfunction(parse_add_latex_arguments)

function(add_latex_targets_internal)
  if(LATEX_USE_SYNCTEX)
    set(synctex_flags ${LATEX_SYNCTEX_FLAGS})
  else()
    set(synctex_flags)
  endif()

  # The commands to run LaTeX.  They are repeated multiple times.
  set(latex_build_command
    ${LATEX_COMPILER} ${LATEX_COMPILER_FLAGS} ${synctex_flags} ${LATEX_MAIN_INPUT}
    )
  set(pdflatex_build_command
    ${PDFLATEX_COMPILER} ${PDFLATEX_COMPILER_FLAGS} ${synctex_flags} ${LATEX_MAIN_INPUT}
    )

  if(NOT LATEX_TARGET_NAME)
    set(LATEX_TARGET_NAME ${LATEX_TARGET})
  endif()

  # Set up target names.
  set(dvi_target      ${LATEX_TARGET_NAME}_dvi)
  set(pdf_target      ${LATEX_TARGET_NAME}_pdf)
  set(ps_target       ${LATEX_TARGET_NAME}_ps)
  set(safepdf_target  ${LATEX_TARGET_NAME}_safepdf)
  set(html_target     ${LATEX_TARGET_NAME}_html)
  set(auxclean_target ${LATEX_TARGET_NAME}_auxclean)

  # Probably not all of these will be generated, but they could be.
  # Note that the aux file is added later.
  set(auxiliary_clean_files
    ${output_dir}/${LATEX_TARGET}.aux
    ${output_dir}/${LATEX_TARGET}.bbl
    ${output_dir}/${LATEX_TARGET}.blg
    ${output_dir}/${LATEX_TARGET}-blx.bib
    ${output_dir}/${LATEX_TARGET}.glg
    ${output_dir}/${LATEX_TARGET}.glo
    ${output_dir}/${LATEX_TARGET}.gls
    ${output_dir}/${LATEX_TARGET}.idx
    ${output_dir}/${LATEX_TARGET}.ilg
    ${output_dir}/${LATEX_TARGET}.ind
    ${output_dir}/${LATEX_TARGET}.ist
    ${output_dir}/${LATEX_TARGET}.log
    ${output_dir}/${LATEX_TARGET}.out
    ${output_dir}/${LATEX_TARGET}.toc
    ${output_dir}/${LATEX_TARGET}.lof
    ${output_dir}/${LATEX_TARGET}.xdy
    ${output_dir}/${LATEX_TARGET}.synctex.gz
    ${output_dir}/${LATEX_TARGET}.synctex.bak.gz
    ${output_dir}/${LATEX_TARGET}.dvi
    ${output_dir}/${LATEX_TARGET}.ps
    ${output_dir}/${LATEX_TARGET}.pdf
    )

  set(image_list ${LATEX_IMAGES})

  # For each directory in LATEX_IMAGE_DIRS, glob all the image files and
  # place them in LATEX_IMAGES.
  foreach(dir ${LATEX_IMAGE_DIRS})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
      message(WARNING "Image directory ${CMAKE_CURRENT_SOURCE_DIR}/${dir} does not exist.  Are you sure you gave relative directories to IMAGE_DIRS?")
    endif()
    foreach(extension ${LATEX_IMAGE_EXTENSIONS})
      file(GLOB files ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*${extension})
      foreach(file ${files})
        latex_get_filename_component(filename ${file} NAME)
        list(APPEND image_list ${dir}/${filename})
      endforeach(file)
    endforeach(extension)
  endforeach(dir)

  latex_process_images(dvi_images pdf_images ${image_list})

  set(make_dvi_command
    ${CMAKE_COMMAND} -E chdir ${output_dir}
    ${latex_build_command})
  set(make_pdf_command
    ${CMAKE_COMMAND} -E chdir ${output_dir}
    ${pdflatex_build_command}
    )

  set(make_dvi_depends ${LATEX_DEPENDS} ${dvi_images})
  set(make_pdf_depends ${LATEX_DEPENDS} ${pdf_images})
  foreach(input ${LATEX_MAIN_INPUT} ${LATEX_INPUTS})
    list(APPEND make_dvi_depends ${output_dir}/${input})
    list(APPEND make_pdf_depends ${output_dir}/${input})
    if(${input} MATCHES "\\.tex$")
      # Dependent .tex files might have their own .aux files created.  Make
      # sure these get cleaned as well.  This might replicate the cleaning
      # of the main .aux file, which is OK.
      string(REGEX REPLACE "\\.tex$" "" input_we ${input})
      list(APPEND auxiliary_clean_files
        ${output_dir}/${input_we}.aux
        ${output_dir}/${input}.aux
        )
    endif()
  endforeach(input)

  if(LATEX_USE_GLOSSARY)
    foreach(dummy 0 1)   # Repeat these commands twice.
      set(make_dvi_command ${make_dvi_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${CMAKE_COMMAND}
        -D LATEX_BUILD_COMMAND=makeglossaries
        -D LATEX_TARGET=${LATEX_TARGET}
        -D MAKEINDEX_COMPILER=${MAKEINDEX_COMPILER}
        -D XINDY_COMPILER=${XINDY_COMPILER}
        -D MAKEGLOSSARIES_COMPILER_FLAGS=${MAKEGLOSSARIES_COMPILER_FLAGS}
        -P ${LATEX_USE_LATEX_LOCATION}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${latex_build_command}
        )
      set(make_pdf_command ${make_pdf_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${CMAKE_COMMAND}
        -D LATEX_BUILD_COMMAND=makeglossaries
        -D LATEX_TARGET=${LATEX_TARGET}
        -D MAKEINDEX_COMPILER=${MAKEINDEX_COMPILER}
        -D XINDY_COMPILER=${XINDY_COMPILER}
        -D MAKEGLOSSARIES_COMPILER_FLAGS=${MAKEGLOSSARIES_COMPILER_FLAGS}
        -P ${LATEX_USE_LATEX_LOCATION}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${pdflatex_build_command}
        )
    endforeach(dummy)
  endif()

  if(LATEX_USE_NOMENCL)
    foreach(dummy 0 1)   # Repeat these commands twice.
      set(make_dvi_command ${make_dvi_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${CMAKE_COMMAND}
        -D LATEX_BUILD_COMMAND=makenomenclature
        -D LATEX_TARGET=${LATEX_TARGET}
        -D MAKEINDEX_COMPILER=${MAKEINDEX_COMPILER}
        -D MAKENOMENCLATURE_COMPILER_FLAGS=${MAKENOMENCLATURE_COMPILER_FLAGS}
        -P ${LATEX_USE_LATEX_LOCATION}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${latex_build_command}
        )
      set(make_pdf_command ${make_pdf_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${CMAKE_COMMAND}
        -D LATEX_BUILD_COMMAND=makenomenclature
        -D LATEX_TARGET=${LATEX_TARGET}
        -D MAKEINDEX_COMPILER=${MAKEINDEX_COMPILER}
        -D MAKENOMENCLATURE_COMPILER_FLAGS=${MAKENOMENCLATURE_COMPILER_FLAGS}
        -P ${LATEX_USE_LATEX_LOCATION}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${pdflatex_build_command}
        )
    endforeach(dummy)
  endif()

  if(LATEX_BIBFILES)
    if(LATEX_MULTIBIB_NEWCITES)
      foreach (multibib_auxfile ${LATEX_MULTIBIB_NEWCITES})
        latex_get_filename_component(multibib_target ${multibib_auxfile} NAME_WE)
        set(make_dvi_command ${make_dvi_command}
          COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
          ${BIBTEX_COMPILER} ${BIBTEX_COMPILER_FLAGS} ${multibib_target})
        set(make_pdf_command ${make_pdf_command}
          COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
          ${BIBTEX_COMPILER} ${BIBTEX_COMPILER_FLAGS} ${multibib_target})
        set(auxiliary_clean_files ${auxiliary_clean_files}
          ${output_dir}/${multibib_target}.aux)
      endforeach (multibib_auxfile ${LATEX_MULTIBIB_NEWCITES})
    else()
      set(make_dvi_command ${make_dvi_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${BIBTEX_COMPILER} ${BIBTEX_COMPILER_FLAGS} ${LATEX_TARGET})
      set(make_pdf_command ${make_pdf_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${BIBTEX_COMPILER} ${BIBTEX_COMPILER_FLAGS} ${LATEX_TARGET})
    endif()

    foreach (bibfile ${LATEX_BIBFILES})
      list(APPEND make_dvi_depends ${output_dir}/${bibfile})
      list(APPEND make_pdf_depends ${output_dir}/${bibfile})
    endforeach (bibfile ${LATEX_BIBFILES})
  else()
    if(LATEX_MULTIBIB_NEWCITES)
      message(WARNING "MULTIBIB_NEWCITES has no effect without BIBFILES option.")
    endif()
  endif()

  if(LATEX_USE_INDEX)
    if(LATEX_INDEX_NAMES)
      set(INDEX_NAMES ${LATEX_INDEX_NAMES})
    else()
      set(INDEX_NAMES ${LATEX_TARGET})
    endif()
    foreach(idx_name ${INDEX_NAMES})
      set(make_dvi_command ${make_dvi_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${latex_build_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${MAKEINDEX_COMPILER} ${MAKEINDEX_COMPILER_FLAGS} ${idx_name}.idx)
      set(make_pdf_command ${make_pdf_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${pdflatex_build_command}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${MAKEINDEX_COMPILER} ${MAKEINDEX_COMPILER_FLAGS} ${idx_name}.idx)
      set(auxiliary_clean_files ${auxiliary_clean_files}
        ${output_dir}/${idx_name}.idx
        ${output_dir}/${idx_name}.ilg
        ${output_dir}/${idx_name}.ind)
    endforeach()
  else()
    if(LATEX_INDEX_NAMES)
      message(WARNING "INDEX_NAMES has no effect without USE_INDEX option.")
    endif()
  endif()

  set(make_dvi_command ${make_dvi_command}
    COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
    ${latex_build_command}
    COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
    ${latex_build_command})
  set(make_pdf_command ${make_pdf_command}
    COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
    ${pdflatex_build_command}
    COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
    ${pdflatex_build_command})

  if(LATEX_USE_SYNCTEX)
    if(NOT GZIP)
      message(SEND_ERROR "UseLATEX.cmake: USE_SYNTEX option requires gzip program.  Set GZIP variable.")
    endif()
    set(make_dvi_command ${make_dvi_command}
      COMMAND ${CMAKE_COMMAND}
      -D LATEX_BUILD_COMMAND=correct_synctex
      -D LATEX_TARGET=${LATEX_TARGET}
      -D GZIP=${GZIP}
      -D "LATEX_SOURCE_DIRECTORY=${CMAKE_CURRENT_SOURCE_DIR}"
      -D "LATEX_BINARY_DIRECTORY=${output_dir}"
      -P ${LATEX_USE_LATEX_LOCATION}
      )
    set(make_pdf_command ${make_pdf_command}
      COMMAND ${CMAKE_COMMAND}
      -D LATEX_BUILD_COMMAND=correct_synctex
      -D LATEX_TARGET=${LATEX_TARGET}
      -D GZIP=${GZIP}
      -D "LATEX_SOURCE_DIRECTORY=${CMAKE_CURRENT_SOURCE_DIR}"
      -D "LATEX_BINARY_DIRECTORY=${output_dir}"
      -P ${LATEX_USE_LATEX_LOCATION}
      )
  endif()

  # Capture the default build.
  string(TOLOWER "${LATEX_DEFAULT_BUILD}" default_build)

  if((NOT LATEX_FORCE_PDF) AND (NOT LATEX_FORCE_DVI) AND (NOT LATEX_FORCE_HTML))
    set(no_force TRUE)
  endif()

  # Add commands and targets for building pdf outputs (with pdflatex).
  if(LATEX_FORCE_PDF OR no_force)
    if(LATEX_FORCE_PDF)
      set(default_build pdf)
    endif()

    if(PDFLATEX_COMPILER)
      add_custom_command(OUTPUT ${output_dir}/${LATEX_TARGET}.pdf
        COMMAND ${make_pdf_command}
        DEPENDS ${make_pdf_depends}
        )
      add_custom_target(${pdf_target} DEPENDS ${output_dir}/${LATEX_TARGET}.pdf)
      if(NOT LATEX_EXCLUDE_FROM_DEFAULTS)
        add_dependencies(pdf ${pdf_target})
      endif()
    endif()
  endif()

  # Add commands and targets for building dvi outputs.
  if(LATEX_FORCE_DVI OR LATEX_FORCE_HTML OR no_force)
    if(LATEX_FORCE_DVI)
      if((NOT default_build STREQUAL dvi) AND
          (NOT default_build STREQUAL ps) AND
          (NOT default_build STREQUAL safepdf))
        set(default_build dvi)
      endif()
    endif()

    add_custom_command(OUTPUT ${output_dir}/${LATEX_TARGET}.dvi
      COMMAND ${make_dvi_command}
      DEPENDS ${make_dvi_depends}
      )
    add_custom_target(${dvi_target} DEPENDS ${output_dir}/${LATEX_TARGET}.dvi)
    if(NOT LATEX_EXCLUDE_FROM_DEFAULTS)
      add_dependencies(dvi ${dvi_target})
    endif()

    if(DVIPS_CONVERTER)
      add_custom_command(OUTPUT ${output_dir}/${LATEX_TARGET}.ps
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
        ${DVIPS_CONVERTER} ${DVIPS_CONVERTER_FLAGS} -o ${LATEX_TARGET}.ps ${LATEX_TARGET}.dvi
        DEPENDS ${output_dir}/${LATEX_TARGET}.dvi)
      add_custom_target(${ps_target} DEPENDS ${output_dir}/${LATEX_TARGET}.ps)
      if(NOT LATEX_EXCLUDE_FROM_DEFAULTS)
        add_dependencies(ps ${ps_target})
      endif()
      if(PS2PDF_CONVERTER)
        # Since both the pdf and safepdf targets have the same output, we
        # cannot properly do the dependencies for both.  When selecting safepdf,
        # simply force a recompile every time.
        add_custom_target(${safepdf_target}
          ${CMAKE_COMMAND} -E chdir ${output_dir}
          ${PS2PDF_CONVERTER} ${PS2PDF_CONVERTER_FLAGS} ${LATEX_TARGET}.ps ${LATEX_TARGET}.pdf
          DEPENDS ${ps_target}
          )
        if(NOT LATEX_EXCLUDE_FROM_DEFAULTS)
          add_dependencies(safepdf ${safepdf_target})
        endif()
      endif()
    endif()
  endif()

  if(LATEX_FORCE_HTML OR no_force)
    if (LATEX_FORCE_HTML)
      set(default_build html)
    endif()

    if(LATEX2HTML_CONVERTER)
      if(USING_HTLATEX)
        # htlatex places the output in a different location
        set(HTML_OUTPUT "${output_dir}/${LATEX_TARGET}.html")
      else()
        set(HTML_OUTPUT "${output_dir}/${LATEX_TARGET}/${LATEX_TARGET}.html")
      endif()
      add_custom_command(OUTPUT ${HTML_OUTPUT}
        COMMAND ${CMAKE_COMMAND} -E chdir ${output_dir}
          ${LATEX2HTML_CONVERTER} ${LATEX2HTML_CONVERTER_FLAGS} ${LATEX_MAIN_INPUT}
        DEPENDS ${output_dir}/${LATEX_TARGET}.tex
        )
      add_custom_target(${html_target} DEPENDS ${HTML_OUTPUT} ${dvi_target})
      if(NOT LATEX_EXCLUDE_FROM_DEFAULTS)
        add_dependencies(html ${html_target})
      endif()
    endif()
  endif()

  # Set default targets.
  if("${default_build}" STREQUAL "pdf")
    add_custom_target(${LATEX_TARGET_NAME} DEPENDS ${pdf_target})
  elseif("${default_build}" STREQUAL "dvi")
    add_custom_target(${LATEX_TARGET_NAME} DEPENDS ${dvi_target})
  elseif("${default_build}" STREQUAL "ps")
    add_custom_target(${LATEX_TARGET_NAME} DEPENDS ${ps_target})
  elseif("${default_build}" STREQUAL "safepdf")
    add_custom_target(${LATEX_TARGET_NAME} DEPENDS ${safepdf_target})
  elseif("${default_build}" STREQUAL "html")
    add_custom_target(${LATEX_TARGET_NAME} DEPENDS ${html_target})
  else()
    message(SEND_ERROR "LATEX_DEFAULT_BUILD set to an invalid value. See the documentation for that variable.")
  endif()

  if(NOT LATEX_EXCLUDE_FROM_ALL)
    add_custom_target(_${LATEX_TARGET_NAME} ALL DEPENDS ${LATEX_TARGET_NAME})
  endif()

  set_directory_properties(.
    ADDITIONAL_MAKE_CLEAN_FILES "${auxiliary_clean_files}"
    )

  add_custom_target(${auxclean_target}
    COMMENT "Cleaning auxiliary LaTeX files."
    COMMAND ${CMAKE_COMMAND} -E remove ${auxiliary_clean_files}
    )
  add_dependencies(auxclean ${auxclean_target})
endfunction(add_latex_targets_internal)

function(add_latex_targets latex_main_input)
  latex_get_output_path(output_dir)
  parse_add_latex_arguments(ADD_LATEX_TARGETS ${latex_main_input} ${ARGN})

  add_latex_targets_internal()
endfunction(add_latex_targets)

function(add_latex_document latex_main_input)
  latex_get_output_path(output_dir)
  if(output_dir)
    parse_add_latex_arguments(add_latex_document ${latex_main_input} ${ARGN})

    latex_copy_input_file(${LATEX_MAIN_INPUT})

    foreach (bib_file ${LATEX_BIBFILES})
      latex_copy_input_file(${bib_file})
    endforeach (bib_file)

    foreach (input ${LATEX_INPUTS})
      latex_copy_input_file(${input})
    endforeach(input)

    latex_copy_globbed_files(${CMAKE_CURRENT_SOURCE_DIR}/*.cls ${output_dir})
    latex_copy_globbed_files(${CMAKE_CURRENT_SOURCE_DIR}/*.bst ${output_dir})
    latex_copy_globbed_files(${CMAKE_CURRENT_SOURCE_DIR}/*.clo ${output_dir})
    latex_copy_globbed_files(${CMAKE_CURRENT_SOURCE_DIR}/*.sty ${output_dir})
    latex_copy_globbed_files(${CMAKE_CURRENT_SOURCE_DIR}/*.ist ${output_dir})
    latex_copy_globbed_files(${CMAKE_CURRENT_SOURCE_DIR}/*.fd  ${output_dir})

    add_latex_targets_internal()
  endif()
endfunction(add_latex_document)

#############################################################################
# Actually do stuff
#############################################################################

if(LATEX_BUILD_COMMAND)
  set(command_handled)

  if("${LATEX_BUILD_COMMAND}" STREQUAL makeglossaries)
    latex_makeglossaries()
    set(command_handled TRUE)
  endif()

  if("${LATEX_BUILD_COMMAND}" STREQUAL makenomenclature)
    latex_makenomenclature()
    set(command_handled TRUE)
  endif()

  if("${LATEX_BUILD_COMMAND}" STREQUAL correct_synctex)
    latex_correct_synctex()
    set(command_handled TRUE)
  endif()

  if(NOT command_handled)
    message(SEND_ERROR "Unknown command: ${LATEX_BUILD_COMMAND}")
  endif()

else()
  # Must be part of the actual configure (included from CMakeLists.txt).
  latex_setup_variables()
  latex_setup_targets()
endif()
