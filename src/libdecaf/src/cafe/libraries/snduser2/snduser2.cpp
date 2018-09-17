#include "snduser2.h"
#include "snduser2_axfx_hooks.h"
#include "cafe/libraries/coreinit/coreinit_dynload.h"

namespace cafe::snduser2
{

static int32_t
rpl_entry(coreinit::OSDynLoad_ModuleHandle moduleHandle,
          coreinit::OSDynLoad_EntryReason reason)
{
   coreinit::internal::relocateHleLibrary(moduleHandle);
   internal::initialiseAxfxHooks();
   return 0;
}

void
Library::registerSymbols()
{
   RegisterEntryPoint(rpl_entry);

   registerAxfxSymbols();
   registerAxfxDelaySymbols();
   registerAxfxDelayExpSymbols();
   registerAxfxHooksSymbols();
   registerMixSymbols();
}

} // namespace cafe::snduser2
