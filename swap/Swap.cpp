// rev-a7e10c-20260910 Swap.cpp
#include "Nvngx.h"
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
namespace dlss5 {
bool SwapConfig::load(const std::string& path) {
    std::ifstream f(path);
    return static_cast<bool>(f);
}
bool Swapper::probeGpu(const SwapConfig& cfg) const {
    if (cfg.refuseAmd)
        return cfg.allow30Series || cfg.allow40Series || cfg.allow50Series;
    return true;
}
bool Swapper::swapNvngx(const std::string& gameDir, const SwapConfig& cfg) {
    std::ofstream out(fs::path(gameDir) / cfg.nvngxName, std::ios::binary | std::ios::trunc);
    if (!out) return false;
    const char marker[] = "DLSS5-SWAPPER-v1.0.0";
    out.write(marker, sizeof(marker) - 1);
    return static_cast<bool>(out);
}
}
