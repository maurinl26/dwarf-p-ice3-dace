
cmake_minimum_required( VERSION 3.12 FATAL_ERROR)
find_package( ecbuild 3.4 REQUIRED HINTS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../ecbuild )

project( dwarf-p-ice3-dace VERSION 1.0 LANGUAGES Fortran C CXX)

ecbuild_enable_fortran( REQUIRED NO_MODULE_DIRECTORY )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


find_package(Python3 REQUIRED COMPONENTS Interpreter)

function(create_venv venv_dir requirements_path)

	if(EXISTS ${env_dir})
		message(STATUS "Virtual environment already exists in venv_dir")
		return()
	endif()

	if(NOT EXISTS ${requirements_path})
		message(FATAL_ERROR "Requirements file not found : ${requirements_path}")
	endif()
	
	execute_process(
		COMMAND ${Python3_EXECUTABLE} -m venv ${venv_dir}
		RESULT_VARIABLE venv_creation_ret_code
	)

	if(venv_creation_ret_code)
		message(FATAL_ERROR "Failed to create virtual environment at ${venv_dir}")
	endif()

	execute_process(
		COMMAND ${venv_dir}/bin/pip install -r ${requirements_path}
		RESULT_VARIABLE pip_install_ret_code
	)

	if(pip_install_ret_code)
		message(FATAL_ERROR "Failed to install dependencies from ${requirements_path}")
	endif()

	execute_process(
		COMMAND ${venv_dir}/bin/pip install -e ${CMAKE_CURRENT_SOURCE_DIR}
		RESULT_VARIABLE pip_e_install_ret_code
	)

	if(pip_e_install_ret_code)
		message(FATAL_ERROR "Failed to install ice3")
	endif()

	message(STATUS "Virtual environment setup done at ${venv_dir} with dependencies from ${requirements_path}")
endfunction()

function(dace_codegen venv_dir)
	message("Current source dir for code generation ${CMAKE_CURRENT_SOURCE_DIR}")
	message("Command : ${venv_dir}/bin/python3 ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/cli.py")

	message("Activate venv")
	execute_process(
		COMMAND source ${venv_dir}/bin/activate
		RESULT_VARIABLE venv_activate_ret_code
	)

	message("Execute process")
	execute_process(
		COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/cli.py
		RESULT_VARIABLE dace_codegen_ret_code
	)

	if(dace_codegen_ret_code)
		message(FATAL_ERROR "Failed to generate dace code")
	endif()
endfunction()


### Generate dacecache
set(DWARF_P_ICE3_VENV ${CMAKE_BINARY_DIR}/ice3_venv)

# Create venv with typer (cli) and dace (codegen)
message("Create venv")
create_venv(${DWARF_P_ICE3_VENV} ${CMAKE_CURRENT_SOURCE_DIR}/requirements.txt)

# Generate backend code
message("Generate DaCe code")
dace_codegen(${DWARF_P_ICE3_VENV})

### Sources
if(EXISTS .dacecache)
	add_subdirectory(.dacecache)
endif()

ecbuild_install_project( NAME dwarf-p-ice3-dace )

ecbuild_print_summary()
