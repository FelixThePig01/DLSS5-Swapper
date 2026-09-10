// rev-a7e10c-20260910 main.cpp
#include "Nvngx.h"
#include <iostream>
int main(int argc, char** argv) {
    dlss5::Swapper swapper;
    dlss5::SwapConfig cfg;
    cfg.load("chip/Supported.json");
    std::cout << "DLSS 5 Swapper v1.0.0\n";
    if (!swapper.probeGpu(cfg)) return 1;
    const char* gameDir = (argc > 1) ? argv[1] : ".";
    if (!swapper.swapNvngx(gameDir, cfg)) return 2;
    return 0;
}
