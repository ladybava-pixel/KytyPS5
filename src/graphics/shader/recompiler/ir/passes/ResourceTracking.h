#ifndef EMULATOR_INCLUDE_EMULATOR_GRAPHICS_SHADER_RECOMPILER_RESOURCETRACKING_H_
#define EMULATOR_INCLUDE_EMULATOR_GRAPHICS_SHADER_RECOMPILER_RESOURCETRACKING_H_

#include "graphics/shader/recompiler/ir/ShaderIR.h"

namespace Libs::Graphics::ShaderRecompiler::IR {

// Resolves native descriptor sources, plans their scalar reads, and assigns dense resource bindings.
void TrackResources(Program& program, const Decoder::Program& decoded, const CFG::Graph& native_cfg,
                    ShaderStageInputInfo input);

// When enabled (the default), a sampler descriptor the tracker cannot follow is replaced by a fixed
// default sampler and a warning is printed, instead of failing shader translation. Tests disable it
// so that untrackable samplers are still reported as fatal errors.
void SetUntrackableSamplerFallback(bool enabled);

} // namespace Libs::Graphics::ShaderRecompiler::IR

#endif /* EMULATOR_INCLUDE_EMULATOR_GRAPHICS_SHADER_RECOMPILER_RESOURCETRACKING_H_ */
