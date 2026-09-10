// rev-a7e10c-20260910 Nvngx.h
#pragma once
#include <string>
namespace dlss5 {
struct SwapConfig {
    bool allow30Series = true;
    bool allow40Series = true;
    bool allow50Series = true;
    bool refuseAmd = true;
    std::string nvngxName = "nvngx_dlss.dll";
    bool load(const std::string& path);
};
class Swapper {
public:
    bool probeGpu(const SwapConfig& cfg) const;
    bool swapNvngx(const std::string& gameDir, const SwapConfig& cfg);
};
}
