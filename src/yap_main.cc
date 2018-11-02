#ifndef YAP_LOGGING_YAP_LOGGING_H_
#include "logging/yap_logging.h"
#endif

#include <string>
#include <libelf.h>
#include <err.h>

int main(int argc,char *argv[]) {

    if (elf_version(EV_CURRENT) == EV_NONE)
		   err(EX_SOFTWARE, "ELF library too old");

    if (argc < 2) {
        err(EX_SOFTWARE, "wrong usage: you must input a executable file");
    }

    std::string elf_file_name(argv[1]);
    if (yap::utils::elf::is_elf_file(elf_file_name) == false) {
        err(EX_SOFTWARE, "wrong usage: the input file is not elf format" );
    }

}
