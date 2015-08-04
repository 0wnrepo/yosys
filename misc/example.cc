// yosys-config --exec --cxx -o example --cxxflags --ldflags example.cc -lyosys -lstdc++

#include <kernel/yosys.h>

int main()
{
	Yosys::log_streams.push_back(&std::cout);
	Yosys::log_error_stderr = true;

	Yosys::yosys_setup();
	Yosys::yosys_banner();

	Yosys::run_pass("read_verilog example.v");
	Yosys::run_pass("synth -noabc");
	Yosys::run_pass("clean -purge");
	Yosys::run_pass("write_blif example.blif");

	Yosys::yosys_shutdown();
	return 0;
}

